#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<int> s[100];

void dfs(vector<int> G[], int v[], vector<int> pre, int i, int& count) {
	if (v[i]&&pre.size()) {
		int j;
		for (j = 0; j < count; j++) {
			if (s[j].count(i))
				break;
		}
		
		int t = 0;
		if (j != count ) {
			for (t; t < pre.size(); t++)
			{
				if (s[j].count(pre[t]))
					break;
			}
		}
		else {
			for (t; t < pre.size(); t++)
				if (pre[t] == i)
					break;
		}
		for (t; t < pre.size(); t++) {
			s[j].insert(pre[t]);
		}
		if (j == count)
			count++;
	}
	else {
		v[i] = 1;
		pre.push_back(i);
		for (int k = 0; k < G[i].size(); k++) {
			dfs(G, v, pre, G[i][k], count);
		}
		pre.pop_back();
	}
	
}
int main()
{

	int n, m;
	vector<int> G[100];
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;b--;
		G[a].push_back(b);
	}
	int v[100];
	for (int i = 0; i < n; i++)
		v[i] = 0;
	vector<int> pre;
	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
		dfs(G, v, pre, i,count);
	for (int i = 0; i < count-1; i++)
		for (int j = i+1; j < count; j++)
		{
			for(set<int>::iterator ite = s[j].begin(); ite != s[j].end(); ite++)
				if (s[i].count(*ite)) {
					s[i].insert(s[j].begin(), s[j].end());
					for (int o = j; o < count; o++)
						s[o] = s[o + 1];
					j--;
					count--;
					break;
				}
		}
	for (int i = 0; i < count; i++)
		sum += s[i].size() *(s[i].size() - 1) / 2;
	cout << sum << endl;
	system("PAUSE");
	return 0;
}