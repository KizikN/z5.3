#include<iostream>
#include<list>
#include<forward_list>
#include<time.h>

using namespace std;

void Part1();
void Part2();

int main()
{
	//=========
	int i = 1;
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
	forward_list<char>L1, L2;
	for (int i = 0; i < 5; i++)
		L1.push_front(65 + rand() % 25);
	for (int i = 0; i < 6; i++)
		L2.push_front(65 + rand() % 25);

	forward_list<char>::iterator p = L1.begin();
	forward_list<char> L;
	L.push_front(*p);

	for (; p != L1.end(); p++)
		cout << *p << " ";
	cout << endl;
	for (p = L2.begin(); p != L2.end(); p++)
		cout << *p << " ";
	cout << endl;

	for (p = L1.begin(); p != L1.end(); p++)
	{
		for (forward_list<char>::iterator k = L.begin(); k != L.end();)
		{
			if (*k == *p)
				break;
			if (++k == L.end())
			{
				L.push_front(*p);
				break;
			}
		}
	}

	for (p = L2.begin(); p != L2.end(); p++)
	{
		for (forward_list<char>::iterator k = L.begin(); k != L.end();)
		{
			if (*k == *p)
				break;
			if (++k == L.end())
			{
				L.push_front(*p);
				break;
			}
		}
	}

	for (forward_list<char>::iterator k = L.begin(); k != L.end(); k++)
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