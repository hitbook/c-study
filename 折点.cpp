#include<iostream>
#include<vector>
using namespace std;
int DFS(int i, int j, int n, int m, int v[][100], int left[][100], int right[][100], int visit[][100], int cnt){
	if(i < 0 || j < 0 || i >= n || j <= m || visit[i][j])
		return 0;
	if(v[i][j] && cnt <= right[i][j] && cnt >= left[i][j])
		return 0;
	if(i == n - 1&& j == m-1 )
		return cnt;
	visit[i][j] = 1;
	int t[4];
	t[0] = DFS(i, j - 1, n, m, v, left, right,visit, cnt+1);
	t[1] = DFS(i, j + 1, n, m, v, left, right, visit,cnt+1);
	t[2] = DFS(i - 1, j , n, m, v, left, right, visit, cnt+1);
	t[3] = DFS(i + 1, j, n, m, v, left, right, visit, cnt+1);
	int min = 1000000;
	for(int k = 0; k < 4; k++)
		if(t[k] < min&& t[k] != 0)
			min = t[k];
	if(min == 1000000){
		visit[i][j] = 0;
		return 0;
	}
	cout << min <<endl;
	return min;
	
}
int main()
{
	int n, m, t;
	cin >> n >> m >> t;
	int v[100][100], left[100][100], right[100][100];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			v[i][j] = 0;
	for(int i = 0; i < t; i++){
		int t1,t2, l ,r;
		cin >> t1 >> t2 >> l >> r;
		v[t1][t2] = 1;
		left[t1][t2] = l;
		right[t1][t2] = r;
	}
	int visit[100][100];
	int te[2];
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			visit[i][j] = 0;
	te[0] = DFS(1, 0, n, m, v, left, right, visit, 1);
	te[1] = DFS(0, 1, n, m, v, left, right, visit, 1);
	int min = 1000000;
	cout << te[0] << "  " << te[1] << endl;
	for(int i = 0; i < 2; i++)
		if(te[i] !=0 && te[i] < min)
			min = te[i];
	cout << min <<endl;
	return 0;
 } 
