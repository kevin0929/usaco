/*
ID: Kevin Ma [tn781922]
TASK: barn1
LANG: C++    
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ofstream fout("barn1.out");
	ifstream fin("barn1.in");
    
    int m, s, c, sum = 0;
    fin >> m >> s >> c;
    if(m >= c)
    {
        fout << c << "\n";
        return 0;
    }
    int l[c];
    for(int i=0;i<c;i++) fin >> l[i];
    sort(l, l+c);
    for(int j=0;j<c-1;j++) l[j] = l[j+1] - l[j];
    sort(l, l+c-1);
    for(int i=0;i<c-m;i++)
        sum = sum + l[i];
    sum = sum + m;
    fout << sum << "\n";
    return 0;
}