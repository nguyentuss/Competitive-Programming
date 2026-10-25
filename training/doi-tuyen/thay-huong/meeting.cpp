#include<bits/stdc++.h>
using namespace std;
#define pi pair<long long ,pair<long long ,long long >>

long long  dp[2008][2008], trace[2008];
long long  m , n , u , v , k , t , x;
vector<pair<long long ,pair<long long ,long long >>> G[2008];
void DIJKSTRA (int startnode)
{
    priority_queue< pi, vector<pair<long long ,pair<long long ,long long >>> , greater<pi>> pq;
    for (int i = 0 ; i <= n ; i++)
    {
        for (int j = 0 ; j <= k ; j++) dp[i][j] = 1e17;
    }
        pq.push({0,{startnode,0}});
        dp[startnode][0] = 0 ;
        while (pq.size())
        {
            int u = pq.top().second.first , costu = pq.top().second.second , timeu = pq.top().first;
            pq.pop();
            if(timeu != dp[u][costu]) continue;
            for(auto i : G[u])
            {
                long long  v = i.first, costv = costu + i.second.second, timeuv = i.second.first;
                if(costv <= k && dp[v][costv] > dp[u][costu] + timeuv)
                {
                    dp[v][costv] = dp[u][costu] + timeuv;
                    pq.push({dp[v][costv], {v, costv}});
                }
            }
        }
}
long long  o ,p ;
int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("meeting.inp","r",stdin);
	freopen("meeting.out","w",stdout);
    cin >> k >> n >> m ;
    --k;
    for (int i = 1 ; i <= m ; i++) 
    {
        cin >> u >> v >> t >> x;
        G[u].push_back(make_pair(v,make_pair(t,x)));
        G[v].push_back(make_pair(u,make_pair(t,x)));
    }
    cin >> o >> p;
    DIJKSTRA(o);
    long long  ans = 1e17 ;
    for (int i = 0; i <= k ; i++) ans = min(dp[p][i],ans);
    if (ans != 1e17) cout << ans;
    else cout << -1;
}