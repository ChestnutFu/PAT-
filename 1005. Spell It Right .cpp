#include<stdio.h>
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int getsum(string str)
{
	int sum = 0;
	int emp;
	int len = str.length();
	for (int i = 0; i < len;i++)
	{
		emp = str[i] - '0';
		sum = sum + emp;
	}
	return sum;
}
void printsum(int sum)
{
	int r;
	int x;
	stack <int> S;
	if (sum == 0)
		printf("zero");
	while (sum != 0)
	{
		r = sum % 10;
		sum /= 10;
		S.push(r);
	}
	while (S.size() != 0)
	{
		x = S.top();
		S.pop();
		switch (x)
		{
		case 0:
			printf("zero");
			break;
		case 1:
			printf("one");
			break;
		case 2:
			printf("two");
			break;
		case 3:
			printf("three");
			break;
		case 4:
			printf("four");
			break;
		case 5:
			printf("five");
			break;
		case 6:
			printf("six");
			break;
		case 7:
			printf("seven");
			break;
		case 8:
			printf("eight");
			break;
		case 9:
			printf("nine");
			break;
		default:
			break;
		}
		if (S.size() != 0)
			printf(" ");
	}
}
int main(){
	string str;
	while (getline(cin,str))
	{
		int sum;
		sum = getsum(str);
		printsum(sum);
	}
	return 0;
}
