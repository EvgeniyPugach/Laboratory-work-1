#include<iostream>
#include <stdio.h>
#include <stdlib.h>     // srand, rand 
#include <time.h>   // time 

const int N = 20;

using namespace std;

int TransitionFromDecimalToOctal(int n);

int main() {
	int a[N],b[N], i, j, m, k;
	srand(time(NULL));
	cout << "Random array: " << endl;
	for (i = 0; i < N; i++) {
		a[i] = rand() % 30 - 10 ;
		cout<<" "<<a[i];
	}

	cout << "\n";

	i = 0,k = 0;
	m = N;

	cout << "Array of negative numbers: " << endl;
    while (i < m) 
	   if (a[i] < 0) {
		   b[k] = a[i];
		   cout << " " << b[k];
		 m -= 1;
		 for (j = i; j < m; j++)
		     a[j] = a[j + 1];
		}
		else
		  i += 1;

    cout << "\n"; 


	cout << "Array of positive numbers: " << endl;
	for (i = 0; i < m; i++) {
		cout << " " << a[i];
	}
	cout << "\n";

	cout << "To octal"<<endl;
	for (i = 0; i < m; i++) {
		int p = TransitionFromDecimalToOctal(a[i]);
		cout <<" "<< p;
	}
	cout << "\n";
	system("pause");
	return 0;
}


int TransitionFromDecimalToOctal(int n)
{
	int  t = 0, d = 1,k=0;
	while (n)
	{
		t += (n % 8)*d;
		n = n / 8;
		d = d * 10;
	}
	return t;
}