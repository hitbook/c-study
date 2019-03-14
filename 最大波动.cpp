#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int s[6] = {0};
		int t[5] = {0};
		for(int j = 0; j < 5; j++ )
			cin >> t[j];
		for(int k = 0; k < 6; k++)
			cin >> s[k];
		for(int k = 0; k < 6; k++)
			cout << s[k];
		cout << endl;
	}
}
