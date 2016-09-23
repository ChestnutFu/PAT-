#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
	int Galleon;
	int Sickle;
	int Knut;
};
int main()
{
	node a, b;
	scanf("%d.%d.%d", &a.Galleon, &a.Sickle, &a.Knut);
	scanf("%d.%d.%d", &b.Galleon, &b.Sickle, &b.Knut);
	int Knut, Sickle, Galleon;
	int K, S, G;
	K = a.Knut + b.Knut;
	Knut = K % 29;
	S = a.Sickle + b.Sickle + K / 29;
	Sickle = S % 17;
	G = a.Galleon + b.Galleon + S / 17;
	Galleon = G;
	printf("%d.%d.%d\n", Galleon, Sickle, Knut);
	system("pause");
}
