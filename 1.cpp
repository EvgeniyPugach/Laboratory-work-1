#include<iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>  

using namespace std;

void createArr(int* arr, int n);
void quickSort(int* arr, int left, int right);
int transitionFromDecimalToOctal(int n);
int createArrNandP(int* arr, int* Arr, int n);
void toOctal(int* arr,int* octarr, int n);
int amountEven(int);
/*void quickSortEven(int* arr, int left, int right);*/

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	int *Arr = new int[n];
	int *octarr = new int[n];

	createArr(arr, n);
	int r = createArrNandP(arr, Arr, n);

	toOctal(arr,octarr, r);

	cout << "To octal" << endl;
	for (int i = 0; i < r; i++) {
		cout << " " << octarr[i];
	}
	cout << endl;

	system("pause");
}


void quickSort(int* arr, int left, int right)
{
	int i = left, j = right;

	int tmp;

	int pivot = arr[(left + right) / 2];

	while (i <= j) {

		while (arr[i] < pivot)

			i++;

		while (arr[j] > pivot)

			j--;

		if (i <= j) {

			tmp = arr[i];

			arr[i] = arr[j];

			arr[j] = tmp;

			i++;

			j--;

		}

	};

	if (left < j)

		quickSort(arr, left, j);

	if (i < right)

		quickSort(arr, i, right);

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

int createArrNandP(int* arr,int* Arr, int n) {

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
	return m;
}

void toOctal(int*arr,int*octarr,int n ) {
	for (int i = 0; i < n; i++) {
		int p = transitionFromDecimalToOctal(arr[i]);
		octarr[i] = p;
	}
	cout << "\n";
}

int  amountEven(int n)
{
	int  m, k;
	int b = 0;

	while (n != 0)
	{
		k = 10;
		m = n % k;

		if (m % 2 == 0 )
			b++;

		n = n - m;
		n = n / k;
		k = k * 10;
	}

	return b;
}

/*void quickSortEven(int* arr, int left, int right)
{
	int i = left, j = right;

	int tmp;

	int pivot = amountEven( arr[left + right / 2]);

	

	while (i <= j) {

		while (amountEven(arr[i]) < pivot)

			i++;

		while (amountEven(arr[j]) > pivot)

			j--; 

		if (i <= j) {

			tmp = arr[i];

			arr[i] = arr[j];

			arr[j] = tmp;
			
			i++;

			j--;

		}

	};

	if (left < j)

		quickSortEven(arr, left, j);

	if (i < right)

		quickSortEven(arr, i, right);

}*/