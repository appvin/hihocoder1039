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
	if (s == r)
	{
		return r;
	}
	else
	{
		return em(r);
	}
}

int main()
{
	int n;
	string abc = "ABC";
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		string s;
		cin >> s;
		if (s == "")
		{
			cout << "1" << endl;
		}
		else
		{
			string ss = s;
			int l = ss.size() + 1;
			int min = ss.size();
			for (int j = 0; j<ss.size(); j++)
			{
				for (int k = 0; k < 3; k++)
				{
					s = ss;
					string p = "";
					p += abc[k];
					s.insert(j, p);
					if (min > em(s).size())
					{
						min = em(s).size();
					}
				}
			}
			cout << l - min << endl;
		}

	}
}