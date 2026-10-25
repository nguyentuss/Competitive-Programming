#include<bits/stdc++.h>
#define el cout<<"\n"
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define maxn 300005
#define fi first
#define se second
using namespace std;
int n, q, t[maxn], ans[maxn];
pair <int, int> a[maxn];
struct A
{
    int l, r, v, id;
}b[maxn];
bool cmp (A a, A b)
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ///freopen(file".inp","r",stdin);
    ///freopen(file".out","w",stdout);
    cin >> n;
    f1(i, n)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    cin >> q;
    f1 (i, q)
    {
        cin >> b[i].l >> b[i].r >> b[i].v;
        b[i].id = i;
    }
    sort(b+1, b+q+1, cmp);
    sort(a+1, a+n+1);
    int pos = n+1;
    for (int i=1; i<=q; i++)
    {
        while (pos > 1 && a[pos-1].fi > b[i].v)
            update(a[--pos].se);
        ans[b[i].id] = get(b[i].r) - get(b[i].l-1);
    }
    f1 (i, q) cout << ans[i] << '\n';
    return 0;
}