#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        string ans = "";
        int x = min(str1.size(), str2.size());
        for (int i = x; i >= 0; i--)
        {
            string gg = str1.substr(0, i);
            if (str1.size() % gg.size() == 0 && str2.size() % gg.size() == 0)
            {
                string tmp1, tmp2;
                while (tmp1.size() != str1.size())
                    tmp1 += gg;
                while (tmp2.size() != str2.size())
                    tmp2 += gg;
                if (tmp1 == str1 && tmp2 == str2)
                {
                    ans = gg;
                    break;
                }
            }
        }
        return ans;
    }
};