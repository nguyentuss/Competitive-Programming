#include <bits/stdc++.h>
#define oo 1000000000
#define fs first
#define sc second
using namespace std;
typedef pair<int,int> II;
typedef pair<int,II> III;
    III a[100001];
    int n,m,deg[100001],lt[100001],sl[100001],d[100001];
    vector<II> g[100001];
    long long ds=0;
    int pre[100001],depth[100001],cur[100001],s[100001],
    valp[100001];
    int f[100001][20],vmin[100001][20],retmin;
void dfs()
{
    for(int i=1; i<=n; i++) lt[i]=0;
    int sn=0;
    s[++sn]=1; lt[1]=1;
    while(sn)
    {
        int u=s[sn];
        while(cur[u]<deg[u]&&lt[g[u][cur[u]].first]) cur[u]++;
        if(cur[u]==deg[u]) sn--;
        else{
            int v=g[u][cur[u]].first;
            lt[v]=1;
            s[++sn]=v;
            depth[v]=depth[u]+1;
            pre[v]=u;
            valp[v]=g[u][cur[u]].second;
        }
    }
}
void init()
{
    for(int i=1; i<=n; i++){
        f[i][0]=pre[i];
        vmin[i][0]=valp[i];
    }
    int m=int(log2(n))+1;
    for(int k=1; k<=m; k++)
        for(int i=1; i<=n; i++)
    {
        f[i][k]=f[f[i][k-1]][k-1];
        if(f[i][k]==0) vmin[i][k]=oo;
        else
        vmin[i][k]=min(vmin[i][k-1],vmin[f[i][k-1]][k-1]);
    }
}
void lca(int u, int v)
{
    while(depth[u]>depth[v])
    {
        int k=int(log2(depth[u]-depth[v]));
        retmin=min(retmin,vmin[u][k]);
        u=f[u][k];
    }
    while(depth[v]>depth[u])
    {
        int k=int(log2(depth[v]-depth[u]));
        retmin=min(retmin,vmin[v][k]);
        v=f[v][k];
    }
    if(u==v) return;
    int m=int(log2(depth[u]))+1;
    for(int k=m; k>=0; k--)
        if(f[u][k]!=f[v][k])
    {
        retmin=min(retmin,vmin[u][k]);
        retmin=min(retmin,vmin[v][k]);
        u=f[u][k]; v=f[v][k];
    }
    retmin=min(retmin,vmin[u][0]);
    retmin=min(retmin,vmin[v][0]);
    u=f[u][0]; v=f[v][0];
    return;
}
int tim(int u)
{
    if(u==lt[u]) return u;
    lt[u]=tim(lt[u]);
    return lt[u];
}
int main()
{
    //freopen("upgranet.inp","r",stdin);
    //freopen("upgranet.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
        cin>>a[i].sc.fs>>a[i].sc.sc>>a[i].fs;
    sort(a+1,a+m+1);
    for(int i=1; i<=n; i++) lt[i]=i,sl[i]=1;
    for(int i=m; i>=1; i--)
    {
        int u1=a[i].sc.fs;
        int v1=a[i].sc.sc;
        int u=tim(u1);
        int v=tim(v1);
        if(u!=v)
        {
            d[i]=1;
            if(sl[u]<sl[v]){lt[u]=v;sl[v]+=sl[u];}
            else {lt[v]=u;sl[u]+=sl[v];}
            deg[u1]++;g[u1].push_back(II(v1,a[i].fs));
            deg[v1]++;g[v1].push_back(II(u1,a[i].fs));
        }
    }
    dfs();
    init();
    for(int i=1; i<=m; i++)
        if(d[i]==0)
        {
            retmin=oo;
            int u=a[i].sc.fs;
            int v=a[i].sc.sc;
            lca(u,v);
            int p=retmin-a[i].fs;
            ds+=(long long)p;
        }
    cout<<ds;
}