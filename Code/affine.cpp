#include <bits/stdc++.h>
#include <string.h>
/* Affine
P = C = Zn
K = {(a,b) thuoc Zn x Zn : gcd(a,n) = 1}
ek(x) = (ax+b) mod n
dk(y) = (a^-1 (y-b)) mod n
Ex:
plaintext: ATTACK
key: (5,3)
ciphertext: DUUDNB
*/

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
	
	int r, q, y, y0=0, y1=1, tga=a, m=n;
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

char *encryptAffine(char *plaintext, int key[2])
{
    int length = strlen(plaintext);
    char* cipher = (char*)malloc(sizeof(char)*(length-1));
    for(int i=0; i < length; i++)
        cipher[i] = 65 + (key[0] * (plaintext[i]-65) + key[1])%26;
    cipher[length] = '\0';
    return cipher;
}

char *decryptAffine(char *ciphertext, int key[2])
{
    int length = strlen(ciphertext);
    char* plain = (char*)malloc(sizeof(char)*(length-1));
    int nda = nghichdaoModulo(key[0],26); // a^-1 mod 26

    for(int i=0; i < length; i++)
    {
    	int tg = (nda*(ciphertext[i]-key[1]-65))%26;
    	if(tg<0)
    		tg+=26;
    	plain[i] = 65 + tg;
    }
        
    plain[length] = '\0';
    return plain;
}

int main()
{
    char plain[100] = "ATTACK";
    char cipher[100] = "DUUDNB";
    int key[2] = {5,3};
    printf("Encrypt: %s => %s", plain,encryptAffine(plain, key));
    printf("\nDecrypt: %s <= %s\n\n", cipher,decryptAffine(cipher, key));
    
    char xaumh[100], xaugm[100]; int k[2];
    printf("Nhap ban ro: ");
    fflush(stdin);
    gets(xaumh);
    printf("Nhap key: ");
    fflush(stdin);
    for(int i=0; i<2; i++)
    	scanf("%d", &k[i]);
    printf("Encrypt: %s => %s", xaumh,encryptAffine(xaumh, k));
    printf("\n\nNhap ban ma: ");
    fflush(stdin);
    gets(xaugm);
    printf("Nhap key: ");
    fflush(stdin);
    for(int i=0; i<2; i++)
    	scanf("%d", &k[i]);
    printf("Decrypt: %s => %s", xaumh,decryptAffine(xaugm, k));
    getchar();
    return 0;
}
