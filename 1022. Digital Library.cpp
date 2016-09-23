#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<sstream>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		map<string, std::vector<string>>QueryMap[5];

		while (n--)
		{
			getchar();
			string id, title, author, keyWord, publisher, year;
			getline(cin, id);
			getline(cin, title); getline(cin, author); getline(cin, keyWord);
			getline(cin, publisher); cin >> year;
			QueryMap[0][title].push_back(id);
			QueryMap[1][author].push_back(id);
			QueryMap[3][publisher].push_back(id);
			QueryMap[4][year].push_back(id);

			istringstream istr(keyWord);
			while (!istr.eof())
			{
				string word;
				istr >> word;
				QueryMap[2][word].push_back(id);
			}
		}

		for (int i = 0; i < 5; i++)
		{
			map<string, std::vector<string>>::iterator it;
			for (it = QueryMap[i].begin(); it != QueryMap[i].end(); it++)
			{
				sort(it->second.begin(), it->second.end());
			}
		}

		int m;
		scanf("%d", &m);
		while (m--)
		{
			int index; string q;
			scanf("%d: ", &index);
			getline(cin, q);
			printf("%d: ", index);
			cout << q << endl;
			index--;
			map<string, std::vector<string>>::iterator it;
			it = QueryMap[index].find(q);
			if (it != QueryMap[index].end())
			{
				std::vector<string> result = QueryMap[index][q];
				for (int i = 0; i < result.size(); i++)
					cout << result[i] << endl;
			}
			else
				printf("Not Found\n");
		}
	}
	return 0;
}
