#include <iostream>
#include <string>

using namespace std;

void Move(int n, char a, char b, int& i){
	cout << "dia["<< n << "]: " << a << " -> " << b << " " << i <<endl;
}

void arrange(int n, char a, char b, char c, int& i){
	i++;
	if(n == 1){
		Move(n, a, c, i); return;
	}
	else{
		arrange(n - 1, a, c, b, i);
		Move(n, a, c, i);
		arrange(n - 1, b, a, c, i);	
	}
}


int main(){
	int n;
	cin >> n;
	int i = 0;
	arrange(n, 'A', 'B', 'C', i);
	
	return 0;
}