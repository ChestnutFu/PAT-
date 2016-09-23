#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int n, k;
struct Call
{
	string a, b;
	int t;
};
struct node
{
	int weight;
	int root;
};
struct Gang
{
	int maxw, head, sumw, num;
	Gang(){ head = -1; num = 0; sumw = 0; maxw = -1; }
};
vector<Call>calls;
set<string>name;
map<string, int>name2id;
map<int, string>id2name;
vector<node>p;
void compress(int top,int a)
{
	if (top != p[a].root)
	{
		compress(top, p[a].root);
		p[a].root = top;
	}
}
int findRoot(int a)
{
	if (p[a].root != a)
	{
		int top = findRoot(p[a].root);
		compress(top, a);
	}
	return p[a].root;
}
void Union(int v,int u)
{
	int a = findRoot(v);
	int b = findRoot(u);
	p[a].root = b;
}

int main()
{
	while (scanf("%d%d", &n, &k) != EOF)
	{
		calls.clear();
		calls.resize(n);
		name.clear();
		for (int i = 0; i < n;i++)
		{
			string a, b;
			int weight;
			cin >> a >> b >> weight;
			calls[i].a = a;
			calls[i].b = b;
			calls[i].t = weight;
			name.insert(a);
			name.insert(b);
		}
		int reanlen = name.size();
		name2id.clear();
		id2name.clear();
		set<string>::iterator it;
		int id = 0;
		for (it = name.begin(); it != name.end(); it++, id++)
		{
			name2id[*it] = id; id2name[id] = *it;
		}
		p.clear();
		p.resize(reanlen);
		for (int i = 0; i < reanlen; i++)
		{
			p[i].weight = 0;
			p[i].root = i;
		}
		for (int i = 0; i < n; i++)
		{
			int v = name2id[calls[i].a];
			int u = name2id[calls[i].b];
			p[v].weight += calls[i].t;
			p[u].weight += calls[i].t;
			Union(v, u);
		}
		map<int, Gang>allSet;
		map<int, Gang>::iterator Git;
		for (int i = 0; i < reanlen; i++)
		{
			int top = findRoot(i);
			Git = allSet.find(top);
			if (Git != allSet.end())
			{
				if (p[i].weight > allSet[top].maxw)
				{
					allSet[top].head = i;
					allSet[top].maxw = p[i].weight;
				}
				allSet[top].sumw += p[i].weight;
				allSet[top].num++;
			}
			else
			{
				Gang tmp;
				tmp.head = i;
				tmp.maxw = p[i].weight;
				tmp.sumw = p[i].weight;
				tmp.num = 1;
				allSet[top] = tmp;
			}
		}
		vector<Gang>gang;
		for (Git = allSet.begin(); Git != allSet.end(); Git++)
		{
			if (Git->second.sumw > 2 * k&&Git->second.num > 2)
				gang.push_back(Git->second);
		}
		vector<pair<string, int>> head;
		for (int i = 0; i < gang.size(); ++i)
			head.push_back(make_pair(id2name[gang[i].head], gang[i].num));
		sort(head.begin(), head.end());
		printf("%d\n", head.size());
		for (int i = 0; i < head.size(); ++i)
			cout << head[i].first << " " << head[i].second << endl;
	}
	return 0;
}
