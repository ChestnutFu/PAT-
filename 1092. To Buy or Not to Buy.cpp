//1092  
#include<iostream>  
#include<string>  
using namespace std;
int main()
{
	string shop, eva;
	cin >> shop >> eva;
	int s[265] = { 0 };//count the shop's beads  
	int e[265] = { 0 };//count Eva's beads  
	for (int i = 0; i<shop.size(); ++i)
		++s[shop[i]];
	for (int i = 0; i<eva.size(); ++i)
		++e[eva[i]];
	int count = 0;//the number of missing beads  
	for (int i = 0; i<256; ++i)
		if (s[i]<e[i])
			count += e[i] - s[i];
	if (count == 0)
		cout << "Yes " << shop.size() - eva.size();
	else
		cout << "No " << count;
	return 0;
}

