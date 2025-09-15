#include <bits/stdc++.h>

using namespace std;

class Phan_so{
	private:
		int tu;
		int mau;
	public:
		Phan_so(int t = 0, int m = 1);
		
		
		void nhap();
		void xuat();
		
		friend void rut_gon(Phan_so& s2);
		
		Phan_so operator+(Phan_so& s2);
		Phan_so operator-(Phan_so& s2);
		Phan_so operator*(Phan_so& s2);
		Phan_so operator/(Phan_so& s2);
		
};

Phan_so::Phan_so(int t, int m){
	tu = t;
	mau = m;
}

void Phan_so::nhap(){
	cout << "nhap tu so: "; cin >> tu;
	cout << "nhap mau so: "; cin>> mau;
}

int gcd(int a, int b){
	return b == 0? a: gcd(b, a%b);
}

void rut_gon(Phan_so& s2){
	int g = gcd(abs(s2.tu), abs(s2.mau));
	if(s2.mau < 0){
		s2.mau = -s2.mau;
		s2.tu = -s2.tu;
	}
	s2.tu /= g;
	s2.mau /=g;
}

void Phan_so::xuat(){
	cout << "\n Phan so: " << "tu = " << tu << " mau = " << mau <<endl; 
}


Phan_so Phan_so::operator+(Phan_so& s2){
	Phan_so s1;
	s1.tu = this->tu*s2.mau + this->mau*s2.tu;
	s1.mau = this->mau*s2.mau;
	return s1;
}
Phan_so Phan_so::operator-(Phan_so& s2){
	Phan_so s1;
	s1.tu = this->tu*s2.mau - this->mau*s2.tu;
	s1.mau = this->mau*s2.mau;
	return s1;
}
Phan_so Phan_so::operator*(Phan_so& s2){
	Phan_so s1;
	s1.tu = this->tu*s2.tu;
	s1.mau = this->mau*s2.mau;
	return s1;
}
Phan_so Phan_so::operator/(Phan_so& s2){
	Phan_so s1;
	s1.tu = this->tu*s2.mau;
	s1.mau = this->mau*s2.tu;
	return s1;
}

int main(){
	Phan_so ps, ps2;
	
	ps.nhap();
	ps.xuat();
	
	ps2.nhap();
	ps2.xuat();
	
	Phan_so s1 = ps + ps2; rut_gon(s1); s1.xuat();
	s1 = ps - ps2;rut_gon(s1); s1.xuat();
	s1 = ps*ps2;rut_gon(s1); s1.xuat();
	s1 = ps/ps2;rut_gon(s1); s1.xuat();
	
	return 0;
}