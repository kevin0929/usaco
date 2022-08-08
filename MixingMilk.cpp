/*
ID: Kevin Ma [tn781922]
TASK: milk
LANG: C++    
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ofstream fout("milk.out");
    ifstream fin("milk.in");
    
    int n, m, sum = 0;
    fin >> n >> m;
    vector<pair<int, int> > ans;
    for(int i=0;i<m;i++)
    {
        int unit, amount;
        fin >> unit >> amount;
        ans.push_back({unit, amount});
    }
    sort(ans.begin(), ans.end());
    for(int j=0;j<m;j++)
    {
        if(n > 0)
        {
            if(n - ans[j].second > 0)
            {
                sum = sum + ans[j].second*ans[j].first;
                n = n - ans[j].second;
            }
            else
            {
                sum = sum + n*ans[j].first;
                n = 0; 
            }
        }
        else break;
    }
    fout << sum << "\n";
    return 0;
}
