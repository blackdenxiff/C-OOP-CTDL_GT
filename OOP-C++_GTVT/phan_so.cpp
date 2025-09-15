#include <iostream>
#include <numeric>
using namespace std;

class Phan_so {
private:
    int tu;
    int mau;
public:
    Phan_so();
    void copy(int t, int m);
    void nhap();
    void in() const;
    Phan_so operator+(const Phan_so &b) const;
    Phan_so operator-(const Phan_so &b) const;
    Phan_so operator*(const Phan_so &b) const;
    Phan_so operator/(const Phan_so &b) const;
};

Phan_so::Phan_so() {
    tu = 0;
    mau = 1;
}

void Phan_so::copy(int t, int m) {
    tu = t;
    mau = m;
}

void Phan_so::nhap() {
    int t, m;
    while (1) {
        cout << "Nhap tu so: "; cin >> t;
        cout << "Nhap mau so: "; cin >> m;
        if (m == 0) {
            cout << "Loi: mau = 0, nhap lai.\n";
            continue;
        }
        copy(t, m);
        break;
    }
}

void Phan_so::in() const {
    cout << tu << "/" << mau;
}

Phan_so Phan_so::operator+(const Phan_so &b) const {
    Phan_so kq;
    kq.tu = tu*b.mau + b.tu*mau;
    kq.mau = mau*b.mau;
    return kq;
}

Phan_so Phan_so::operator-(const Phan_so &b) const {
    Phan_so kq;
    kq.tu = tu*b.mau - b.tu*mau;
    kq.mau = mau*b.mau;
    return kq;
}

Phan_so Phan_so::operator*(const Phan_so &b) const {
    Phan_so kq;
    kq.tu = tu*b.tu;
    kq.mau = mau*b.mau;
    return kq;
}

Phan_so Phan_so::operator/(const Phan_so &b) const {
    Phan_so kq;
    if (b.tu == 0) {
        cout << "Loi: chia cho phan so tu=0!\n";
        kq.tu = 0; kq.mau = 1;
        return kq;
    }
    kq.tu = tu*b.mau;
    kq.mau = mau*b.tu;
    return kq;
}

int main() {
    Phan_so P1, P2;
    cout << "Nhap phan so 1:\n"; 
    P1.nhap();
    cout << "Nhap phan so 2:\n"; 
    P2.nhap();

    cout << "P1 = "; P1.in(); 
    cout << "\nP2 = "; P2.in(); 

    cout << "\nCong: "; (P1 + P2).in();
    cout << "\nTru: "; (P1 - P2).in();
    cout << "\nNhan: "; (P1 * P2).in();
    cout << "\nChia: "; (P1 / P2).in();

    return 0;
}
