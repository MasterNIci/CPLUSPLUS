//  main.cpp
//  RSA
//
//  Created by Sergiy on 06.06.17.
//  Erkl�rt by Nicola B�hler 

#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>


bool isPrime(long int prime);
long int calculateE( long int t ); //Berechnen von E
long int greatestCommonDivisor( long int e, long int t );
long int calculateD( long int e, long int t );
long int encrypt( long int i, long int e, long int n );
long int decrypt(long int i, long int d, long int n );

int main( )
{
    long int p, q, n, t, e, d;
    
    long int encryptedText[100];
    memset(encryptedText, 0, sizeof(encryptedText));
    
    long int decryptedText[100];
    memset(decryptedText, 0, sizeof(decryptedText));
    
    bool flag;
    
    std::string msg;
    
    std::cout << "Welcome to RCA program" << std::endl << std::endl;
    
    // C??????? ????????? ? ?????????? ??????
    
    // 1. ?????????? ??? ????????? ????????? ??????? ????? p ? q ????????? ???????
    
    do
    {
        std::cout << "Enter a Prime number  p :" << std::endl;
        std::cin >> p;
        flag = isPrime( p );
        
        if ( flag == false )
        {
            std::cout << "\nWRONG INPUT (This number is not Prime. A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself)\n" << std::endl;
        }
    } while ( flag == false );
    
    
    do
    {
        std::cout << "Enter a Prime number  q :" << std::endl;
        std::cin >> q;
        flag = isPrime( q );
        
        if ( flag == false )
        {
            std::cout << "\nWRONG INPUT (This number is not Prime. A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself)\n" << std::endl;
        }
    } while ( flag == false);
    
    // 2. ??????????? ?? ???????????? n = p � q, ??????? ?????????? ???????.
    n = p * q;
    std::cout << "\nResult of computing n = p*q = " << n << std::endl;
    
    // 3. ??????????? ???????? ??????? ?????? ?? ????? n: f(n) = (p-1)�(q-1)
    t = ( p - 1 ) * ( q - 1 );
    std::cout << "Result of computing Euler's totient function:\t t = " << t << std::endl;
    
    // 4. ?????????? ????? ????? e ( 1 < e < f(n) ), ??????? ??????? ?? ????????? ??????? ?????? (t)
    //	  ????? e ?????????? ???????? ???????????
    e = calculateE( t );
    
    // 5. ??????????? ????? d, ???????????????? ???????? ? ????? e ?? ?????? f(n), ?? ???? ?????, ??????????????? ?????????:
    //    d � e = 1 (mod f(n))
    d = calculateD( e, t );
    
    // 6. ???? {e, n} ??????????? ? ???????? ????????? ????? RSA
    std::cout << "\nRSA public key is (n = " << n << ", e = " << e << ")" << std::endl;
    
    // 7. ???? {d, n} ?????? ???? ????????? ????? RSA ? ???????? ? ???????
    std::cout << "RSA private key is (n = " << n << ", d = " << d << ")" << std::endl;
    
    
    
    std::cout << "\nEnter Message to be encryped:" << std::endl;
    
    // there is a newline character left in the input stream, so we use ignore()
    std::cin.ignore();
    
    std::getline( std::cin, msg );
    
    std::cout << "\nThe message is: " << msg << std::endl;
    
    
    // encryption
    
    for (long int i = 0; i < msg.length(); i++)
    {
        encryptedText[i] = encrypt( msg[i], e, n);
    }
    
    std::cout << "\nTHE ENCRYPTED MESSAGE IS:" << std::endl;
    
    for ( long int i = 0; i < msg.length(); i++ )
    {
        printf( "%c", (char)encryptedText[i] );
    }
    
    
    //decryption
    
    for (long int i = 0; i < msg.length(); i++)
    {
        decryptedText[i] = decrypt(encryptedText[i], d, n);
    }
    
    std::cout << "\n\nTHE DECRYPTED MESSAGE IS:" << std::endl;
    
    for (long int i = 0; i < msg.length(); i++)
    {
        printf( "%c", (char)decryptedText[i] );
    }
    
    
    std::cout << std::endl << std::endl;
    
    //system("PAUSE");
    
    return 0;
}

bool isPrime( long int prime)
{
    long int i, j;
    
    j = (long int)sqrt((long double)prime);
    
    for ( i = 2; i <= j; i++)
    {
        if ( prime % i == 0 )
        {
            return false;
        }
    }
    
    return true;
}

long int calculateE( long int t )
{
    // ?????????? ????? ????? e ( 1 < e < t ) // ??????? ??????? ?? ????????? ??????? ?????? (t)
    
    long int e;
    
    for ( e = 2; e < t; e++ )
    {
        if (greatestCommonDivisor( e, t ) == 1 )
        {
            return e;
        }
    }
    
    return -1;
}

long int greatestCommonDivisor( long int e, long int t )
{
    while ( e > 0 )
    {
        long int myTemp;
        
        myTemp = e;
        e = t % e;
        t = myTemp;
    }
    
    return t;
}

long int calculateD( long int e, long int t)
{
    // ??????????? ????? d, ???????????????? ???????? ? ????? e ?? ?????? f(n), ?? ???? ?????, ??????????????? ?????????:
    //    d � e = 1 (mod f(n))
    
    long int d;
    long int k = 1;
    
    while ( 1 )
    {
        k = k + t;
        
        if ( k % e == 0)
        {
            d = (k / e);
            return d;
        }
    }
    
}


long int encrypt( long int i, long int e, long int n )
{
    long int current, result;
    
    current = i - 97;
    result = 1;
    
    for ( long int j = 0; j < e; j++ )
    {
        result = result * current;
        result = result % n;
    }
    
    return result;
}

long int decrypt(long int i, long int d, long int n)
{
    long int current, result;
    
    current = i;
    result = 1;
    
    for ( long int j = 0; j < d; j++ )
    {
        result = result * current;
        result = result % n;
    }
    
    return result + 97;
}
