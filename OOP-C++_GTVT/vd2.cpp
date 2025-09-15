#include <bits/stdc++.h>
using namespace std;

class KhachHang {
private:
    string hoTen;
    int namSinh;
    string soCMND;
    string khoiKH;

public:

    KhachHang() {
        hoTen = "";
        namSinh = 0;
        soCMND = "";
        khoiKH = "";
    }
    KhachHang(string ht, int ns, string cmnd, string kk) {
        hoTen = ht;
        namSinh = ns;
        soCMND = cmnd;
        khoiKH = kk;
    }
    void nhap() {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cin.ignore();
        cout << "Nhap so CMND: ";
        getline(cin, soCMND);
        cout << "Nhap khoi KH: ";
        getline(cin, khoiKH);
    }
    void xuat() {
        cout << "Ho ten: " << hoTen << "\n";
        cout << "Nam sinh: " << namSinh << "\n";
        cout << "So CMND: " << soCMND << "\n";
        cout << "Khoi KH: " << khoiKH << "\n";
    }
};

int main() {
	int n;
	cout << "n: "; cin >> n; cin.ignore();
    	KhachHang kh[n];
    	for(int i = 0; i < n; i++){
    	    cout << "Nhap thong tin khach hang " << i <<":\n";
	    kh[i].nhap();
    	}

    return 0;
}