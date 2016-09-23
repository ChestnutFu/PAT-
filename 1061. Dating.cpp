#include<stdio.h>
#include<string.h>
using namespace std;
char daysInAWeek[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
int main()
{
	char s1[61], s2[61], s3[61], s4[61];
	while (scanf("%s%s%s%s",&s1,&s2,&s3,&s4)!=EOF)
	{
		int a = 0, b = 0;
		char strsame[2];
		int h = 0;
		/*前两行*/
		while (s1[a]!='\0'&&s2[b]!='\0')
		{
			if (s1[a] == s2[b]&&h==0&&s1[a]>='A'&&s1[a]<='G')
			{
				strsame[h] = s1[a];
				h++;
			}
			else if (s1[a] == s2[b] && h == 1 )
			{
				if ((s1[a] >= '0'&&s1[a] <= '9') || (s1[a] >= 'A'&&s1[a] <= 'N'))
				{
					strsame[h] = s1[a];
					h++;
				}
			}
			if (h == 2)
				break;
			a++;
			b++;
		}
		a = 0; b = 0;
		int k = 0;
		while (s3[a]!='\0'&&s4[b]!='\0')
		{
			if (s3[a] == s4[b])
				if ((s3[a] >= 'a'&&s3[a] <= 'z') || (s3[a] >= 'A'&&s3[a] <= 'Z'))
					break;
			a++;
			b++;
		}
		k = a;
		/*打印weekday*/
		int weekday = strsame[0] - 'A';
		for (int i = 0; i < 3; i++)
			printf("%c", daysInAWeek[weekday][i]);
		printf(" ");
		/*打印小时*/
		if (strsame[1] >= '0'&&strsame[1] <= '9')
			printf("0%d:", strsame[1] - '0');
		else
			printf("%d:", strsame[1] - 'A' + 10);
		if (k < 10)
			printf("0%d\n", k);
		else
			printf("%d\n", k);
	}
	return 0;
}
