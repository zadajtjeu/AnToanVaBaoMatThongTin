#include <bits/stdc++.h>

/* Extended Euclidean algorithm for computing multiplicative inverses in modular structures
*/
long ModuloInverse(long a, long n) // a^-1 mod n
{
	long r, q, t, t0 = 0, t1 = 1;

	while(a > 0)
	{
		r = n % a;
		q = n/a;
		if(r == 0)
			break;
		t = t0 - t1*q;
		n = a;
		a = r;
		t0 = t1;
		t1 = t;
	}

	if(a > 1)
		return -1; // GCD(a,n) # 1
	if(t>0)
		return t; //a^-1 mod n = t mod n
	else
		return t+n; //a^-1 mod n = -t mod n = t+n mod n
}

int main(int argc, char const *argv[])
{
	printf("%ld^-1 mod %ld = %ld\n", (long)8, (long)29, ModuloInverse(8,29));
	return 0;
}