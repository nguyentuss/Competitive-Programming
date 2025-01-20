/*
	https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/Baltic/official/boi2009_solutions/trian-sol.pdf
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> adj(100005),color(100005),nadj(100005);
int p[100005][30],val[100005],l[100005];
int n;
int res=0,vis[100005];

void build(int cur,int lvl){
    vis[cur]=1;
    l[cur]=lvl;
    for(int i=0;i<adj[cur].size();i++){
        if(!vis[adj[cur][i]]){
            p[adj[cur][i]][0]=cur;
            nadj[cur].push_back(adj[cur][i]);
            build(adj[cur][i],lvl+1);
        }
    }
}
pair<int,int> dfs(int cur){
    int te=0,sup=0;
    for(int i=0;i<nadj[cur].size();i++){
        pair<int,int> pr=dfs(nadj[cur][i]);
        te+=pr.second;
        sup+=pr.first;
    }
    sup+=val[cur];
    te++;
    if(sup==te){res++;}
    return {sup,te};
}

void pre(){
    for(int j=1;j<=19;j++){
        for(int i=1;i<=n;i++){
            if(p[i][j-1]!=-1){
                p[i][j]=p[p[i][j-1]][j-1];
            }
        }
    }
}
int LCA(int u,int v){
    if(l[u]<l[v]){
        int tmp=u;
        u=v;
        v=tmp;
    }
    for(int j=19;j>=0;j--){
        if(p[u][j]!=-1&&l[p[u][j]]>=l[v]){
            u=p[u][j];
        }
    }
    if(u==v){
        return u;
    }
    for(int j=19;j>=0;j--){
        if(p[u][j]!=p[v][j]){
            v=p[v][j];
            u=p[u][j];
        }
    }
    return p[u][0];
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("maxflow.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(p,-1,sizeof p);
    cin>>n;
    map<pair<int,int>,int> mp;
    for(int i=1;i<=n-2;i++){
        int ar[3],cl;
        for(int j=0;j<3;j++){
            cin>>ar[j];
        }
        cin>>cl;
        color[cl].push_back(i);
        sort(ar,ar+3);
        if(mp[{ar[0],ar[1]}]!=0){
            adj[mp[{ar[0],ar[1]}]].push_back(i);
            adj[i].push_back(mp[{ar[0],ar[1]}]);
        }
        else{
            mp[{ar[0],ar[1]}]=i;
        }
        if(mp[{ar[1],ar[2]}]!=0){
            adj[mp[{ar[1],ar[2]}]].push_back(i);
            adj[i].push_back(mp[{ar[1],ar[2]}]);
        }
        else{
            mp[{ar[1],ar[2]}]=i;
        }
        if(mp[{ar[0],ar[2]}]!=0){
            adj[mp[{ar[0],ar[2]}]].push_back(i);
            adj[i].push_back(mp[{ar[0],ar[2]}]);
        }
        else{
            mp[{ar[0],ar[2]}]=i;
        }
    }
    build(1,0);
    pre();
    for(int i=1;i<=n;i++){
        int cur=0;
        if(color[i].size()==0){
            continue;
        }
        else if(color[i].size()==1){
            val[color[i][0]]+=1;
        }
        else {
            for (int j = 1; j < color[i].size(); j++) {
                if (j == 1) {
                    cur = LCA(color[i][0], color[i][j]);
                } else {
                    cur = LCA(cur, color[i][j]);
                }
            }
            val[cur]+=color[i].size();
        }
    }
    dfs(1);
    cout<<res-1<<endl;
    return 0;
}