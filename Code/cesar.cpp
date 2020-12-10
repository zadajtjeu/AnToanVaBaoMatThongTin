#include <bits/stdc++.h>
#include <string.h>
/* Cesar
P = C = K = Zn
ek(x) = (x+k) mod n
dk(y) = (y-k) mod n
Ex:
plaintext: ATTACK
key: 17
ciphertext: RKKRTB
*/
char *encryptCesar(char *plaintext, int key)
{
    int length = strlen(plaintext);
    char* cipher = (char*)malloc(sizeof(char)*(length-1));
    for(int i=0; i < length; i++)
        cipher[i] = 65 + (plaintext[i] + key -65)%26;
    cipher[length] = '\0';
    return cipher;
}
char *decryptCesar(char *ciphertext, int key)
{
    int length = strlen(ciphertext);
    char* plain = (char*)malloc(sizeof(char)*(length-1));
    for(int i=0; i < length; i++)
        plain[i] = 65 + (ciphertext[i] - key - 65 + 26)%26;
    plain[length] = '\0';
    return plain;
}

int main()
{
    char plain[100] = "ATTACK";
    char cipher[100] = "RKKRTB";
    printf("Encrypt: %s => %s", plain,encryptCesar(plain, 17));
    printf("\nDecrypt: %s <= %s\n\n", cipher,decryptCesar(cipher, 17));
    
    
    char xaumh[100], xaugm[100]; int k;
    printf("Nhap ban ro: ");
    fflush(stdin);
    gets(xaumh);
    printf("Nhap key: ");
    fflush(stdin);
    scanf("%d", &k);
    printf("Encrypt: %s => %s", xaumh,encryptCesar(xaumh, k));
    printf("\n\nNhap ban ma: ");
    fflush(stdin);
    gets(xaugm);
    printf("Nhap key: ");
    fflush(stdin);
    scanf("%d", &k);
    printf("Decrypt: %s => %s", xaumh,decryptCesar(xaugm, k));
    getchar();
    return 0;
}
