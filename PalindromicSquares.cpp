/*
ID: Kevin Ma [tn781922]
TASK: palsquare
LANG: C++    
*/
#include<bits/stdc++.h>
using namespace std;

int b;
string transfer(int n);
bool p(string s);

int main()
{
    ofstream fout("palsquare.out");
	ifstream fin("palsquare.in");
    
    fin >> b;
    string s;
    pair<int, int> ans[300];
    for(int i=0;i<300;i++)
    {
        ans[i].first = i+1;
        ans[i].second = (i+1)*(i+1);
    }
    for(int j=0;j<300;j++)
    {
    	s = transfer(ans[j].second);
    	if(p(s))
    		fout << transfer(ans[j].first) << " " << transfer(ans[j].second) << "\n";
	}
}

string transfer(int n)
{
  string s1 = "", s2 = "";
   char tmp;
   while(n > 0)
   {
    if(n % b >= 10)
    {
        tmp = 'A' + (n%b) - 10;
        s1 = s1 + tmp;
        n = n / b;
    }
    else
    {
        tmp = '0' + (n%b);
        s1 = s1 + tmp;
        n = n / b;
    }
    //cout << tmp;
   }
   for(int i=s1.length()-1;i>=0;i--)
   	s2 = s2 + s1[i];
   return s2;
}

bool p(string s)
{
	int len = s.length();
	bool flag = true;
	for(int i=0;i<len/2;i++)
		if(s[i] != s[len-1-i]) 
		{
			flag = false;
			break;
		}
	return flag;
}