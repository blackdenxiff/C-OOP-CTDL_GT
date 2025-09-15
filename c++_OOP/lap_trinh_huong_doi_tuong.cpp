    #include <iostream>
#include <string>
/* public: được phép truy cập từ bên ngoài class;
   private: chỉ bên trg class mới được sử dụng;

 => Access modefier// chỉ định(quyền) truy cập;
*/

using namespace std;
class phu_nu{
	public:
		string ho_ten;
		void trang_diem(){

		}
	private:
	bool con_zin;
};


int main(){
	phu_nu thao;
	phu_nu *test = new phu_nu;
	test->ho_ten =  "012345";

	return 0;
}
