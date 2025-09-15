#include <iostream>

using namespace std;

void binary_system(int n){
	if(n < 2){
		cout << " 1 ";
		return;
	}
	else{
		cout << " " << n%2;
		binary_system(n/2);
	}
}

void kt_hexadecimal_system(int n){
	if(n%16 < 10) cout << " " << n%16;
	else if(n%16 == 10) cout << " A ";
	else if(n%16 == 11) cout << " B ";
	else if(n%16 == 12) cout << " C ";
	else if(n%16 == 13) cout << " D ";
	else if(n%16 == 14) cout << " E ";
	else if(n%16 == 15) cout << " F ";
}

void hexadecimal_system(int n){
	if(n < 16){
		kt_hexadecimal_system(n);
		return;
	}
	else{
		hexadecimal_system(n/16);
		kt_hexadecimal_system(n);
	}
}

int dem_so(int n, int& i){
	if(n < 10){
		i += 1; return i;
	}
	else{
		dem_so(n/10, i); i += 1; return i;
	}
}
 
int total(int n, int& i){
	if(n < 10){
		i = n;
		return i;
	}
	else{
		total(n/10, i); i += n%10; return i;
	}
}

int total2(int n){
	if(n < 10){
		return n;
	}
	else{
		return n%10 + total2(n/10);
	}	
}



int main(){
	int n;
	int i = 0;
	cin >> n;
	binary_system(n); cout <<"\n";
	hexadecimal_system(n); cout << "\n";
	cout << dem_so(n, i) << endl;
	cout << total2(n) << endl;
	return 0;
}