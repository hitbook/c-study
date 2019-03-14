#include<iostream>
#include<vector>
using namespace std;

int dfs(vector<int> G[], int v[], vector<int> pre, int i){
	if(v[i]){
		int t = pre.size();
		pre.pop_back();		
		if(t == 1)
			return 0;
		else
			return t*(t-1) / 2;
	}
	v[i] = 1;
	pre.push_back(i);
	int sum = 0;
	for(int k = 0; k < G[i].size(); k++){
		sum += dfs(G, v, pre, G[i][k]);
	}
	pre.erase(pre.end() - 1);
	return sum;
	
}
int main()
{
	
	int n, m;
	vector<int> G[10000];
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--;b--;
		G[a].push_back(b);
	}
	int v[10000] ;
	for(int i = 0; i < n; i++)
		v[i] = 0;
	vector<int> pre;
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += dfs(G, v, pre, i);
	cout << sum <<endl;
	return 0; 
}
