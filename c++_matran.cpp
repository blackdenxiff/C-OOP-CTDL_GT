#include <iostream>
#include <cmath>

using namespace std;
void enter_matrix(double a[100][100], int *m, int *n){
	cout << "nhap kich thuoc ma tran(m, n): ";
	cin >> *m >> *n;
	
	for(int i = 0; i < *n; i++){
		for(int j = 0; j < *m; j++){
			cout << "nhap phan tu[" << i << "]["<< j << "]: ";
			cin >> a[i][j];
		}
	}
}

void print_function(double a[100][100], int m, int n){
	cout << "\nmatrix: " << endl;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << "\t" << a[i][j];
		}
		cout << "\n";
	}
}
int main(){
	double a[100][100];
	int m, n;
	
	enter_matrix(a, &m, &n);
	print_function(a, m, n);
	
	return 0;
}