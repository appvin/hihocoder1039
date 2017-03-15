#include <iostream>
#include <string>

using namespace std;

string em(string s)
{
	string r = "";
	for (int i = 0; i<s.size(); i++)
	{
		if (i == 0)
		{
			if (s[i] != s[i + 1])
			{
				r += s[i];
			}
		}
		else if (i == s.size() - 1)
		{
			if (s[i] != s[i - 1])
			{
				r += s[i];
			}
		}
		else
		{
			if ((s[i] != s[i - 1]) && (s[i] != s[i + 1]))
			{
				r += s[i];
			}
		}
	}
	if (em(r) == r)
	{
		return r;
	}
	else
	{
		r = em(r);
		return r;
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		string s;
		cin >> s;
		int l = s.size() + 1;
		s = em(s);
		int min = s.size();
		if (s == "")
		{
			cout << l << endl;
		}
		else
		{
			string ss = s;
			for (int j = 0; j<ss.size(); j++)
			{
				s = ss;
				string p = "";
				p+= s[j];
				s.insert(j, p);
				if (min>em(s).size())
				{
					min = em(s).size();
				}
			}
			cout << l - min << endl;
		}

	}
}