#include<iostream>
using namespace std;
int main()
{
	long long int cur = 0;
	long long int cnt = 0;
	int r, y, g;
	cin >> r >> y >> g;
	int T = r + g + y;
	int n;
	cin >> n;
	int road[100000][2];
	for (int i = 0; i < n; i++)
		cin >> road[i][0] >> road[i][1];
	for (int i = 0; i < n; i++) {
		cnt = cur % T;
		switch (road[i][0]) {
		case 0:
			cur += road[i][1];
			break;
		case 1:
			if (cnt < road[i][1])
				cur += road[i][1] - cnt;
			else if (cnt >= road[i][1] && cnt < road[i][1] + g)
				cur = cur;
			else 
				cur += T - cnt + road[i][1];
			break;
		case 2:
			if (cnt < road[i][1])
				cur += road[i][1] - cnt + r;
			else if (cnt >= road[i][1] && cnt < road[i][1] + r)
				cur += road[i][1] + r - cnt;
			else if (cnt >= road[i][1] + r && cnt < road[i][1] + r + g)
				cur = cur;
			else
				cur += T - cnt + road[i][1] + r;
			break;
		case 3:
			if (cnt < road[i][1])
				cur = cur;
			else if (cnt >= road[i][1] && cnt < road[i][1] + y)
				cur += y - cnt + road[i][1] + r;
			else if (cnt >= road[i][1] + y && cnt < road[i][1] + y + r)
				cur += road[i][1] + y + r - cnt;
			else
				cur = cur;
			break;
		}
		
	}
	
	cout << cur << endl;
	return 0;
}