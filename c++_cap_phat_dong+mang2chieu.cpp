#include <iostream>
#include <cmath>

using namespace std;
void enter_matrix(double** &a, int *m, int *n){
	cout << "nhap kich thuoc ma tran(m, n): ";
	cin >> *m >> *n;
	
	a = new double*[*n];
	for(int l = 0; l < *n; l++){
		a[l] = new double[*m];
	}
	if(a == NULL){
		cout << "\n ko the cap phat bo nho: :(";
		return;
	}
	for(int i = 0; i < *n; i++){
		for(int j = 0; j < *m; j++){
			cout << "nhap phan tu[" << i << "]["<< j << "]: ";
			cin >> a[i][j];
		}
	}
}
void free_matrix(double** &a, int n){
	for(int i = 0; i < n; i++){
		delete[] a[i];
	}
	delete[] a;
}
void print_function(double **a, int m, int n){
	cout << "\nmatrix: " << endl;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << "\t" << a[i][j];
		}
		cout << "\n";
	}
}

int main(){
	double **a;
	int m, n;
	
	enter_matrix(a, &m, &n);
	print_function(a, m, n);
	free_matrix(a, n);
	return 0;
}

