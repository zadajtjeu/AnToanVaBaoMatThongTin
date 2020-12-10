#include <bits/stdc++.h>

/* Exponential Squaring (Fast Modulo Multiplication)
x^n mod m
- n=0, x^n = 1
- n>0, x^n mod m =
	+ (x^k)^2 , n=2k
	+ (x^k)^2 * x, n=2k+1

*/
// Ex
long powerModulo(long x, long n, long m)// x^n mod m
{
	long p;
	if(n ==0 )
		return 1;
	p = powerModulo(x, n/2, m);
	if(n%2 == 0)
		return (p%m*p%m)%m;
	else
		return ((p%m*p%m)%m*x)%m;
}


//Loop
long exponentiation(long x, long n, long m) 
{ 
    long p = 1L; 
    while (n > 0)  
    { 
        if (n % 2 != 0) 
            p = (p * x) % m; 
        x = (x * x) % m; 
        n /= 2; 
    } 
    return p % m; 
} 

int main(int argc, char const *argv[])
{
	printf("%ld^%ld mod %ld = %ld\n", 37L, 27L, 101L, exponentiation(37,27,101) );
	return 0;
}