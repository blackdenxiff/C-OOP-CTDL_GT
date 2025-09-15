#include <iostream>

using namespace std;

void function_enter_n(int *n){
	while(1){
		cout << "nhap so nguyen duong n: "; cin >> *n;
		if(n > 0){
			break;
		}
		else{
			cout << "loi n phai lon hon 0: vui long nhap lai:" << endl;
		}
	}
}
void test_function(int n){
	for(int i = 1; i <= n; i++){
		cout << "[i = " << i << "]: ";
		if(i%2 == 0){
			cout << "L";
		}
		else{
			cout << i;
		}
		if(i%4 == 0){
			cout << "T";
		}
		if(i%8 == 0){
			cout << "O";
		}
		if(i%16 == 0){
			cout << "L";
		}
		cout <<"\n";
	}
}
int main(){
	int n;
	function_enter_n( &n);
	test_function(n);
}