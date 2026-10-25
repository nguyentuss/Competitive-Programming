#include<bits/stdc++.h>
#define ll long long
#define pl pair<ll,ll>
#define se second
#define fi first
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
using namespace std;
const ll maxn = 1e6 + 7;
const ll oo = 1000000000;
struct giun 
{ 
    ll L, R; 
} lista[maxn+2];
ll m , n, M[maxn] , pre[maxn];
char c; 
ll x, y;
int main()
{
    giuncute;
    freopen("test.inp","r",stdin);
	//freopen("lista.inp","r",stdin);
    //freopen("lista.out","w",stdout);
    cin >> n >> m;
    for( int i = 0; i <= n+1; ++i ) 
    {
        lista[i].L = i-1;
        lista[i].R = i+1;
    }
    for( int i = 0; i < m; ++i ) 
    {
        cin >> c >> x >> y;
        lista[lista[x].R].L = lista[x].L;
        lista[lista[x].L].R = lista[x].R;
        if( c == 'A' ) 
        {
            lista[x].L = lista[y].L;
            lista[x].R = y;
        } 
        else 
        {
            lista[x].L = y;
            lista[x].R = lista[y].R;
        }
        lista[lista[x].R].L = x;
        lista[lista[x].L].R = x;
    }
    M[0] = 0;
    for (int i = 1 ; i <= n ; i++) {
        cout << lista[i].L << " " << lista[i].R << '\n';
    }
    for( int i = 1; i <= n; ++i ) M[i] = oo;
    ll tmp = 0;
    for( int x = lista[0].R; x != n+1; x = lista[x].R )
    {
        ll d = upper_bound( M, M+n, x ) - M;
        M[d] = x;
        pre[x] = M[d-1];
        tmp = max(tmp , d);
    }
    cout << n - tmp;
}   