#include <iostream>
using namespace std;


int main(){
	int a;
	int b;
	a = 10;
	b = 2;
	cout << a << "||" << b << endl;
	int *pa, *pb;
	pa = &a;
	pb = &b;
	
	int c;
	c = *pa;
	*pa = *pb;
	*pb = c;
	
	cout << a <<"||" <<b;
	
	return 0;
}