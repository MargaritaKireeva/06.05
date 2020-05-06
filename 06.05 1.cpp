#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

int main()
{
	stack<char> st;
	stack<char> st2;
	ifstream in("input.txt");
	ofstream out("output.txt");
	char x;
	while (in.get(x))
	{
		st.push(x);
	}
	int k = 0;
	while (!st.empty())
	{
		int s = 0;
		do
		{
			if (st.top() == '#')
			{
				k++;
				st.pop();
			}
			if (st.empty())
				break;
		} while (st.top() == '#');
		if (k == 0 && !st.empty())
		{
			st2.push(st.top());
			st.pop();
		}
		else
			if (!st.empty())
			{
				for (int i = 1; i <= k; i++)
					if (st.top() != '#')
					{
						st.pop();
						s++;
					}
			}
		k -= s;
	}
	while (!st2.empty())
	{
		out.put(st2.top());
		st2.pop();
	}
	return 0;
}