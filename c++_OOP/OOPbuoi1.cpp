#include <iostream>
#include <string.h>


using namespace std;

typedef struct{
    int ma_hang;
    string ten_hang;
    string xuat_xu;
    int loai_hang;
    int so_long;
    int tgbh;
}ds;

void nhap(ds **dsh, int *n) {
    cout << "Nhap so luong hang: ";
    cin >> *n;
    cin.ignore();

    *dsh = new ds[*n];

    for (int i = 0; i < *n; i++) {
        cout << "Hang[" << i + 1 << "]" << endl;

        cout << "Ma hang: ";
        cin >> (*dsh)[i].ma_hang;
        cin.ignore();

        cout << "Ten hang: ";
        getline(cin, (*dsh)[i].ten_hang);

        cout << "Xuat xu: ";
        getline(cin, (*dsh)[i].xuat_xu);

        cout << "Loai hang: ";
        cin >> (*dsh)[i].loai_hang;
        cin.ignore();

        cout << "So luong: ";
        cin >> (*dsh)[i].so_long;
        cin.ignore();

        cout << "Thoi gian bao hanh: ";
        cin >> (*dsh)[i].tgbh;
    }
}
void xuat(ds *dsh, int n){
    cout <<"ma hang: "<< dsh[n].ma_hang << "| ten hang: " << dsh[n].ten_hang <<
        "| xuat xu: "<< dsh[n].xuat_xu << "| loai hang" << dsh[n].loai_hang << "| so luong: " << dsh[n].so_long << "| tgbh: " <<dsh[n].tgbh<<endl;
}
int thong_ke(ds *dsh, int n){
    cout << "thong ke hang co thgbh tren 12 thang" << end
    l;
    for(int i = 0; i < n; i++){
        if(dsh[i].tgbh  > 12){
            xuat(dsh, i);
        }
    }
}

int main(){
    int n;
    ds *dsh;
    nhap(&dsh, &n);
    thong_ke(dsh, n);

return 0;
}
