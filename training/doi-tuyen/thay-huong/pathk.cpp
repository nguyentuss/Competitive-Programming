#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>

const int MAXN = 1e3+7;
const ll oo = 1e9 + 7;
ll N,M, S , T;
ll d[MAXN][MAXN]={0} , p[MAXN][MAXN]={0}  , dt[MAXN][MAXN]={0};
ll  t , res ;

void floy(void)
{
    for (int k = 1 ; k <= N ; k++)
    {
        for (int i = 1 ; i <= N ; i++)
        {
            for (int j = 1 ; j <= N ; j++)
            {
                if (d[i][j] > (d[i][k] + d[j][k]))
                {
                    d[i][j] = d[i][k] + d[j][k];
                    if (d[i][j]==t) res++;
                }
            }
        }
    }
}
int main(void)
{
    freopen("pathk.inp","r",stdin);
    freopen("pathk.out","w",stdout);
    cin >> N >> M >> t;
    ll x, y, l;
    for(int i = 1; i<=N; ++i) 
        for(int j = 1; j<=N; ++j) d[i][j] = 1e17;
    for (int i = 1 ; i <= N ; i++) d[i][i] = 0 ;
    for (int i = 1 ; i <= M ; i++)
    {
        cin >> x >> y >> l;
        d[x][y] = l; 
        d[y][x] = l;
    }   
    floy();
    cout << res/2;
}