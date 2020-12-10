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
void mutilNumber(int a[], int na, int b[], int nb, int mutil[], int &n, int modulo)
{
	int tmp, nhan, congdu=0, nhandu=0;
	for (int i = 0; i < na+nb+1; ++i)
		mutil[i] = 0;
	for (int i = 0; i < na; ++i)
	{
		for (int j = 0; j <nb; ++j)
		{
			nhan = a[i]*b[j]+nhandu;
			if(nhan >= modulo)
			{
				nhandu = nhan/modulo;
				nhan = nhan%modulo;
			}else{ nhandu = 0; }

			tmp = mutil[i+j] + nhan + congdu;
			if(tmp >= modulo)
			{
				congdu = tmp/modulo;
				tmp = tmp%modulo;
			}else{ congdu = 0; }
			mutil[i+j] = tmp;
		}
	}
	if (nhandu > 0)
	{
		mutil[na+nb-1] += nhandu;
	}
	n = na+nb;
	while(congdu > 0 )
	{
		tmp = mutil[n] + congdu;
		if(tmp >= modulo)
		{
			congdu = tmp/modulo;
			tmp = tmp%modulo;
		}else{ congdu = 0; }
		mutil[n-1] = tmp;
		n++;
	}
}
/**
 * Ham main
 */
int main() {
    int a=18, b=4, m=5; 
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
    mutilNumber(ma, na, mb, nb, ms, ns, m);
    printf("(%d*%d) mod %d= ", a,b,m);
    for (int i = ns-1; i >= 0; --i)
    {
    	printf("%d", ms[i]);
    	if ((i)%4==0 && i!=0 && i != ns-1)
    		printf(".");
    }
    printf("\n");
    return 1;
}