#include <bits/stdc++.h> 

/* GCD Euclide(a,b)
- a = 0 => GCD(a,b) = b
- b = 0 => GCD(a,b) = a
- a = b*q + r => GCD(a,b) = GCD(b,r) or GCD(a,b) = GCD(b, a mod b)
*/

//Recursion
long GCD_Re(long a, long b)
{
	if (a<b)
	{
		return GCD_Re(b,a);
	}
	else
	{
		if(b == 0)
			return a;
		else
			return GCD_Re(b, a%b);
	}
}

//Loop
long GCD_Loop(long a, long b)
{
	if (a<b)
	{
		return GCD_Loop(b,a);
	}
	else
	{
		while(b > 0)
		{
			long r = a%b;
			a = b;
			b = r;
		}
		return a;
	}
}

int main(int argc, char const *argv[])
{
	long a = 4864, b = 3458;
	printf("GCD_Re(%ld,%ld) = %ld\n", a, b, GCD_Re(a,b));
	printf("GCD_Loop(%ld,%ld) = %ld\n", a, b, GCD_Loop(a,b));
	return 0;
}