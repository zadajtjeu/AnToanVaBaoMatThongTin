/**
 * Chuong trinh chuyen doi he co so trong C
 */
 
#include <bits/stdc++.h>
void convertNumber(int a, int n, int &count, int repre[]) {
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
 
/**
 * Ham main
 */
int main() {
    int a = 34;
    int count,  repre[100];
    convertNumber(a, 7, count, repre);
    printf("%d(10) = ", a);
    for (int i = count-1; i >= 0; --i)
    {
        printf("%d", repre[i]);
    }
    printf("(7)\n");
    return 1;
}