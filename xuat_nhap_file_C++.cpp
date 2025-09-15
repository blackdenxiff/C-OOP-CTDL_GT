/*Bài 1.
Thông tin về tiền chi tiêu gồm có: 1. ID khoản mục chi tiêu là số nguyên tự động
tăng từ 1; 2. loại khoản mục: 1 là thu và 2 là chi; 3. tên khoản mục; 4. số tiền
Viết chương trình cho phép ghi ra file nhị phân(yêu cầu file được đặt tên là mã sinh
viên và tên file mở rộng .bin ) thực hiện 3 chức năng:
1. thêm mới khoản mục
2. cập nhật thông tin khoản mục
3. hiển thị tổng thu, tổng chi và số tiền tiết kiệm được */
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

typedef struct {
	int id;
	double income;// thu nhập
	double exspense;// chi phí, chi tiêu
	string item_name; //tên mặt hàng
	double so_tien;
}dsct;

void ghi_file(){
	dsct list;
	string namefile;
	cout << "nhap name file can ghi: ";
	getline(cin, namefile);
	
	ofstream fout(namefile);
	if(!fout){
		cout << "file not found error: " << namefile << endl;
		return;
	}
	
	while(1){
		cout << "nhap id[nhap 0 de off]: ";
		cin >> list.id;
		if(list.id == 0){ break;}
		cout << "income(thu nhap): ";
		cin >> list.income;
		cout << "expense(chi phi): ";
		cin >> list.exspense;
		cin.ignore();
		
		cout << "item name: ";
		getline(cin, list.item_name);
		
		fout << list.id << "\n" << list.income << "\n" << list.exspense << "\n" << list.item_name << endl;
		cout << "da ghi thanh cong: " endl;
		
	}
	fout.close();
}


int main(){
	dsct ds;
	ghi_file();
}