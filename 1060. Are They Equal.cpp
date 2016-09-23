#include<iostream>  
#include<string>
using namespace std;
void getmachine(int*e, string *str, int N)
{
	int dot = (*str).find('.');
	if (dot != -1)
	{
		str->erase(dot, 1);
		(*e) = dot;
	}
	else(*e) = str->size();
	str->insert(0, "0.");
	dot = 2;
	while (str->size() > dot && (*str)[dot] == '0')
		dot++;
	dot -= 2;
	str->erase(2, dot);
	(*e) -= dot;
	dot = str->size();
	if (dot == 2)(*e) = 0;
	N += 2;
	if (dot >  N)str->erase(N, dot - N + 1);
	else str->insert(dot, N - dot, '0');
}
int main()
{
	string str[2];
	int e[2];
	int N;
	cin >> N >> str[0] >> str[1];
	getmachine(&e[0], &str[0], N);
	getmachine(&e[1], &str[1], N);
	if (e[0] == e[1] && str[0] == str[1])cout << "YES " << str[0] << "*10^" << e[0] << endl;
	else cout << "NO " << str[0] << "*10^" << e[0] << " " << str[1] << "*10^" << e[1] << endl;
	system("pause");
	return 0;
}
