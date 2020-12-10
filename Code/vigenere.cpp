#include <bits/stdc++.h>

/* Vigenere
P = C = K = (Zn)^m
ek(x1,x2,...,xm) = {(x1+k1) mod n,..., (xm+km) mod n}
dk(y1,y2,...,ym) = {(y1-k1) mod n,..., (xm-km) mod n}
Ex:
m = 6, n = 26
K = CIPHER
X = THISCRYPTOSYSTEMISNOTSECURE
Y = VPXZGIAXIVWPUBTTMJPWIZITWZT

*/

char *encryptVigenere(char *plaintext, char *key)
{
    int length = strlen(plaintext);
    char* cipher = (char*)malloc(sizeof(char)*(length-1));
    //key length
    int lenK = strlen(key);

    for(int i=0; i < length;){
    	for(int j=0; j<lenK; j++,i++){
        	cipher[i] = 65 + (plaintext[i]-65 + key[j]-65)%26;
    	}
    }
    cipher[length] = '\0';
    return cipher;
}

char *decryptVigenere(char *ciphertext, char *key)
{
    int length = strlen(ciphertext);
    char* plain = (char*)malloc(sizeof(char)*(length-1));
    //key length
    int lenK = strlen(key);
    for(int i=0; i < length;){
    	for (int j = 0; j < lenK; j++, i++)
    	{
    		if(ciphertext[i] > key[j])
    			plain[i] = 65 + (ciphertext[i] - key[j])%26;
    		else
    			plain[i] = 65 + 26 + (ciphertext[i] - key[j])%26;
    	}
    }
    plain[length] = '\0';
    return plain;
}

int main(int argc, char const *argv[])
{
    char plain[100] = "THISCRYPTOSYSTEMISNOTSECURE";
    char cipher[100] = "VPXZGIAXIVWPUBTTMJPWIZITWZT";
    char key[100] = "CIPHER";
    printf("Encrypt: %s => %s", plain,encryptVigenere(plain, key));
    printf("\nDecrypt: %s <= %s\n\n", cipher,decryptVigenere(cipher, key));

    char xaumh[100], xaugm[100], k[100];
    printf("Nhap ban ro: ");
    fflush(stdin);
    gets(xaumh);
    printf("Nhap key: ");
    gets(k);
    printf("Encrypt: %s => %s", xaumh,encryptVigenere(xaumh, k));
    printf("\n\nNhap ban ma: ");
    gets(xaugm);
    printf("Nhap key: ");
    gets(k);
    printf("Decrypt: %s => %s", xaugm,decryptVigenere(xaugm, k));
    getchar();
	return 0;
}