#include <iostream>
#include <cmath>
#include <string>

using namespace std;

typedef struct{
	int sbd;
	string name;
	float diem_thi;
}ds;

ds nhap(){
	ds t;
	cout << "sbd: "; cin >> t.sbd;
	cin.ignore();
	cout << "ho ten"; getline(cin, t.name);
	cout << "diem: "; cin >> t.diem_thi;
	
	return t;
}

void nhap(ds **dsd, int &n){
	cout << "nhap so luon sv: ";
	cin >> n;
	
	*dsd = new ds[n];
	
	for(int i = 0; i < n; i++){
		(*dsd)[i] = nhap();
	}
}

void in(ds *dsd, int n){
	for(int i = 0; i < n; i++){
		cout << "std["<< i + 1 << "] | sbd: " << dsd[i].sbd << " | name: " << dsd[i].name << " | diem: " << dsd[i].diem_thi << endl;
	}
}

 cong operator-(Complex& other){
 	return 
 }

int main(){
	ds *dsd;
	int n;
	
	nhap(&dsd, n);
	in(dsd, n);
	
	return 0;
}