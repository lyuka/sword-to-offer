#include <iostream>
#include <string>

using namespace std;

void replace_blankspace_01(string & s)
{
	int s_len = s.length();
	//string tmp_s = new 
	for (int i = 0; i < s_len; i++)
	{
		if (s[i] == ' ')
		{
			s += s[s_len-2];
			s += s[s_len-1];
			for (int j = s_len-3; j > i; j--)
			{
				s[j+2] = s[j];
			}
			s[i] = '%';
			s[i+1] = '2';
			s[i+2] = '0';
			s_len += 2;
		}
	}

}

void replace_blankspace_02(string & s)
{
	//if (s == NULL)
	//	return;

	int s_len = s.length();
	int blank_num = 0;
	for (int i = 0; i < s_len; i++)
	{
		if (s[i] == ' ')
			blank_num += 1;
	}
	int s_len_new = s_len + 2 * blank_num;

	if (s_len_new == s_len)
		return;

	s.resize(s_len_new);
	while (s_len_new >= 0 && s_len_new > s_len)
	{
		if (s[s_len] == ' ')
		{
			s[s_len_new--] = '0';
			s[s_len_new--] = '2';
			s[s_len_new--] = '%';
		}
		else
			s[s_len_new--] = s[s_len];
		s_len--;
	}
}

int main()
{
	string s1 = "We are happy.";
	string s2 = "Wearehappy.";
	string s3 = " ";
	string s4 = "";

	replace_blankspace_02(s1);
	cout << s1 << endl;

	replace_blankspace_02(s2);
	cout << s2 << endl;

	replace_blankspace_02(s3);
	cout << s3 << endl;

	replace_blankspace_02(s4);
	cout << s4 << endl;
	return 0;
}