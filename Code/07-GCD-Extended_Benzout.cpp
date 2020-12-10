#include <bits/stdc++.h>

/* Extended Euclidean algorithm
Input: 0 < b < a
Output: d = GCD(a,b), x&y: ax + by=d

1. If b=0 Then d=a, x=1, y=0; return(d,x,y);
2. x2=1, x1=0, y2=0, y1=1;
3. while b>0 do
	3.1. q=a/b, r=a-q*b, x=x2-q*x1, y=y2-q*y1
	3.2. a=b, b=r, x2=x1, x1=x, y2=y1, y1=y
4. d=a, x=x2, y=y2 return d,x,y
*/

long extended_gcd_benzout(long a, long b)
{
	long A=a, B=b;
	long d, q, r, x, x1, x2, y, y1, y2;

	if(b == 0)
	{
		d = a; x = 1; y = 0;
	}
	else
	{
		x2 = 1; x1 = 0; y2 = 0; y1 = 1;
		while(b>0)
		{
			q=a/b; r=a-q*b; x=x2-q*x1; y=y2-q*y1;
			a=b; b=r; x2=x1; x1=x; y2=y1; y1=y;
		}

		d = a; x = x2; y = y2;
	}
	printf("a=%ld b=%ld d=%ld x=%ld y=%ld\n",A,B,d,x,y);
	return d;
}

int main(int argc, char const *argv[])
{
	long a = 4864, b=3458;
	printf("\nextended_gcd(%ld,%ld) = %ld\n", a,b,extended_gcd_benzout(a,b));
	return 0;
}


/* Code geeksforgeeks
// C function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
  
// Driver Program 
int main() 
{ 
    int x, y; 
    int a = 35, b = 15; 
    int g = gcdExtended(a, b, &x, &y); 
    printf("gcd(%d, %d) = %d", a, b, g); 
    return 0; 
} 
*/