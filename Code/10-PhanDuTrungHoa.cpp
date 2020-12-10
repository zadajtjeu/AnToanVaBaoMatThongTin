#include<bits/stdc++.h> 
using namespace std; 
  
// k is size of num[] and rem[].  Returns the smallest 
// number x such that: 
//  x % num[0] = rem[0],  
//  x % num[1] = rem[1],  
//  .................. 
//  x % num[k-2] = rem[k-1] 
// Assumption: Numbers in num[] are pairwise coprime  
// (gcd for every pair is 1) 
int findMinX(int num[], int rem[], int k) 
{ 
    int x = 1; // Initialize result 
    // As per the Chinese remainder theorem, 
    // this loop will always break. 
    while (true) 
    { 
        // Check if remainder of x % num[j] is  
        // rem[j] or not (for all j from 0 to k-1) 
        int j; 
        for (j=0; j<k; j++ ) 
            if (x%num[j] != rem[j]) 
               break; 
        // If all remainders matched, we found x 
        if (j == k) 
            return x; 
        // Else try next numner 
        x++; 
    } 
  
    return x; 
} 
  
// Driver method 
int main(void) 
{
    /* Example 
    5 = x mod 7 & 6 = x mod 11, x?

    7^-1 mod 11 = 8
    11^-1 mod 7 = 2
    x = (5*2*11 + 6*8*7) mod (7*11) = 61 mod 77
    */
    int num[] = {7, 11}; 
    int rem[] = {5, 6}; 
    int k = sizeof(num)/sizeof(num[0]); 
    cout << "x = " << findMinX(num, rem, k) << endl; 
    return 0; 
} 