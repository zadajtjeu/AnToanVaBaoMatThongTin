#include <bits/stdc++.h>

/* Hill cipher
P = C = (Zn)^m
K la ma tran vuong m*m kha nghich
ek(x) = x*k
dk(y) = y*k^-1
EX: m=2, Z26, K = (3 3|2 5)
P = HELP, C = DPLE
*/

void printMatrix(int matrix[][50], int m)
{
	printf("\n");
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
			printf(" %5d ", matrix[i][j]);
		printf("\n");
	}
}

void tich2matran(int vecto[], int key[][50], int m, int re[])
{
	for (int i = 0; i < m; ++i)
	{
		int s=0;
		for (int j = 0; j < m; ++j)
			s += vecto[j]*key[j][i];
		re[i] = s%26;
	}
}

char *encryptHill(char *plaintext, int key[][50], int m)
{
    int length = strlen(plaintext);
    char* cipher = (char*)malloc(sizeof(char)*(length-1));
    for(int i=0; i < length; i+=m){
    	int ci[50], vecto[50];

    	for (int j = 0; j < m; ++j)
	    	vecto[j] = plaintext[i+j]-65;
	    tich2matran(vecto, key, m, ci);

	    for (int j = 0; j < m; ++j)
		    cipher[i+j] = ci[j]+65;
    }
    cipher[length] = '\0';
    return cipher;
}


//Giai ma K co m=2
int nghichdaoModulo(int a, int n) //a^-1 mod n
{
	/* Thuat toan Euclide mo rong
	cho 2 so r0 va r1, tim r1^-1 mod r0
	VD r0 = 29, r1 = 8, tim 8^-1 mod 29
	s*r0 + t*r1 = gcd(r0,r1)
	s0 =1
	s1=0
	si = s(i-2) - q(i-1)*s(i-1)
	t0 = 0
	t1 = 1
	ti = t(i-2) - q(i-1)*t(i-1)
	*/
	
	int r, q, y, y0=0, y1=1, m=n;
	while(a > 0)
	{
		r = m%a;
		if(r == 0)
			break;
		q = m/a;
		y = y0-y1*q;
		m=a;
		a=r;
		y0=y1;
		y1=y;
	}
	if(a>1)
		return -1;
	else if(y>0)
		return y;
	else
		return y+n;
}

//tim ma tran khoa K^-1
void timKgiaima(int key[][50], int keyND[][50], int m)
{
	//cong thuc chi ap dung cho m=2
	int det = key[0][0]*key[1][1] - key[0][1]*key[1][0];
	int detnd = nghichdaoModulo(det,26);

	keyND[0][0] = (detnd*key[1][1])%26;
	keyND[1][1] = (detnd*key[0][0])%26;
	keyND[0][1] = (detnd*-key[0][1])%26;
	keyND[1][0] = (detnd*-key[1][0])%26;
	if(keyND[0][1] < 0)
		keyND[0][1] += 26;
	if(keyND[1][0] < 0)
		keyND[1][0] += 26;
}


char *decryptHill(char *ciphertext, int key[][50], int m)
{
    int length = strlen(ciphertext);
    char* plain = (char*)malloc(sizeof(char)*(length-1));

    int keyND[50][50];
    timKgiaima(key, keyND, m);

    for(int i=0; i < length; i+=m)
    {
    	int pi[50], vecto[50];

    	for (int j = 0; j < m; ++j)
	    	vecto[j] = ciphertext[i+j]-65;
	    tich2matran(vecto, keyND, m, pi);

	    for (int j = 0; j < m; ++j)
		    plain[i+j] = pi[j]+65;
    }
        
    plain[length] = '\0';
    return plain;
}

int main()
{
    char plain[100] = "HELP";
    char cipher[100] = "DPLE";
    int key[50][50] = {{3,3},{2,5}};
    int m = 2;
    printf("Encrypt: %s => %s", plain,encryptHill(plain, key, m));
    printf("\nDecrypt: %s <= %s\n\n", cipher,decryptHill(cipher, key, m));

    return 0;
}