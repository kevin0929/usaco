/*
ID: Kevin Ma [tn781922]
TASK: namenum
LANG: C++    
*/
#include<bits/stdc++.h>
using namespace std;

map<char, int> m;
void init();
int main()
{
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
	//ifstream fin1("dict.txt");
	
	string s1, s2;
	cin >> s1;
	int len1 = s1.length();
	bool flag, yes = false;
	init();
	freopen("dict.txt", "r", stdin);
	while(cin >> s2)
	{
		flag = true;
		int len2 = s2.length();
		if(len1 == len2)
		{
			for(int i=0;i<len1;i++)
			{
				if((s1[i]-'0') == m[s2[i]]) continue;
				else
				{
					flag = false;
					break;
				}
			}
			if(flag) {
				cout << s2 << "\n";
				yes = true;
			}
		}
	}
	if(!yes) cout << "NONE" << "\n";
	return 0;
}

void init()
{
	m['A']=2;m['B']=2;m['C']=2;
	m['D']=3;m['E']=3;m['F']=3;
	m['G']=4;m['H']=4;m['I']=4;
	m['J']=5;m['K']=5;m['L']=5;
	m['M']=6;m['N']=6;m['O']=6;
	m['P']=7;m['R']=7;m['S']=7;
	m['T']=8;m['U']=8;m['V']=8;
	m['W']=9;m['X']=9;m['Y']=9;
}
