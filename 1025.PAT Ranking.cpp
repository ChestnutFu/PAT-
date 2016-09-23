#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node
{
	string number;
	int score;
	int localtion;
	int final_rank;
	int local_rank;
};
bool compare(node a,node b)
{
	if (a.score > b.score)
		return true;
	else if (a.score == b.score&&a.number < b.number)
		return true;
	else
		return false;
}
int main()
{
	int N;//(<=100), the number of test locations
	while (cin >> N)
	{
		vector<node>List;
		int j;
		for (j = 1; j <= N;j++)
		{
			int K, i;
			cin >> K;
			vector<node>l;
			for (i = 0; i < K; i++)
			{
				string s;
				int score_number;
				cin >> s;
				scanf("%d", &score_number);
				node *p = new node();
				p->number = s;
				p->score = score_number;
				p->localtion = j;
				l.push_back(*p);
			}
			sort(l.begin(), l.end(), compare);

			for (int i = 0; i < l.size(); i++)
			{
				if (i>0 && l[i].score == l[i - 1].score)
					l[i].local_rank = l[i - 1].local_rank;
				else
					l[i].local_rank = i + 1;
				List.push_back(l[i]);
			}
		}
		sort(List.begin(), List.end(), compare);

		for (int i = 0; i < List.size(); i++)
		{
			if (i>0 && List[i].score == List[i - 1].score)
				List[i].final_rank = List[i - 1].final_rank;
			else
				List[i].final_rank = i + 1;
		}
		cout << List.size() << endl;
		for (int i = 0; i < List.size(); i++)
		{
			cout << List[i].number << " " << List[i].final_rank << " " << List[i].localtion << " " << List[i].local_rank << endl;
		}
	}
	return 0;
}
