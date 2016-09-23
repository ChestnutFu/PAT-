#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	string id;
	int inTime;
	int outTime;

	node(string s,int in,int out){
		id = s;
		inTime = in;
		outTime = out;
	}
};
bool cmpin(node a,node b)
{
	return a.inTime < b.inTime;
}
bool cmpout(node a,node b)
{
	return a.outTime > b.outTime;
}
int gettime(int hh,int mm,int ss)
{
	return hh * 3600 + mm * 60 + ss;
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		string id;
		int h1, m1, s1, h2, m2, s2;
		vector<node>person;
		while (n--)
		{
			cin >> id;
			scanf("%d:%d:%d", &h1, &m1, &s1);
			scanf("%d:%d:%d", &h2, &m2, &s2);
			person.push_back(node(id, gettime(h1, m1, s1),gettime(h2,m2,s2)));
		}
		sort(person.begin(), person.end(), cmpin);
		cout << person[0].id << " ";
		sort(person.begin(), person.end(), cmpout);
		cout << person[0].id << endl;
	}
}
