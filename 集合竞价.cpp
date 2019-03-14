#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<sstream> 
using namespace std;
void SplitString(string& s, vector<string>& v, char c)
{
	string s1,s2;
	int i;
	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == c)
			break;
		s1.push_back(s[i]);
	}
	v.push_back(s1);
	if (i + 2 != s.size()) {
		s2.push_back(s[i + 1]);
		v.push_back(s2);
	}
}

int main()
{
	int p;
	cin >> p;
	map<string, int> P;
	for (int i = 0; i < p; i++) {
		string line;
		getline(cin, line);
		vector<string> v;
		SplitString(line, v, ':');
		int t = 0;
		if ((v.size()>1))
			for (int i = 0; i < v[1].size(); i++)
				t += (v[1][i] - 48) * 10;
		else
			t = -1;
		P[v[0]] = t;
	}
	int r;
	cin >> r;
	map<string, vector<string> > R;
	for (int i = 0; i < p; i++) {
		string line;
		getline(cin, line);
		istringstream record(line);
		string s;
		vector<string> vstr;
		record >> s;
		int t;
		record >> t;
		for (int i = 0; i < t; i++) {
			string s1;
			record >> s1;
			vstr.push_back(s1);
		}
		R[s] = vstr;
	}
	int u;
	cin >> u;
	for (int i = 0; i < u; i++) {
		string line;int b = -2;
		getline(cin, line);
		istringstream record1(line);
		string name;
		record1 >> name;
		string s;
		record1 >> s;
		vector<string> v1;
		SplitString(s, v1, ':');
		if (v1.size()) {
			int level = v1[1][0] - 48;
			vector<string> ::iterator ite = R[name].begin();
			
			for (ite; ite != R[name].end(); ite++) {
				if (*ite == v1[0])
					if (P[*ite] >= level)
						b = -1;
			}
		}
		else {
			int level = -1;
			vector<string> ::iterator ite = R[name].begin();
			for (ite; ite != R[name].end(); ite++) {
				if (*ite == v1[0]) {
					if (P[*ite] == level)
						b = -1;
					else
						b = P[*ite];
				}
			}
			
		}
		if (b == -2)
			cout << false << endl;
		else if (b == -1)
			cout << true << endl;
		else
			cout << b;

	}
	system("PAUSE");
	return 0;
}

