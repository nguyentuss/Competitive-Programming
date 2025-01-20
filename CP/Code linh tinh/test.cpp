#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[500005][2],n,k;
vector<pair<int,int> >G[500005];
void addedge(int u,int v,int w){G[u].push_back({v,w});}
bool cmp(int x,int y){return x>y;}
void dfs(int u,int fa){
    vector<int> d;int D;
    dp[u][0]=dp[u][1]=0;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i].first,w=G[u][i].second;
        if(v==fa)continue;
        dfs(v,u);
        dp[u][0]+=dp[v][1];
        dp[u][1]+=dp[v][1];
        d.push_back(w+dp[v][0]-dp[v][1]);
    }
    sort(d.begin(),d.end(),cmp);
    for(int i=0;i<k and i<d.size();i++)
    {
        D=d[i];
        if(D<=0) break;
        if(i<k-1)dp[u][0]+=D;
        //dp[u][0]+=D;
        dp[u][1]+=D;
    }
}
signed main() {
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    int t,u,v,w;
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        for(int i=1;i<=n;i++) G[i].clear(); 
        cin>>n>>k;
        for(int i=1;i<n;i++){cin>>u>>v>>w;addedge(u,v,w);addedge(v,u,w);}
        dfs(1,0);
        for (int i = 1 ; i <= n ; i++) 
            cout << dp[i][1] << " " << dp[i][0] << '\n';
        //cout << dp[1][1] << " " << dp[1][0] << '\n';
        cout<<max(dp[1][1],dp[1][0])<<'\n';
    }
}