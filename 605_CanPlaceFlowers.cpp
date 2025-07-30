#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();
        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 0) {
                bool leftEmpty = (i == 0 || flowerbed[i - 1] == 0);
                bool rightEmpty = (i == size - 1 || flowerbed[i + 1] == 0);
                
                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }
        return count>=n;
    }
};