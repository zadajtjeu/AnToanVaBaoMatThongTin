// A school method based C++ program to check if a 
// number is prime (Số nguyên tố)
#include <bits/stdc++.h> 
using namespace std; 

bool isPrime(int n) 
{ 
	// Corner case 
	if (n <= 1) 
		return false; 

	// Check from 2 to sqrt(n) or n-1
	for (int i = 2; i <= sqrt(n); i++) 
		if (n % i == 0) 
			return false; 

	return true; 
} 

// Driver Program to test above function 
int main() 
{ 
	int x;
	cout<<" Input your number: ";
	cin>>x;
	isPrime(x) ? cout << " true\n" : cout << " false\n"; 
	return 0; 
} 