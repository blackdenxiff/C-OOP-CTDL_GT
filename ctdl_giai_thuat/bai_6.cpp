#include <iostream>
#include <cmath>
using namespace std;


void nhap(int* &a, int *n){
	cout << "nhap so luong pt: ";
	cin >> *n;
	a = new int[*n];
	for(int i = 0; i < *n; i++){
		cout << "pt[" << i << "]: ";
		cin >> a[i];
	}
}

void Move(int a[], int n){
	int k;
	int b[n];
	cout << "\nnhap k pt dau tien: ";
	cin >> k;
	
	for(int i = 0; i < n - k; i++){
		b[i] = (a[i + k]); 	
	}
	for(int i = 0; i < k; i++){
		b[n - k + i] = (a[i]);
	}
	for(int i = 0; i < n; i++){
		(a[i]) = b[i];
	}
}
void ham_in(int a[], int  n){
	cout << "\nday pt: ";
	for(int i = 0; i < n; i++){
		cout << " | " << a[i];
	}
}

int main(){
	int *a;
	int n;
	
	nhap(a, &n);
	ham_in(a, n);
	Move(a, n);
	ham_in(a, n);
	return 0;
}