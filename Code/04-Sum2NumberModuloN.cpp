#include <bits/stdc++.h>

void convert(int a, int n, int &count, int repre[]) {
    int i=0;
    while(a>0)
    {
        repre[i] = a%n;
        //printf("%d\n", a%n);
        a = a/n;
        i++;
    }
    count = i;
}
void sumNumber(int a[], int na, int b[], int nb, int sum[], int &ns, int modulo)
{
	int du = 0, tmp = 0;
	for (int i=0, j=0; i < na || j < nb; ++i, ++j)
	{
		if (i<na && j<nb)
		{
			tmp = a[i] + b[j]+ du;
			if(tmp >= modulo){
				du = tmp/modulo;
				tmp = tmp%modulo;
			}
			else du = 0;
			sum[i] = tmp;
		}
		else if(i<na && j>=nb)
		{
			tmp = a[i] + du;
			if(tmp >= modulo){
				du = tmp/modulo;
				tmp = tmp%modulo;
			}
			else du = 0;
			sum[i] = tmp;
		}
		else if(i>=na && j<nb)
		{
			tmp = b[j] + du;
			if(tmp >= modulo){
				du = tmp/modulo;
				tmp = tmp%modulo;
			}
			else du = 0;
			sum[j] = tmp;
		}
	}
	ns = na>nb?na:nb;
	if(du > 0)
	{
		++ns;
		sum[ns-1] = du;
	}
	

}
/**
 * Ham main
 */
int main() {
    int a=13, b=3, m=2; // (13+3) theo mod 2 = 1101 + 11 = 10000 (13+3=16)
    int ma[100], mb[100], ms[100], na=0, nb=0, ns=0;
    //Convert a 
    convert(a, m, na, ma);
    printf("%d(10) = ", a);
    for (int i = na-1; i >= 0; --i)
    {
    	printf("%d", ma[i]);
    }
    printf("(%d)\n",m);
    //Convert b 
    convert(b, m, nb, mb);
    printf("%d(10) = ", b);
    for (int i = nb-1; i >= 0; --i)
    {
    	printf("%d", mb[i]);
    }
    printf("(%d)\n",m);
    //SUM a+b
    sumNumber(ma, na, mb, nb, ms, ns, m);
    printf("(%d+%d) mod %d= ", a,b,m);
    for (int i = ns-1; i >= 0; --i)
    {
    	printf("%d", ms[i]);
    }
    printf("\n");
    return 1;
}