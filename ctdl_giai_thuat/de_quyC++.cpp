#include <iostream>

using namespace std;

int number_max(int n, int& i){
	if(n < 1) return i;
	if(i < n%10) i = n%10;
	number_max(n/10, i);
}


int main(){
	int n = 123450;
	int i = 0;
	
	cout << number_max(n, i);
	cout << i;
	return 0;
}