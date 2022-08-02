/*
ID: Kevin Ma [tn781922]
TASK: milk2
LANG: C++    
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");
	
	int n, begin_time, end_time;
	fin >> n;
	vector<pair<int, int> > cow;
	for(int i=0;i<n;i++)
	{
		fin >> begin_time >> end_time;
		cow.push_back({begin_time, end_time});
	}
	sort(cow.begin(), cow.end());
	
	int max_have_cow_time = cow[0].second - cow[0].first, max_no_cow_time = 0, 
		have_cow_time = cow[0].second - cow[0].first, lower_bound = cow[0].first, upper_bound = cow[0].second, have_no_cow_time = 0;
	for(int j=1;j<n;j++)
	{
		if(cow[j].second > upper_bound)
		{
			if(cow[j].first <= upper_bound)
			{
				if(have_cow_time == 0) have_cow_time = cow[j].second - lower_bound;
				else have_cow_time =  have_cow_time + (cow[j].second - upper_bound);
				upper_bound = cow[j].second;
			}
			else
			{
				have_no_cow_time = cow[j].first - upper_bound;
				if(have_no_cow_time > max_no_cow_time) max_no_cow_time = have_no_cow_time;
				if(have_cow_time > max_have_cow_time) max_have_cow_time = have_cow_time;
				have_cow_time = 0;
				lower_bound = cow[j].first;
				upper_bound = cow[j].second;
			}
		}
		else
			continue;
	}
	fout << max_have_cow_time << " " << max_no_cow_time << "\n";
	/*for(int j=0;j<n;j++)
		cout << cow[j].first << " " << cow[j].second << "\n";*/
	return 0;
}
