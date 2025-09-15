#include <iostream>
#include <string>
#include <vecto>
#include <algorithm>
#include <fstream>
1. #include <vector> — Dùng mảng động hiện đại trong C++{
 #include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a;          // tạo vector rỗng
    a.push_back(10);        // thêm phần tử 10 vào cuối
    a.push_back(5);
    a.push_back(20);

    cout << "Phần tử đầu tiên: " << a[0] << endl;
    cout << "Số phần tử: " << a.size() << endl;

    return 0;
}
⚙️ Một số hàm hay dùng với vector:
Câu lệnh	Tác dụng
a.size()	Trả về số phần tử
a.push_back(x)	Thêm x vào cuối
a.pop_back()	Xóa phần tử cuối
a.clear()	Xóa hết phần tử
a[i] hoặc a.at(i)	Truy cập phần tử thứ i
vector<int> b = a;	Sao chép vector a sang b
}
2. #include <algorithm> — Gọi các thuật toán có sẵn{
	
	#include <iostream>
	#include <vector>
	#include <algorithm>
	using namespace std;
	
	int main() {
	    vector<int> a = {5, 1, 9, 3};
	
	    sort(a.begin(), a.end()); // sắp xếp tăng dần
	
	    cout << "Sau khi sắp xếp: ";
	    for (int x : a)
	        cout << x << " ";  // in ra: 1 3 5 9
	
	    reverse(a.begin(), a.end()); // đảo ngược
	
	    cout << "\nSau khi đảo ngược: ";
	    for (int x : a)
	        cout << x << " ";  // in ra: 9 5 3 1
	
	    return 0;
	}
		Các hàm trong <algorithm> hay dùng:
		Hàm	Ý nghĩa
		sort(a.begin(), a.end())	Sắp xếp tăng dần
		reverse(a.begin(), a.end())	Đảo ngược mảng
		max_element(...)	Con trỏ tới phần tử lớn nhất
		min_element(...)	Con trỏ tới phần tử nhỏ nhất
		count(a.begin(), a.end(), x)	Đếm số lần x xuất hiện
		find(a.begin(), a.end(), x)	Tìm phần tử x trong vector
}
3. nhập xuất file{
	1. thư viện cần dùng: #include <fstream>;
	2. Mở file;
		A. ghi file;
		ofstream fout("namefile"); // mở file để ghi(ghi mới, xóa nội dung cũ)
		ofstream fout("namefile", ios::app); // mở file để ghi tiếp(ko xóa nội dung cũ)
		
		B. đọc file;
		ifstream fin("namefile"); // mở file để đọc
		
		C Đọc + Ghi;
		fstream file("namefile", ios::in | ios::out); // vừa đọc vừa ghi;
		fstream file("namefile", ios::in | ios::out | ios::app) // đọc + ghi + thêm cuối;
		
	3. Ghi dữ liệu vào file;
		ofstream fout("namefile");
		fout << "helo" << endl; // ghi vào file;
		fout.close(); // dóng file;
	
	4. đọc dữ liệu;
			ifstream fin("namefiel");
			string line;
			
		cách 1: đọc theo dòng;
			while(getline(fin, line)){
				cout << line << endl;
			}
			fin.close();
		cách 2: đọc từng từ;
			while(fin >> line){
				cout << line << endl;
			}
		cách 4: đọc số;
			int x;
			while (fin >> x){
				cout << "số đọc đước" << x << endl;
			}
	
	6. Kiểm tra mở file thành công không
		cpp
		Sao chép
		Chỉnh sửa
		ifstream fin("data.txt");
		if (!fin) {
		    cout << "Không mở được file!" << endl;
		    return 1;
		}
	
	 7.d Một số chế độ mở file
		Chế độ		Ý nghĩa
		ios::in		Mở để đọc
		ios::out	Mở để ghi (xóa cũ)
		ios::app	Ghi vào cuối file
		ios::trunc	Xóa nội dung file (mặc định với out)
		ios::binary	Mở file dạng nhị phân
		ios::ate	Bắt đầu đọc/ghi tại cuối file
	
	
	
}

4. mẹo nhập xuất kí tự đủ thứ{
	1. cách nhập chuỗi có dấu cách;
		string ten;
		getline(cin, ten);
		
	2. xóa kí tự '\n'
	cout << "Nhap tuoi: ";
	cin >> tuoi;
	cin.ignore(); // ← Bỏ kí tự '\n' còn lại
		
}

