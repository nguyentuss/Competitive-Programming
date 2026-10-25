#include<bits/stdc++.h>
using namespace std;
const int oo=3000000;
const int maxn=205;
int n,m,s,t;
int D[maxn][maxn],P[maxn][maxn];
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(D[i][k]+D[k][j]< D[i][j]){
                    D[i][j]=D[i][k]+D[k][j];
                    P[i][j]=k;
                }
            }
        }
    }
}
void Path(int u, int v){
    if(P[u][v]==0) return;
    else{
        Path(u,P[u][v]);
        cout << P[u][v] << " ";
        Path(P[u][v],v);
    }
}
int main(){
    //freopen("Ngadangiu.INP","r",stdin);
    //freopen("Ngadangiu.OUT","w",stdout);
    freopen("path.INP","r",stdin);
    freopen("path.OUT","w",stdout);
    cin >> n >> m >> s >> t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            D[i][j]=100000;
            P[i][j]=0;
            if(i==j) D[i][j]=0;
        }
    }
    int u,v,val;
    for(int i=1;i<=m;i++){
        cin >> u >> v >> val;
        D[u][v]=D[v][u]=val;
    }
    floyd();
    cout << D[s][t] << endl;
    cout << s << " ";
    Path(s,t);
    cout << t;
    return 0;
}