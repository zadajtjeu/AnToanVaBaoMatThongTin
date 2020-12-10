// C++ program to display first N Prime numbers 
#include <bits/stdc++.h> 
using namespace std; 

// Function to print first N prime numbers 
void print_first_N_primes(int N) 
{ 
	// Declare the variables 
	int i, j, flag; 

	// Print display message 
	cout << "\nPrime numbers between 1 and "
		<< N << " are:\n"; 

	// Traverse each number from 1 to N 
	// with the help of for loop 
	for (i = 1; i <= N; i++) { 

		// Skip 0 and 1 as they are 
		// niether prime nor composite 
		if (i == 1 || i == 0) 
			continue; 

		// flag variable to tell 
		// if i is prime or not 
		flag = 1; 

		for (j = 2; j <= i / 2; ++j) { 
			if (i % j == 0) { 
				flag = 0; 
				break; 
			} 
		} 

		// flag = 1 means i is prime 
		// and flag = 0 means i is not prime 
		if (flag == 1) 
			cout << i << " "; 
	} 
}

void print_N_primes(int N) 
{ 
	// Declare the variables 
	int i, j, flag, count = 0;

	// Print display message 
	cout << "\nThe first "<< N << " Prime numbers:\n"; 

	// Traverse each number from 1 to N 
	// with the help of for loop 
	for (i = 1; count < N; i++) { 

		// Skip 0 and 1 as they are 
		// niether prime nor composite 
		if (i == 1 || i == 0) 
			continue; 

		// flag variable to tell 
		// if i is prime or not 
		flag = 1; 

		for (j = 2; j <= i / 2; ++j) { 
			if (i % j == 0) { 
				flag = 0; 
				break; 
			} 
		} 

		// flag = 1 means i is prime 
		// and flag = 0 means i is not prime 
		if (flag == 1)
		{
			count++;
			cout << i << " "; 
		}
	} 
} 

// Driver code 
int main() 
{ 
	int N;
	cout << "Prime numbers between 1 and N, Input N = ";
	cin >> N; 
	print_first_N_primes(N); 

	//print the first N prime number
	int M;
	cout << "\n\n\nPrint the first M prime number, Input M = ";
	cin >> M; 
	print_N_primes(M);

	cout<<endl;
	return 0; 
} 
