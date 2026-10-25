#include<bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)
#define f first
#define s second
#define ii pair<int ,int>
#define int long long
int n, q, t[MAX_N];
ii a[MAX_N];
int v[MAX_N];
struct query
{
    int l, r, v, id;
}b[MAX_N];
bool cmp (query a, query b)
{
    return a.v > b.v;
}
void update(int x)
{
    for(;x<=n;x+=x&-x) t[x]++;
}
int get(int x)
{
    int s = 0;
    for(;x;x-=x&-x) s+=t[x];
    return s;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("paveseq.inp","r",stdin);
    freopen("paveseq.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
    	cin >> v[i];
    	a[i].s = i;
    }
    int p; cin >> p;
    for (int i = 1 ; i <= n ; i++) {
        v[i] -= p;
        a[i].f = a[i - 1].f + v[i];
    }
    for (int i = 0 ; i <= n ; i++)
    {
        b[i].l = i + 1 , b[i].r = n , b[i].v = a[i].f - 1;
        b[i].id = i;
    }
    sort(b, b+n+1, cmp);
    sort(a + 1, a+n+1);
    int pos = n+1;
    int ans = 0;
    for (int i = 0 ; i <= n; i++)
    {  
        while (pos > 1 && a[pos-1].f > b[i].v)
            update(a[--pos].s);
        //cout << b[i].l << " " << b[i].r << " " << get(b[i].r) - get(b[i].l - 1) << '\n';
        ans += get(b[i].r) - get(b[i].l-1);
    }
    //for (int i = 1 ; i <= n ; i++) if (v[i] >= 0) ans++;
    cout << ans;

    return 0;
}