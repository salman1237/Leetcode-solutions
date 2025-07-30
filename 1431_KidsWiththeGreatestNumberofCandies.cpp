#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxCandies = *max_element(candies.begin(), candies.end());
        for (int candy : candies) {
            if (candy + extraCandies >= maxCandies) {
                result.pb(true);
            } else {
                result.pb(false);
            }
        }
        return result;
    }
};