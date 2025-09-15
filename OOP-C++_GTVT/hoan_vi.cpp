#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void nhap(int& n, vector<int>& a){
	cout << "nhap so luong phan tu: "; cin >> n;
	a.resize(n);
	for(int  i = 0; i < n; i++){
		cout << "[" << i << "]: "; cin >> a[i];
	}
}

int giai_thua(int a){
	if(a == 1 || a == 0) return a;
	return a*giai_thua(a - 1);
}
int main(){
	int n;
	vector<int> a;
	
	nhap(n, a);
	
	for(int i = 0; i < n; i++){
		int test = a[i];
		cout << "gt_" << a[i] << ": " << giai_thua(test) << endl; 
	}
	
	
	
	return 0;
}