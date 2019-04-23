#include<iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>  
#include <algorithm>

using namespace std;

int cntEvensInOctal(int x);
bool isLess(int lhs, int rhs);
void createArr(int* arr, int n);
void quickSort(int* arr, int left, int right);
int transitionFromDecimalToOctal(int n);
int createArrNandP(int* arr, int* Arr, int n);
int toOctal(int* arr, int* octarr, int n);
void arr_uniq(int * arr, int & size);

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	int *Arr = new int[n];
	int *octarr = new int[n];

	createArr(arr, n);
	int r = createArrNandP(arr, Arr, n);

	toOctal(arr, octarr, r);

	cout << "To octal" << endl;
	for (int i = 0; i < r; i++) {
		cout << " " << octarr[i];
	}
	cout << endl;

	arr_uniq(arr, r);

	cout << endl;

	cout << "Sorted array of positive numbers" << endl;
	quickSort(arr, 0, r - 1);

	for (int i = 0; i < r; i++)
	{
		cout << " " << arr[i];
	}
	cout << endl;

	

	system("pause");
	return 0;
}


void quickSort(int* arr, int left, int right)
{
	int i = left, j = right;


	int ind = ( left + right)/2;
	int pivot = arr[ind];

	
	do {
		while (isLess(arr[i], pivot)) ++i;
		while (isLess(pivot, arr[j])) --j;
		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) quickSort(arr, left, j);
	if (i < right) quickSort(arr, i, right);
}

void createArr(int*arr, int n) {


	srand(time(NULL));
int num;
	for (int i = 0; i < n; i++) {
	num = rand() % 30 - 10;
	arr[i] = num;
	}
for (int i = 0; i < n; i++) { cout << arr[i] << " "; }
	cout << endl;
}

int transitionFromDecimalToOctal(int n)
{
	int  t = 0, d = 1, k = 0;
	while (n)
	{
		t += (n % 8)*d;
		n = n / 8;
		d = d * 10;
	}
	return t;
}

int createArrNandP(int* arr, int* Arr, int n) {

	int i = 0, k = 0; int m = n;
	cout << "Array of negative numbers: " << endl;
	while (i < m)
		if (arr[i] < 0) {
			Arr[k] = arr[i];
			cout << " " << Arr[k];
			m -= 1;
			for (int j = i; j < m; j++)
				arr[j] = arr[j + 1];
		}
		else
			i += 1;
	cout << "\n";
	cout << "Array of positive numbers: " << endl;
	for (i = 0; i < m; i++) {
		cout << " " << arr[i];
	}
	cout << endl;
	return m;
}

int toOctal(int*arr, int*octarr, int n) {
	for (int i = 0; i < n; i++) {
		int p = transitionFromDecimalToOctal(arr[i]);
		octarr[i] = p;
	}
	return 0;
}



bool isLess(int lhs, int rhs) {
	return cntEvensInOctal(lhs) < cntEvensInOctal(rhs);
}

int cntEvensInOctal(int x) {
	int res = 0;
	do  {
		int bit = x % 8;
		if (bit % 2 == 0) {
			++res;
		}
		x /= 8;
	} while (x != 0);

	return res;
}

void arr_uniq(int * arr, int & size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i != j)
			{
				if (arr[i] == arr[j])
				{
					swap(arr[size - 1], arr[j]);
					size--;
				}
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << " " << arr[i];
	}
}
