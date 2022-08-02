/*
ID: Kevin Ma [tn781922]
TASK: friday
LANG: C++    
*/

#include<bits/stdc++.h>
using namespace std;

bool checkforleapyear(int year);

int main()
{
	ofstream fout("friday.out");
	ifstream fin("friday.in");
	
	int n, year = 1900, m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, d[8] = {}, day = 1, month = 1;
	fin >> n;
	while(year < 1900+n)
	{
		bool leapyear = false;
		if(checkforleapyear(year)) leapyear = true;
		
		if(leapyear) m[2] = 29;
		else m[2] = 28;
		
		d[day]++;
		day = day + ((m[month] - 13) + 13) % 7;
		if(day > 7) day = day % 7;
		month++; 
		if(month == 13) 
		{
			year++;
			month = 1;
		}
	}
	for(int i=1;i<=6;i++)
		fout << d[i] << " ";
	fout << d[7] << "\n";
}

bool checkforleapyear(int year)
{
	if(year % 4 == 0)
	{
		if(year % 400 == 0) return true;
		else if(year % 100 == 0) return false;
		else return true;
	}
	return false;
}
