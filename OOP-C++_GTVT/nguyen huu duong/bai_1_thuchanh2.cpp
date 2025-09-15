#include <bits\stdc++.h>
using namespace std;

class da_thuc{
	private:
		int a[4];
		
	public:
		da_thuc(int A = 0, int B = 0, int C = 0, int D= 0);
		void nhap();
		void in();
		
		da_thuc operator+(da_thuc& dt2);
};

void da_thuc::nhap(){
	for(int i = 0; i < 4; i++){
		cout << "\nhe so bac "<< i <<": "; cin >> a[i];
	}
}
da_thuc::da_thuc(int A, int B, int C, int D){
	a[0] = A; a[1] = B; a[2] = C; a[3] = D; 
}
void da_thuc::in(){
	cout << "\nP(x) = ";
	for(int i = 0; i < 4; i++){
		if(i == 0){
			 cout << a[0];	
		}
		else if(a[i] > 0){
			cout << " + " << a[i] << "x^" << i;
		}
		else if(a[i] < 0){
			cout << " - " << a[i] << "x^" << i;	
		}
	}
}

da_thuc da_thuc::operator+(da_thuc& dt2){
	int a = this->a[0] + dt2.a[0];
	int b = this->a[1] + dt2.a[1]; 
	int c = this->a[2] + dt2.a[2]; 
	int d = this->a[3] + dt2.a[3];
	return da_thuc(a, b, c, d);
}

int main(){
	da_thuc dt1, dt2;
	
	dt1.nhap(); dt1.in();
	dt2.nhap(); dt2.in();
	
	da_thuc dt3 = dt1 + dt2;
	dt3.in();
	
	
	return 0;
}