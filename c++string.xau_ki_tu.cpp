#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	string s1; // declare empty string// khai báo xâu rỗng
	string s2 = "";// declare empty string // khai báo xâu rỗng
	string s3 = "duongdepzai"; //declare string with content // khai báo xâu có nội dung;
	
	cout << "content s1: " << s1 << endl;
	cout << "number of characters s1: " << s1.size() << endl; // số lượng kí tự s1:
	cout << "content s2: " << s2 << endl;
	cout << "number of characters s2: " << s2.size() << endl;
	cout << "content s3: " << s3 << endl;
	cout << "number of characters s3: " << s3.size() << endl;
	// browse string; // duyệt
	for(int i = 0; i < (int)s3.size(); i++){
		cout << i << ": " << s3[i] << endl;
	}
	
	cout << "nhap chuoi s1: " << s1;
	cin >> s1;
	cin.ignore(); // delete \enter\
	cout << s1 <<endl;
	
	s1.push_back('&'); // add a charater to the end of the string// thêm 1 kí tự vào cuối chuỗi;
	cout << s1 <<endl;
	s1.pop_back();
	cout << s1 <<endl;// delete a character at the end of the string// xóa 1 kí tự ở cuối chuỗi;
	
	s3.append("12a2");// append the string// nối chuỗi;
	cout << s3 <<endl;
	s3.append(s1); // 
	cout << s3 <<endl;
	
	s3 += s1;// append the string; nối thêm chuỗi;
	s3 += "CNTT_3";
	cout << s3 <<endl;
	
	//name_string.insert(index, strings); insert: chèn, index: chỉ số;
	s3.insert(5, "***"); // append string at any position// chèn thê chuỗi ở bất kì vị trí nào;
	cout << s3 <<endl;
	s3.insert(8, s1);
	cout << s3 <<endl;
	
	s3.erase(6);// delete from character 6th to of the string;// xóa từ kí tự thứ 6 đến cuối chuỗi;
	cout << s3 <<endl;
	
	string s = "12345678910";
	s.erase(6, 10); // delete from character 6th to 10th; // xóa từ kí tự thứ 6 đến  10;
	cout << s <<endl;
	
	string test = "nguyenhuuduong";
	string s4 = test.substr(2, 8); // cut string from 2th to 8th assign to s4; cứ chuỗi từ 2 đến 8 gán vào s4;
	cout << s4 <<endl;
	
	
	test = "nguyenhuuduong";
	if(test.find("huu") == string::npos){
		cout << "NOT FOUND"<< endl; // not found// ko tìm thấy;
	}
	else{
		cout << "FOUND" << endl;
		cout << test.find("huu"); // Hàm này sẽ trả về chỉ số đầu tiên của xâu con nếu xâu này tồn tại trong xâu đang tìm kiếm, ngược lại sẽ trả về giá trị là string::npos 
	}
	
	
	// so sánh
	//Để so sánh 2 xâu trong C++ bạn có thể sử dụng luôn các toán tử so sánh như >, <, !=, ==...
	cout << boolalpha << ("28tech" == "28tech") << endl;
	cout << boolalpha << ("28tech" != "28tech") << endl;
	cout << boolalpha << ("28techabc" < "28techza") << endl;
	cout << boolalpha << ("28Tech" < "28tech") << endl;
	cout << boolalpha << ("28 tech" < "28@tech") << endl;
	
	//Ngoài ra bạn có thể sử dụng hàm compare() hoặc tự cài đặt hàm này cho mình;
	string s0 = "28tech", t = "28Tech", p = "28tech";
	cout << s0.compare(p) << endl;
	cout << s0.compare(t) << endl;
	cout << t.compare(p) << endl;
	
	return 0;
}