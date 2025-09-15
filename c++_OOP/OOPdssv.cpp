#include <iostream>
#include <string>

using namespace std;
class Giao_Vien;
class Sinh_Vien;


class Sinh_Vien{
    private:
        string name_sv;
        string khoa;
        double diem_thi;
        static int dem;

    public:

        void input_sinh_vien();
        void output_sinh_vien();
        double getdiem_thi();
        friend void in_thong_tin(Sinh_Vien); // friend function;
        friend class Giao_Vien; // friend class;

        // nhập thông tin chỉ cần cin >> là xong;
        friend istream& operator >> (istream &in, Sinh_Vien &a);
        // in thông tin chỉ cần cout << là xong;
        friend ostream& operator << (ostream &out, Sinh_Vien &a);
        // lạp chồng toán tử;
        bool operator < (Sinh_Vien a);
        ~Sinh_Vien();
};

        bool Sinh_Vien:: operator <(Sinh_Vien a){
            return this->diem_thi < a.diem_thi;
        }

        istream& operator >>(istream &in, Sinh_Vien &a){ // nhập thông tin chỉ cần cin >> là xong;
            cout << "nhap ten sv: ";
            cin >> a.name_sv;
            cout << "khoa: ";
            cin >> a.khoa;
            cout << "diem thi: ";
            cin >> a.diem_thi;
            return in;
        }

        ostream& operator << (ostream &out, Sinh_Vien &a){  // in thông tin chỉ cần cout << là xong;
            cout << a.name_sv << a. khoa << a.diem_thi << endl;
            return out;
        }


class Giao_Vien{
    private:
        string name_giao_vien;
    public:
        void update(Sinh_Vien&); // friend class
};

    void Giao_Vien::update(Sinh_Vien& a){ //friend class
        cout << "nhap ten sv: ";
        cin >> a.name_sv;
        cout << "khoa: ";
        cin >> a.khoa;
        cout << "diem thi: ";
        cin >> a.diem_thi;
    }

    void in_thong_tin(Sinh_Vien a){// friend function;
        cout << a.name_sv << a. khoa << a.diem_thi << endl;
    }


   int Sinh_Vien::dem = 0;
    Sinh_Vien::~Sinh_Vien(){
    }

    void  Sinh_Vien::input_sinh_vien(){
        cout << "nhap ten sv: ";
        cin >>this-> name_sv;
        cout << "khoa: ";
        cin >> khoa;
        cout << "diem thi: ";
        cin >> diem_thi;
    }

    void Sinh_Vien::output_sinh_vien(){
        cout << name_sv << endl;
        cout << khoa << endl;
        cout << diem_thi << endl;
    }

    double Sinh_Vien::getdiem_thi(){
        cout << diem_thi<< " " << dem<< endl;
        return diem_thi;
    }





int main(){
      Sinh_Vien x, y;
       cin >> x >> y;
       if(x < y) cout << "yes";
       else{cout << "no";}
return 0;
}
