#include <iostream>
#include <cmath>
#include <string>

using namespace std;


//integer Hex conversion function declare(m Hex convert to Decimal)
long Hex(string num, int n);

int main()
{
	string num;
	int n;
	cin >> num >> n;
	cout << Hex(num, n);
	return 0;
}

//function define and actualize

long Hex(string num, int n)
{
	long result = 0;
	for (int i = 0; i<num.size(); i++)
	{
		if ('0' <= num[i] && num[i] <= '9')
			result += (num[i] - '0') * pow(n, (num.size() - i - 1));
		else if ('A' <= num[i] && num[i] <= 'Z')
			result += (num[i] - 'A' + 10) * pow(n, (num.size() - i - 1));
		else if ('a' <= num[i] && num[i] <= 'z')
			result += (num[i] - 'a' + 10) * pow(n, (num.size() - i - 1));
	}
	return result;
}
