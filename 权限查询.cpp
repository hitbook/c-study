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
	if (i  != s.size()) {
		s2.push_back(s[i + 1]);
		v.push_back(s2);
	}
}

int main()
{
	int p;
	cin >> p;
	getchar();
	map<string, int> P;
	for (int i = 0; i < p; i++) {
		string str;
		getline(cin, str);
		vector<string> v;
		SplitString(str, v, ':');
		int t = 0;
		if ((v.size()>1))
			for (int i = 0; i < v[1].size(); i++)
				t += (v[1][i] - 48) * 10;
		else
			t = -1;
		P[v[0]] = t;
	}
	int r;
	cin >> r;getchar();
	map<string, vector<pair<string, int> > > R;
	for (int i = 0; i < r; i++) {
		string line;
		getline(cin, line);
		istringstream record(line);
		string s;
		vector<pair<string, int> > vstr;
		record >> s;
		int t;
		record >> t;
		for (int i = 0; i < t; i++) {
			string s1;
			record >> s1;
			vector<string> vl;
			SplitString(s1, vl, ':');
			int t1 = 0;
			if ((vl.size() > 1))
				t1 += vl[1][0] - 48;
			else
				t1 = -1;
			vstr.push_back(pair<string,int>(vl[0],t1));
		}
		R[s] = vstr;
	}
	int u;
	cin >> u;getchar();
	map<string, vector<string> > U;
	for (int i = 0; i < u; i++) {
		string line;
		getline(cin, line);
		istringstream record(line);
		string s;
		record >> s;
		vector<string> vstr;
		int t;
		record >> t;
		for (int i = 0; i < t; i++) {
			string s1;
			record >> s1;
			vstr.push_back(s1);
		}
		
		U[s] = vstr;
	}
	int q;
	cin >> q;getchar();
	for (int i = 0; i < q; i++) {
		string line;int b = -2;
		getline(cin, line);
		istringstream record1(line);
		string name;
		record1 >> name;
		string s;
		record1 >> s;
		vector<string> v1;
		SplitString(s, v1, ':');
		if (v1.size()>1) {
			int level = v1[1][0] - 48;
			vector<string> ::iterator ite = U[name].begin();	
			for (ite; ite != U[name].end(); ite++) {
				vector<pair<string, int> > ::iterator ite1 = R[*ite].begin();
				for (ite1; ite1 != R[*ite].end(); ite1++) {
					if (ite1->first == v1[0]) {
						if (ite1->second >= level)
							b = -1;
					}
				}
			}
		}
		else {
			int level = -1;
			vector<string> ::iterator ite = U[name].begin();
			for (ite; ite != U[name].end(); ite++) {
				vector<pair<string, int> >::iterator ite1 = R[*ite].begin();
				for (ite1; ite1 != R[*ite].end(); ite1++) {
					if (ite1->first == v1[0]) {
						if (ite1->second == level)
							b = -1;
						else
							b = ite1->second;
					}
				}
			}
			
		}
		if (b == -2)
			cout << "false" << endl;
		else if (b == -1)
			cout << "true" << endl;
		else
			cout << b << endl;

	}
//	system("PAUSE");
	return 0;
}
