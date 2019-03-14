#include<iostream>
using namespace std;
int main(){
	int a[10];
	a[0] = 3500;
	a[1] = 3500 + 1500 *0.97;
	a[2] = a[1] + 3000 * 0.9;
	a[3] = a[2] + 4500 * 0.8;
	a[4] = a[3] + 26000 * 0.75;
	a[5] = a[4] + 20000 * 0.7;
	a[6] = a[5] + 25000 * 0.65;
	int t ;
	cin >> t;
	if(t > a[6])
		t = 83500 + (t - a[6]) / 0.55;
	else if (t > a[5])
		t = 58500 + (t - a[5]) /0.65;
	else if ( t > a[4])
		t = 38500 + (t - a[4]) /0.7;
	else if ( t > a[3])
		t = 12500 + (t - a[3]) /0.75;
	else if ( t > a[2])
		t = 8000 + (t - a[2]) /0.8;
	else if ( t > a[1])
		t = 5000 + (t - a[1]) /0.9;
	else if ( t > a[0])
		t = 3500 + (t - a[0]) /0.97;
	else
		t = t ;
	cout << t << endl;
} 
