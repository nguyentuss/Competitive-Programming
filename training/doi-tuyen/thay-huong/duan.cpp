#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define MAX_N (int) (2e5 + 7)
int n , u ;
vector<int> g[MAX_N];
pair<int ,int> ans[MAX_N];
void dfs(int u)
{
    ans[u] = {1,1};
    for (int v : g[u])
    {
        dfs(v);
        ans[u].first += ans[v].first + ans[v].second , ans[u].second += ans[v].second;
    }
}
signed main()
{
    freopen("duan.inp","r",stdin);
    freopen("duan.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 2 ; i <= n ; i++) cin >> u , g[u].push_back(i);
    dfs(1);
    for (int i = 1 ; i <= n ; i++) cout << ans[i].first << " ";
}