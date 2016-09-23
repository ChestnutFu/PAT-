#include<iostream>  
#include<algorithm>  
#include<cstring>  
using namespace std;

struct Person{
	char name[9];
	int age;
	int net_worth;
}*person;

bool person_compare(const Person &p1, const Person &p2)
{
	if (p1.net_worth != p2.net_worth)
		return p1.net_worth > p2.net_worth;
	if (p1.age != p2.age)
		return p1.age < p2.age;
	return strcmp(p1.name, p2.name)<0;
}

int main()
{
	int N, K;
	int output, amin, amax, count;
	scanf("%d%d", &N, &K);
	person = new Person[N];

	for (int i = 0; i < N; ++i)
	{
		scanf("%s%d%d", &person[i].name, &person[i].age, &person[i].net_worth);
	}
	sort(person, person + N, person_compare);

	for (int i = 0; i < K; ++i)
	{
		scanf("%d%d%d", &output, &amin, &amax);
		cout << "Case #" << i + 1 << ":" << endl;
		count = 0;
		for (int j = 0; j < N; ++j)
		{
			if (count >= output)
				break;
			if (person[j].age >= amin && person[j].age <= amax)
			{
				++count;
				printf("%s %d %d\n", person[j].name, person[j].age, person[j].net_worth);
			}
		}
		if (count == 0)
			printf("%s\n", "None");
	}
	return 0;
}
