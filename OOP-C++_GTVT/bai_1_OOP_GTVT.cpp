#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
typedef struct{
	double x;
	double y;
}coordinates;
class diem{
	public:
		vector<coordinates> point;		
};
class straight_section{
	public:
	vector<coordinate> point;
};



coordinates nhap(){
	vector<coordinates> diem_test(1);
	cout << "nhap toa do x: "; cin >> diem_test[0].x;
	cout << "nhap toa do y: "; cin >> diem_test[0].y;
	return diem_test[0];
}

void nhap(vector<coordinates> &point, int &n){
	cout << "nhap so luong diem: "; cin >> n;
	point.resize(n);
	
	for(int i = 0; i < n; i++){
		cout << "diem [" << i <<"]: " << endl;
		point[i] = nhap();
	}
}
void xuat(vector<coordinates> diem, int n, int kt){
	if(kt == 1){
		cout << "coordisnate[" << n << "]: " << diem[n].x << " || " << diem[n].y << endl;	
		return;
	}
	else if(kt == 2){
		for(int i = 0; i < n; i++){
			cout << "coordisnate[" << i << "]: " << diem[i].x << " || " << diem[i].y << endl;
		}
		return;
	}
}

	double operator[]}(const coordinates& a,const coordinates& b){
		double c;
		c = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
		return c;
	}
	
	coordinates operator-(const coordinates& a, const coordinates& b){
		coordinates c;
		c.x = a.x - b.x;
		c.y = a.y - b.y;
		return c;
	}
	
	coordinates operator+(const coordinates& a, const coordinates& b){
		coordinates c;
		c.x = a.x + b.x;
		c.y = a.y + b.y;
		return c;
	}
	

	double distance(vector<coordinates> diem, int n){
		int a ,b; double kc = 0;
		while(1){
			cout << "distance: nhap diem dau va cuoi: "; cin>> a>> b;
			if(a < 0 || b >= n){
				cout << "loi a>=0 || b < "<< n << endl;
			} 
			else{
				break;
			}
		}
		
		for(int i = a; i < b; i++){
			double h = diem[i] + diem[i+1];
			kc += h;
		}
		return kc;
	}


int main(){
	diem D;
	int n, kt;
	nhap(D.point, n);
	xuat(D.point, n, kt = 2);
	
	double a = distance(D.point, n);
	cout << "kc: "<< a << endl;
	
	return 0;
}