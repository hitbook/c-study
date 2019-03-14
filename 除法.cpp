#include<iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int a[n+1];
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	while(m--){
		int t;
		cin >> t;
		if(t == 1)
		{
			int l, r, v;
			cin >> l >> r >> v;
			for(int i = l; l <= r; i++)
				if(!a[i]%v)
					a[i] = a[i] / v;
		}
		if(t == 2){
			int l, r;
			cin >> l >> r;
			int sum = 0;
			for(int i = l; i <= r; i++)
				sum += a[i];
			cout << sum << endl;
		}
	}
	return 0;
 } 
