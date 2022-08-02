/*
ID: Kevin Ma [tn781922]
TASK: transform
LANG: C++    
*/

#include<bits/stdc++.h>
using namespace std;

int n;
bool condition1(char g1[10][10], char g2[10][10]);
bool condition2(char g1[10][10], char g2[10][10]);
bool condition3(char g1[10][10], char g2[10][10]);
bool condition4(char g1[10][10], char g2[10][10]);
bool condition5(char g1[10][10], char g2[10][10]);
bool condition6(char g1[10][10], char g2[10][10]);

int main()
{
	ofstream fout("transform.out");
	ifstream fin("transform.in");
	
	fin >> n;
	char g1[10][10], g2[10][10];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fin >> g1[i][j];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			fin >> g2[i][j];
			
	if(condition1(g1, g2)) 
	{
		fout << "1" << "\n";
		return 0;
	}
			
	if(condition2(g1, g2))
	{
		fout << "2" << "\n";
		return 0;
	}
	
	if(condition3(g1, g2))
	{
		fout << "3" << "\n";
		return 0;
    }

	if(condition4(g1, g2))
	{
		fout << "4" << "\n";
		return 0;
	}
	
	if(condition5(g1, g2))
	{
		fout << "5" << "\n";
		return 0;
	}
	
	if(condition6(g1, g2))
	{
		fout << "6" << "\n";
		return 0;
	}
	fout << "7" << "\n";
	return 0;
}

bool condition1(char g1[10][10], char g2[10][10])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(g1[i][j] != g2[j][n-1-i]) return false;
	return true;
}

bool condition2(char g1[10][10], char g2[10][10])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(g1[i][j] != g2[n-1-i][n-1-j]) return false;
	return true;
}

bool condition3(char g1[10][10], char g2[10][10])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(g1[i][j] != g2[n-1-j][i]) return false;
	return true;
}

bool condition4(char g1[10][10], char g2[10][10])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(g1[i][j] != g2[i][n-1-j]) return false;
	return true;
}

bool condition5(char g1[10][10], char g2[10][10])
{
	char tmp[10][10];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			tmp[i][j] = g1[i][n-1-j];	//reflection
	char tmp90[10][10];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			tmp90[i][j] = tmp[j][n-1-i];
	if(condition6(tmp90, g2)) return true;
	char tmp180[10][10];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			tmp180[i][j] = tmp[n-1-i][n-1-j];
	if(condition6(tmp180, g2)) return true;
	char tmp270[10][10];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			tmp270[i][j] = tmp[n-1-j][i];
	if(condition6(tmp270, g2)) return true;
	
	return false;
}

bool condition6(char g1[10][10], char g2[10][10])
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(g1[i][j] != g2[i][j]) return false;
	return true;
}
