#include <iostream>
#include <unordered_map>
using namespace std;

/*
	isalpha(char c)
	islower()
	isupper()
	isdigit()
	isalnum()ÅÐ¶Ï×Ö·ûÊÇ·ñÊÇ×ÖÄ¸»òÊý×Ö
	tolower()
	toupper()
*/

class Solution {
public:
	bool isPalindrome(string s) {
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= '0'&&s[i] <= '9')continue;
			if (s[i] >= 'A'&&s[i] <= 'Z')s[i] = s[i] | 0b00100000;
		}
		int left = 0;
		int right = s.size() - 1;
		while (left < right)
		{
			while (s[left] < '0' || s[left] > '9'&&s[left] < 'a' || s[left] > 'z')
			{
				left++;
				if (left > right)return true;
			}
			while(s[right] < '0'||s[right] > '9'&&s[right] < 'a'||s[right] > 'z')
				right--;
			if (s[left] != s[right])return false;
			left++;
			right--;
		}
		return true;
	}
};

class Solution {
public:
	bool isPalindrome(string s) {
		
	}
};

int main()
{
	Solution*S= new Solution;
	string s = "race a car";
	cout << S->isPalindrome(s);
	return 0;
}