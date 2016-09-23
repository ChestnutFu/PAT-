#define _CRT_SECURE_NO_WARNINGS
#include<iostream>  
#include<vector>  
#include<string>  
#include<map>  
#include<algorithm>  
using namespace std;

struct record
{
	int time;//the time of this record  
	int in;//the status of the plate  
	record(int t, int i) :time(t), in(i){}
	bool operator <(const record &r)const
	{
		return time<r.time;
	}
};

int name2id(string str)
{//transform the plate's name to a id number  
	int num = 0;
	for (int i = 0; i<7; ++i)
	{
		if (str[i] >= '0'&&str[i] <= '9')
			num = num * 36 + str[i] - '0';
		else
			num = num * 36 + str[i] - 'A' + 10;
	}
	return num;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	map<int, int>id2idx;//the id of plate to its index  
	vector<string>platename;//the name of each plate  
	vector<vector<record>>all;//all record  
	for (int i = 0; i<n; ++i)
	{
		string name;
		char status[5];
		int hour, min, sec;
		cin >> name;
		scanf("%d:%d:%d %s", &hour, &min, &sec, status);
		record r(hour * 3600 + min * 60 + sec, status[0] == 'i' ? 1 : 0);
		int id = name2id(name);
		if (id2idx.count(id))
			all[id2idx[id]].push_back(r);
		else
		{//insert it of it is a new plate  
			id2idx.insert(pair<int, int>(id, all.size()));
			platename.push_back(name);
			vector<record>rec;
			rec.push_back(r);
			all.push_back(rec);
		}
	}
	for (int i = 0; i<all.size(); ++i)
		sort(all[i].begin(), all[i].end());
	vector<int>cur;//current index  
	cur.assign(all.size(), 0);
	vector<int>period;
	period.assign(all.size(), 0);
	for (int i = 0; i<k; ++i)
	{
		int hour, min, sec;
		scanf("%d:%d:%d", &hour, &min, &sec);
		int t = hour * 3600 + min * 60 + sec;
		int count = 0;//the number of cars on plate at this time  
		for (int j = 0; j<all.size(); ++j)
		{
			while (1)
			{
				//if this time is earlier than the earlist record of this plate  
				//or later than the last record of this plate  
				if ((cur[j] == 0 && t<all[j][0].time) || cur[j] >= all[j].size() - 1)
					break;
				if (t >= all[j][cur[j]].time && t<all[j][cur[j] + 1].time)
				{//if this time is just between the current record and next recod  
					if (all[j][cur[j]].in && !all[j][cur[j] + 1].in)
						++count;
					break;
				}
				//calculate the period of each plate  
				if (all[j][cur[j]].in && !all[j][cur[j] + 1].in)
					period[j] += all[j][cur[j] + 1].time - all[j][cur[j]].time;
				++cur[j];
			}
		}
		printf("%d\n", count);
	}
	int maxperiod = 0;
	for (int i = 0; i<all.size(); ++i)
	{
		while (cur[i]<all[i].size() - 1)
		{//calculate the period of the rest recods  
			if (all[i][cur[i]].in && !all[i][cur[i] + 1].in)
				period[i] += all[i][cur[i] + 1].time - all[i][cur[i]].time;
			++cur[i];
		}
		if (period[i]>maxperiod)
			maxperiod = period[i];
	}
	for (int i = 0; i<all.size(); ++i)
		if (maxperiod == period[i])
			cout << platename[i] << ' ';
	printf("%02d:%02d:%02d", maxperiod / 3600, (maxperiod % 3600) / 60, maxperiod % 60);
	return 0;
}




