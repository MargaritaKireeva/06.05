#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int main()
{
	queue<char> st;
	ifstream in("input.txt");
	ofstream out("output.txt");
	char x;
	int N;
	in >> N;
	while (in >> x)
	{
		if (isdigit(x))
			if (st.size() != N)
				st.push(x);
			else
			{
				st.pop();
				st.push(x);
			}
		if (x == '*')
		{
			if (!st.empty())
			{
				out << st.front();
				st.pop();
			}
			else out << x;
		}

	}
	return 0;
}
