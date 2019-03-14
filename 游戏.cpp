#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int a[1000];
	for(int i = 0; i < t; i++)
		cin >> a[i];
	int min = 10000;
	for(int i = 0; i < t - 1; i ++){
		for(int j = i + 1; j < t; j++)
			if(abs(a[j] - a[i]) < min)
				min = abs(a[j] - a[i]);
	}
	cout << min;
 } 
