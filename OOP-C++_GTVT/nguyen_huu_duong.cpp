#include <iostream>
#include <cmath>
using namespace std;

class DaThuc {
private:
    int n;
    float *hs;

public:
    DaThuc() : n(0), hs(nullptr) {}

    DaThuc(int bac) {
        n = bac;
        hs = new float[n+1];
        for (int i = 0; i <= n; i++) hs[i] = 0;
    }

    ~DaThuc() {
        delete[] hs;
    }

    DaThuc(const DaThuc& other) {
        n = other.n;
        hs = new float[n+1];
        for (int i = 0; i <= n; i++) hs[i] = other.hs[i];
    }

    DaThuc& operator=(const DaThuc& other) {
        if (this != &other) {
            delete[] hs;  
            n = other.n;
            hs = new float[n+1];
            for (int i = 0; i <= n; i++) hs[i] = other.hs[i];
        }
        return *this;
    }

    void nhap() {
        cout << "Nhap bac cua da thuc: ";
        cin >> n;
        hs = new float[n+1];
        for (int i = 0; i <= n; i++) {
            cout << "He so bac " << i << ": ";
            cin >> hs[i];
        }
    }

    void xuat() const {
        for (int i = n; i >= 0; i--) {
            cout << hs[i];
            if (i > 0) cout << "x^" << i << " + ";
        }
    }

    DaThuc operator+(const DaThuc& other) {
        int maxBac = max(n, other.n);
        DaThuc kq(maxBac);

        for (int i = 0; i <= maxBac; i++) {
            float a = (i <= n) ? hs[i] : 0;
            float b = (i <= other.n) ? other.hs[i] : 0;
            kq.hs[i] = a + b;
        }
        return kq;
    }

    friend float tinhGiaTri(const DaThuc& dt, float x0);
};

float tinhGiaTri(const DaThuc& dt, float x0) {
    float kq = 0;
    for (int i = 0; i <= dt.n; i++) {
        kq += dt.hs[i] * pow(x0, i);
    }
    return kq;
}

int main() {
    DaThuc p, q;
    cout << "Nhap da thuc p:\n";
    p.nhap();
    cout << "Nhap da thuc q:\n";
    q.nhap();

    float y;
    cout << "Nhap gia tri y: ";
    cin >> y;

    DaThuc tong = p + q;

    cout << "\nDa thuc tong (p+q) la: ";
    tong.xuat();
    cout << endl;

    float val = tinhGiaTri(tong, y);
    cout << "Gia tri (p+q) tai y = " << y << " la: " << val << endl;

    return 0;
}
