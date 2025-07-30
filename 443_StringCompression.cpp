#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int ans=0;
        int ind=0;
        for(int i=0; i<n; i++){
            int cnt=1;
            int j=i+1;
            while(j<n && chars[j]==chars[i]){
                cnt++;
                j++;
            }
            i=j-1;
            chars[ind++]=chars[i];
            if(cnt==1) ans++;
            else{
                ans++;
                string tmp=to_string(cnt);
                for(auto u:tmp){
                    chars[ind++]=u;
                }
                ans+=tmp.size();
            }
        }
        return ans;
    }
};
int main(){
    Solution ss;
    vector<char>cc;
    cc.push_back('a');
    cc.push_back('a');
    cc.push_back('b');
    cc.push_back('b');
    cc.push_back('c');
    cc.push_back('c');
    cc.push_back('c');
    ss.compress(cc);
}