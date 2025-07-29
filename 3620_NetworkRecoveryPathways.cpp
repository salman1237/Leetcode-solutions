#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pi pair<ll, ll>
int n;
class Solution
{
public:
    bool dijkstra(vector<pair<ll, ll>> adj[],ll mid,ll k)
    {
        vector<ll> dist(n + 5, LONG_LONG_MAX);
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        while (!pq.empty())
        {
            ll no = pq.top().second;
            ll di = pq.top().first;
            pq.pop();
            if (dist[no] < di)
                continue;
            for (auto u : adj[no])
            {
                if(u.second<mid) continue;
                ll nd = u.second + di;
                if (nd < dist[u.first])
                {
                    dist[u.first] = nd;
                    pq.push({nd, u.first});
                }
            }
        }
        return dist[n - 1]<=k;
    }
    int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online, long long k)
    {
        n = online.size();
        vector<pair<ll, ll>> adj[n + 2];
        for (auto x : edges)
        {
            ll u = x[0];
            ll v = x[1];
            ll w = x[2];
            if (online[u] && online[v])
                adj[u].pb({v, w});
        }
        ll lo = 0, hi = 1e9;
        ll ans = -1;
        while (lo <= hi)
        {
            ll mid = (lo + hi) >> 1;
            if (dijkstra(adj,mid,k))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return ans;
    }
};


//changed for testing purpose