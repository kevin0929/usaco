/*
ID: Kevin Ma [tn781922]
TASK: gift1
LANG: C++    
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	int np, m, money, peoplenumber, np2;
	string p, p2;
	fin >> np;
	np2 = np;
	map<string, int> ans;
	vector<string> name;
	for(int i=0;i<np;i++)
	{
		fin >> p;
		ans[p] = 0;
		name.push_back(p);
	}
	while(np2--)
	{
		fin >> p;
		fin >> money >> peoplenumber;
		if(peoplenumber == 0) continue;
		int get;
		get = money / peoplenumber;
		ans[p] = ans[p] - money + (money % peoplenumber);
		while(peoplenumber--)
		{
			fin >> p2;
			ans[p2] = ans[p2] + get;
		}
	}
	for(int i=0;i<np;i++)
		fout << name[i] << " " << ans[name[i]] << "\n";
	return 0;
}
