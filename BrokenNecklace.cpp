/*
ID: Kevin Ma [tn781922]
TASK: beads
LANG: C++    
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	ofstream fout("beads.out");
	ifstream fin("beads.in");
	
	int n, max = 0;
	string s1, s;
	fin >> n >> s1;
	s = s1 + s1;
	for(int i=s1.length() - 1;i>=0;i--)
	{
		int i1 = i, i2 = i + 1, left_cnt = 0, right_cnt = 0;
		char tmp_c1 = 'n', tmp_c2 = 'n';
		while(i1 >= 0)
		{
			if(s[i1] == 'w')
			{
				left_cnt++;
				i1--;
			}
			else
			{
				if(tmp_c1 == 'n')
				{
					tmp_c1 = s[i1];
					left_cnt++;
					i1--;
				}
				else
				{
					if(s[i1] == tmp_c1)
					{
						left_cnt++;
						i1--;
					}
					else
						break;
				}
			}
		}
		if(left_cnt >= n)
		{
			max = left_cnt;
			break;
		}
		while(i2 < s.length() - left_cnt)
		{
			if(s[i2] == 'w')
			{
				right_cnt++;
				i2++;
			}
			else
			{
				if(tmp_c2 == 'n')
				{
					tmp_c2 = s[i2];
					right_cnt++;
					i2++;
				}
				else
				{
					if(s[i2] == tmp_c2)
					{
						right_cnt++;
						i2++;
					}
					else
						break;
				}
			}
		}
		if((left_cnt + right_cnt) > max) max = left_cnt + right_cnt;
	}
	fout << max << "\n";
	
	return 0;
} 
