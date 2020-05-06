#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

stack<char> wagons;
stack<char> deadlock1;
stack<char> deadlock2;

void send(char x, int i)
{
	int k = 0;
	while (x != wagons.top())
	{

		switch (i)
		{
		case 1:
			deadlock2.push(wagons.top());
			break;
		case 2:
			deadlock1.push(wagons.top());
			break;
		}
		wagons.pop();
		k++;
	}
	if (x == wagons.top())
	{
		switch (i)
		{
		case 1:
			deadlock1.push(x);
			break;
		case 2:
			deadlock2.push(x);
			break;
		}
		wagons.pop();
	}

	for (int j = 1; j <= k; j++)
	{
		switch (i)
		{
		case 1:
			wagons.push(deadlock2.top());
			deadlock2.pop();
			break;
		case 2:
			wagons.push(deadlock1.top());
			deadlock1.pop();
			break;
		}
	}
}

void print(stack <char> w, stack <char> d1, stack <char> d2)
{
	setlocale(LC_ALL, "Russian");
	stack <char> ww;
	while (!w.empty())
	{
		ww.push(w.top());
		w.pop();
	}
	cout << "Вагоны: ";
	while (!ww.empty())
	{
		cout << ww.top() << ' ';
		ww.pop();
	}
	cout << endl << "Тупик 1: ";
	while (!d1.empty())
	{
		cout << d1.top() << ' ';
		d1.pop();
	}
	cout << endl << "Тупик 2: ";
	while (!d2.empty())
	{
		cout << d2.top() << ' ';
		d2.pop();
	}
	cout << endl;
}

int main()
{

	ifstream in("input.txt");
	ofstream out("output.txt");
	char x;
	while (in >> x)
	{
		wagons.push(x);
	}
	print(wagons, deadlock1, deadlock2);
	send('A', 1);
	print(wagons, deadlock1, deadlock2);
	send('C', 2);
	print(wagons, deadlock1, deadlock2);
	send('D', 2);
	print(wagons, deadlock1, deadlock2);
	return 0;
}
