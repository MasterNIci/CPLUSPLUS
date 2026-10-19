//  main.cpp
//  RSA
//
//  Created by Sergiy on 06.06.17.
//  Erklärt by Nicola Bühler
//
//  Überarbeitet: schnelle Potenz und erweiterter Euklid und Eingabeprüfung.
//  Lernbeispiel ohne Padding. NICHT für echte Daten verwenden.
//  Jedes Byte wird einzeln verschlüsselt. Das ist nur eine Substitutionschiffre.
//  Echtes RSA verschlüsselt nie Text direkt. Es schützt einen Schlüssel und nutzt Padding (OAEP).

#include <cstddef>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

typedef unsigned long long u64;

// Obere Grenze für n. Dann passt jedes Produkt a * b mit a und b unter n in 64 Bit.
const u64 N_MAX = 0xFFFFFFFFULL;   // 2 hoch 32 minus 1

// Untere Grenze für n. Jedes Byte (0 bis 255) muss kleiner als n sein.
const u64 N_MIN = 256;

bool isPrime( u64 prime );
u64 greatestCommonDivisor( u64 a, u64 b );
u64 calculateE( u64 t );                          // Berechnen von E
u64 calculateD( u64 e, u64 t );                   // Berechnen von D
u64 modPow( u64 base, u64 exponent, u64 n );      // schnelle Potenz
u64 encrypt( u64 m, u64 e, u64 n );
u64 decrypt( u64 c, u64 d, u64 n );
bool readNumber( const char* prompt, u64& value );
bool readPrime( const char* prompt, u64 notThis, u64& prime );

int main( )
{
    u64 p = 0, q = 0, n = 0, t = 0, e = 0, d = 0;

    std::cout << "Welcome to RSA program" << std::endl;
    std::cout << "(Toy example without padding. Do NOT use it for real data.)" << std::endl << std::endl;

    // Schritte 1 bis 5: Schlüsselpaar erzeugen.
    // Passen die Zahlen nicht dann wird neu gefragt.
    for ( ;; )
    {
        // 1. Zwei verschiedene Primzahlen p und q wählen. Beide bleiben geheim.
        if ( !readPrime( "Enter a Prime number  p :", 0, p ) ) return 1;
        if ( !readPrime( "Enter a Prime number  q :", p, q ) ) return 1;

        // 2. Modul n = p * q berechnen. Es steckt in beiden Schlüsseln.
        n = p * q;

        if ( n < N_MIN || n > N_MAX )
        {
            std::cout << "\nWRONG INPUT (n = p*q must be between " << N_MIN << " and " << N_MAX << ")\n" << std::endl;
            continue;
        }

        // 3. Eulersche Phi Funktion von n: t = (p minus 1) mal (q minus 1)
        t = ( p - 1 ) * ( q - 1 );

        // 4. Öffentlichen Exponenten e wählen: 1 < e < t und teilerfremd zu t
        e = calculateE( t );

        if ( e == 0 )
        {
            std::cout << "\nNo usable e for these primes. Please choose other primes.\n" << std::endl;
            continue;
        }

        // 5. Privaten Exponenten d berechnen: d * e = 1 (mod t)
        d = calculateD( e, t );

        break;
    }

    std::cout << "\nResult of computing n = p*q = " << n << std::endl;
    std::cout << "Result of computing Euler's totient function:\t t = " << t << std::endl;

    // 6. Das Paar {e, n} ist der öffentliche Schlüssel.
    std::cout << "\nRSA public key is (n = " << n << ", e = " << e << ")" << std::endl;

    // 7. Das Paar {d, n} ist der private Schlüssel. Er bleibt geheim.
    std::cout << "RSA private key is (n = " << n << ", d = " << d << ")" << std::endl;

    // Probe: d * e muss bei Division durch t den Rest 1 lassen.
    std::cout << "Check: (d * e) mod t = " << ( d * e ) % t << std::endl;

    std::cout << "\nEnter Message to be encrypted:" << std::endl;

    // readNumber hat den Rest der letzten Zeile schon verworfen. Darum liest getline hier sofort die Nachricht.
    std::string msg;
    std::getline( std::cin, msg );

    if ( msg.empty() )
    {
        std::cout << "\nNo message entered. Nothing to do." << std::endl;
        return 0;
    }

    std::cout << "\nThe message is: " << msg << std::endl;

    // Verschlüsseln: Jedes Byte ist eine Zahl von 0 bis 255 und wird direkt verwendet.
    // Das gilt für alle Zeichen und nicht nur für a bis z. Der Vektor wächst mit der Nachricht.
    std::vector<u64> encryptedText( msg.size() );

    for ( std::size_t i = 0; i < msg.size(); i++ )
    {
        encryptedText[i] = encrypt( (unsigned char)msg[i], e, n );
    }

    // Der Chiffretext besteht aus Zahlen bis n. Als einzelnes char gingen Werte verloren.
    std::cout << "\nTHE ENCRYPTED MESSAGE IS (numbers):" << std::endl;

    for ( std::size_t i = 0; i < encryptedText.size(); i++ )
    {
        std::cout << encryptedText[i] << ' ';
    }

    std::cout << std::endl;

    // Entschlüsseln
    std::string decryptedText;

    for ( std::size_t i = 0; i < encryptedText.size(); i++ )
    {
        decryptedText += (char)(unsigned char)decrypt( encryptedText[i], d, n );
    }

    std::cout << "\nTHE DECRYPTED MESSAGE IS:" << std::endl;
    std::cout << decryptedText << std::endl;

    std::cout << ( decryptedText == msg ? "\nRound trip OK" : "\nRound trip FAILED" ) << std::endl << std::endl;

    return 0;
}

