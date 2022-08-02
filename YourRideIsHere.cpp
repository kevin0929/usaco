/*
ID: Kevin Ma [tn781922]
TASK: ride
LANG: C++    
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string s1, s2;
	fin >> s1 >> s2;
	int sum1 = 1, sum2 = 1;
	for(int i=0;i<s1.length();i++)
		sum1 = (sum1*(s1[i] - 'A' + 1)) % 47;
	for(int j=0;j<s2.length();j++)
		sum2 = (sum2*(s2[j] - 'A' + 1)) % 47;
	if(sum1%47 == sum2%47) fout << "GO" << "\n";
	else fout << "STAY" << "\n";
	
	return 0;
} 
