#include <iostream>
#include <utility>
#include <iomanip>

using namespace std;

int main(){
	/*
	pair <char, int > a('a', 333);
	cout << a.first << ' ' << a.second << endl;
	
	
	pair <pair<char, int>, pair<int , int>> b{{'k', 2}, {2, 3}};
	cout << b.first.first << '\t' << b.first.second << endl;
	
	cout << boolalpha << (a.first == b.first.first) << endl;
	*/
	
	// toans tu gan
	/*
	double g, h;
	double value1;
	while(1){
		cout << "nhap gia tri g, h: ";
		cin >> g >> h;
		value1 = g/h;
		cout << "gia tri g/h = " << setprecision(100) << value1 << endl;
		cout << "gia tri g/h = " << fixed << setprecision(3) << value1 << endl;
	}*/
	
	//true && true = true
    bool res1 = (10 < 20) && (20 >= 20);
    //true && true && false = false
    bool res2 = (10 < 20) && (20 == 20) && (5 > 10);
    //false || false || true = true
    bool res3 = (10 > 20) || (20 < 10) || (5 == 5);
    // !(true) = false
    bool res4 = !(10 < 20);
    //!(true && true) = !(true) = false
    bool res5 = !((20 < 30) && (30 > 10));
    cout << res1 << " " << res2 << " " << res3 << " " << res4 << " " << res5 << endl;
	return 0;
}