bool isPrime( u64 prime )
{
    // Probedivision. 0 und 1 sind keine Primzahlen.
    if ( prime < 2 ) return false;
    if ( prime % 2 == 0 ) return prime == 2;

    // i <= prime / i bedeutet i * i <= prime. Es braucht weder sqrt noch gibt es einen Überlauf.
    for ( u64 i = 3; i <= prime / i; i += 2 )
    {
        if ( prime % i == 0 )
        {
            return false;
        }
    }

    return true;
}

u64 greatestCommonDivisor( u64 a, u64 b )
{
    // Euklidischer Algorithmus
    while ( b != 0 )
    {
        u64 rest = a % b;

        a = b;
        b = rest;
    }

    return a;
}

u64 calculateE( u64 t )
{
    // Gesucht ist e mit 1 < e < t und ggT von e und t gleich 1.
    // Üblich ist 65537. Bei kleinen t nehmen wir den ersten passenden Wert der Liste.
    // Ein e mit e * e = 1 (mod t) wird übersprungen. Sonst wäre d gleich e.
    // Dann wäre der private Schlüssel gleich dem öffentlichen.
    const u64 candidates[] = { 65537, 257, 17, 5, 3 };

    for ( std::size_t i = 0; i < sizeof( candidates ) / sizeof( candidates[0] ); i++ )
    {
        u64 e = candidates[i];

        if ( e < t && greatestCommonDivisor( e, t ) == 1 && ( e * e ) % t != 1 )
        {
            return e;
        }
    }

    // Reserve: der kleinste ungerade Wert ab 3 der passt
    for ( u64 e = 3; e < t; e += 2 )
    {
        if ( greatestCommonDivisor( e, t ) == 1 && ( e * e ) % t != 1 )
        {
            return e;
        }
    }

    return 0;   // kein passendes e gefunden
}

u64 calculateD( u64 e, u64 t )
{
    // Erweiterter euklidischer Algorithmus. Er findet d mit d * e = 1 (mod t).
    // oldS und s sind die Faktoren von e. Sie laufen mit dem Rest mit.
    long long oldR = (long long)e;
    long long r = (long long)t;
    long long oldS = 1;
    long long s = 0;

    while ( r != 0 )
    {
        long long quotient = oldR / r;
        long long next;

        next = oldR - quotient * r;
        oldR = r;
        r = next;

        next = oldS - quotient * s;
        oldS = s;
        s = next;
    }

    // oldR ist jetzt der ggT von e und t. Er muss 1 sein.
    if ( oldR != 1 )
    {
        return 0;
    }

    // oldS * e = 1 (mod t). Ein negativer Wert wird um t nach oben geschoben.
    if ( oldS < 0 )
    {
        oldS += (long long)t;
    }

    return (u64)oldS;
}

u64 modPow( u64 base, u64 exponent, u64 n )
{
    // Schnelle Potenz (Square and Multiply). Sie braucht nur etwa log2 vom Exponenten viele Schritte.
    // Alle Zwischenwerte bleiben unter n. Wegen n unter 2 hoch 32 passt jedes Produkt in 64 Bit.
    u64 result = 1;

    base = base % n;

    while ( exponent > 0 )
    {
        if ( exponent & 1 )
        {
            result = ( result * base ) % n;
        }

        base = ( base * base ) % n;
        exponent = exponent >> 1;
    }

    return result;
}

u64 encrypt( u64 m, u64 e, u64 n )
{
    // c = m hoch e mod n
    return modPow( m, e, n );
}

u64 decrypt( u64 c, u64 d, u64 n )
{
    // m = c hoch d mod n
    return modPow( c, d, n );
}

// Liest eine ganze Zahl ab 0. Falsche Eingaben werden abgefangen und neu abgefragt.
// Rückgabe false nur wenn die Eingabe zu Ende ist.
bool readNumber( const char* prompt, u64& value )
{
    for ( ;; )
    {
        std::cout << prompt << std::endl;

        long long input = 0;

        if ( std::cin >> input )
        {
            // Rest der Zeile verwerfen. Danach passt der nächste Lesevorgang.
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

            if ( input >= 0 )
            {
                value = (u64)input;
                return true;
            }
        }
        else
        {
            if ( std::cin.eof() )
            {
                std::cout << "\nInput ended." << std::endl;
                return false;
            }

            // Kein Zahlenformat. Fehlerzustand löschen und die Zeile verwerfen.
            std::cin.clear();
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
        }

        std::cout << "\nWRONG INPUT (Please enter a whole number that is not negative)\n" << std::endl;
    }
}

// Liest eine Primzahl. Sie darf nicht gleich notThis sein und muss unter 2 hoch 32 liegen.
bool readPrime( const char* prompt, u64 notThis, u64& prime )
{
    for ( ;; )
    {
        if ( !readNumber( prompt, prime ) )
        {
            return false;
        }

        // Erst die Grösse prüfen. Sonst würde die Probedivision bei riesigen Zahlen ewig laufen.
        if ( prime > N_MAX )
        {
            std::cout << "\nWRONG INPUT (This number is too big. Please stay below " << N_MAX + 1 << ")\n" << std::endl;
        }
        else if ( !isPrime( prime ) )
        {
            std::cout << "\nWRONG INPUT (This number is not Prime. A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself)\n" << std::endl;
        }
        else if ( prime == notThis )
        {
            std::cout << "\nWRONG INPUT (p and q must be different)\n" << std::endl;
        }
        else
        {
            return true;
        }
    }
}
