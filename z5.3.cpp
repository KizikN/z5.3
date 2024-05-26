#include<iostream>
#include<list>
#include<time.h>

using namespace std;

void Part1();
void Part2();

int main()
{
	//=========
	int i = 0;
	//=========
	if (i)
		Part1(); // z2.4
	else
		Part2(); // z2.6

	return 0;
}

void Part1()
{
	srand(time(NULL));
	list<char>L1, L2;
	for (int i = 0; i < 5; i++)
		L1.push_back(65 + rand() % 25);
	for (int i = 0; i < 6; i++)
		L2.push_back(65 + rand() % 25);

	list<char>::iterator p = L1.begin();
	list<char> L;
	L.push_back(*p);

	for (; p != L1.end(); p++)
		cout << *p << " ";
	cout << endl;
	for (p = L2.begin(); p != L2.end(); p++)
		cout << *p << " ";
	cout << endl;

	for (p = L1.begin(); p != L1.end(); p++)
	{
		for (list<char>::iterator k = L.begin(); k != L.end(); k++)
		{
			if (*k == *p)
				break;
			if (++k == L.end())
			{
				k--;
				L.push_back(*p);
				break;
			}
			else
				k--;
		}
	}
	for (p = L2.begin(); p != L2.end(); p++)
	{
		for (list<char>::iterator k = L.begin(); k != L.end(); k++)
		{
			if (*k == *p)
				break;
			if (++k == L.end())
			{
				k--;
				L.push_back(*p);
				break;
			}
			else
				k--;
		}
	}

	for (list<char>::iterator k = L.begin(); k != L.end(); k++)
		cout << *k << " ";
	cout << endl;
}

void Part2()
{
	srand(time(NULL));
	int n;
	cout << "n = ";
	cin >> n;
	n *= 2;
	list<int> A;
	for(int i = 0; i < n; i++)
		A.push_back(rand() % 100);
	list<int>::iterator e = A.begin();
	list<int>::iterator b = A.begin();
	for (; e != A.end(); e++)
		cout << *e << " ";
	cout << endl;
	e--;
	n /= 2;

	int S = 1;
	for (int i = 0; i < n; i++)
	{
		S *= *b - *e;
		if (i != n  - 1)
		{
			b++;
			b++;
			e--;
			e--;
		}
	}
	cout << S << endl;
}