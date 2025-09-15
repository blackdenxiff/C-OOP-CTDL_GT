/*Bài 2: Viết chương trình xây dựng lớp MaTran để nhập ma trận số nguyên kích thước m × n (với m, n ≤ 100).
- Yêu cầu đối với lớp MaTran:
+ Có hàm tạo nhận vào số dòng và số cột, dùng để khởi tạo một đối tượng ma trận với kích thước cho trước.
+ Có phương thức để xuất ma trận ra màn hình theo dạng bảng.
+ Có phương thức để tính và trả về tổng giá trị của tất cả các phần tử trong ma trận.
+ Có phương thức để tìm và trả về phần tử nhỏ nhất trong ma trận.
+ Nạp chồng toán tử cộng (operator+) để thực hiện phép cộng hai ma trận có cùng kích thước, trả về một ma trận mới. Nếu hai ma trận khác kích thước thì thông báo lỗi.
- Yêu cầu đối với chương trình chính:
+ Nhập hai ma trận A và B có cùng kích thước.
+ Xuất hai ma trận ra màn hình.
+ In ra:
Tổng giá trị các phần tử của ma trận A.
Giá trị nhỏ nhất trong ma trận B.
Ma trận C = A + B.
*/


#include <iostream>
#include <cmath>

using namespace std;

class Ma_tran{
	private:
		int m, n;
		int **a;
		
	public:
	
	Ma_tran(int m = 0, int n = 0);
	
	int gt_a(int i, int j);
	void nhap();
	void xuat();
	
	int gt_m();
	int gt_n();
	int Min();
	int tong_pt(int m, int n);
	
	Ma_tran operator+(Ma_tran &m2);
};

Ma_tran::Ma_tran(int m, int n){
	this->m = m;
	this->n = n;
		
	if(m > 0 && n > 0){
		a = new int*[m];
		for(int i = 0; i < m; i++){
			a[i] = new int[n];
		}
	}
	else{
		a = nullptr;
	}
}
void Ma_tran::nhap(){
		if(m == 0 && n == 0){
			cout <<"nhap kich thuc ma tran: "; cin >> m >> n;	
		}
		
		a = new int*[m];
		for(int i = 0; i < m; i++){
			a[i] = new int[n];
		}
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cout << "pt[" << i << "]" << "[" << j << "]: ";
				cin >> a[i][j];
			}
		}
	//
	}
	
int Ma_tran::gt_a(int i, int j){
	return a[i][j];
}

int Ma_tran::gt_m(){
	return this->m;
}
int Ma_tran::gt_n(){
	return this->n;
}

void Ma_tran::xuat(){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << "\t" << a[i][j];
		}
		cout << endl;
	}
}

int Ma_tran::tong_pt(int m, int n){
	if(m == this->m && n == this->n){
		m -= 1; n -= 1;
	}
	if(n == 0){
		if(m == 0)return a[m][n];
		return a[m][0] + tong_pt(m - 1, this->n);
	}
	else{
		return a[m][n] + tong_pt(m, n - 1);
	}
}

int Ma_tran::Min(){
	int min = a[0][0];
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] < min)min = a[i][j];
		}
	}
	return min;
}

Ma_tran Ma_tran::operator+(Ma_tran& m2){
	Ma_tran m1(m, n);

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			m1.a[i][j] = m2.a[i][j] + this->a[i][j];
		}
	}
	return m1;
}


int main(){
	Ma_tran mt2(3, 3), mt3(3, 3);
	
	mt2.nhap();
	mt2.xuat();
	mt3.nhap();
	mt3.xuat();
	cout << "\ntong pt: "<< mt2.tong_pt(mt2.gt_m(), mt2.gt_n()) << endl;
	
	Ma_tran mt1 = mt2 + mt3;
	mt1.xuat();
	
	return 0;
}
