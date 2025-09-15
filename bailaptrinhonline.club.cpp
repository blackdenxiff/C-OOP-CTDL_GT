#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<double> a(n);
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());// xắp sếp từ bé dến lớn;
	
	double median = a[n/2];
	
	double s = 0;
	for(int i = 0; i < n; i++){
		s += fabs(a[i] - median);
	}
	cout << s << endl;
	
	return 0;
}