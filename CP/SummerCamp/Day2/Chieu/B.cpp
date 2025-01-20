#include<bits/stdc++.h>
using namespace std;

#define y1 as214
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >
#define v pair<iv , int>

#define fi first
#define se second
#define fr front()
#define pb push_back

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define REP(i , n) for(int i = 0 ; i < n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)

#define ll long long
#define oo 1e9 + 7

struct seg {
    int l , r , t , type , id , val;
};

const int N = 1e6 + 5;
int n , m , k , u , L = 1 , R = 0 , t = 0 , qq;
int cnt[N] , dp[N] , a[N] , b[N];
ii f[N];
seg q[N];
int ans[N];
int mm[N];
unordered_map < int , int > mp;


bool cmp(seg a, seg b)
{
    if(a.l / k != b.l / k)
        return a.l / k < b.l / k;
    if(a.r / k != b.r / k)
        return a.r / k < b.r / k;
    return a.t < b.t;
}

void MO(int i)
{
    while(R < q[i].r)
    {
        R++;
        cnt[a[R]]++;
    }
    while(R > q[i].r)
    {
        cnt[a[R]]--;
        R--;
    }
    while(L > q[i].l)
    {
        L--;
        cnt[a[L]]++;
    }
    while(L < q[i].l)
    {
        cnt[a[L]]--;
        L++;
    }
    while(t < q[i].t)
    {
        t++;
        if(L <= f[t].fi && f[t].fi <= R)
        {
            cnt[a[f[t].fi]]--;
            cnt[f[t].se]++;
        }
        swap(a[f[t].fi] , f[t].se);
    }
    while(t > q[i].t)
    {
        if(L <= f[t].fi && f[t].fi <= R)
        {
            cnt[a[f[t].fi]]--;
            cnt[f[t].se]++;
        }
        swap(a[f[t].fi] , f[t].se);
        t--;
    }
}

void sp(int &num)
{
    register int c;
    num = 0;
    for(c = getchar() ; c < 48 || c > 57 ; c = getchar());
    for(; c >= 48 && c <= 57 ; c = getchar())
        num = num * 10 + c - 48;
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(NULL);
    sp(n);sp(qq);
    for (int i = 1 ; i <= n ;i ++) {
        sp(a[i]);
        b[i] = a[i];
    }
    int r = 0;
    vector<int> ca;
    FOR(i , 1 , qq)
    {
        int type;
        sp(type);
        if(type == 1)
        {
            int x , y;
            sp(x); sp(y);
            f[++r] = ii(x , y);
            b[n + r] = y;
        }
        else
        {
            int x , y , val;
            sp(x); sp(y); sp(val);
            q[++u].l = x;
            q[u].r = y;
            q[u].t = r;
            q[u].val = val;
            ca.push_back(val);
            q[u].type = type;
            q[u].id = i;
        }
    }
    int cc = 0;
    for (auto x : ca) {
        ++cc;
        b[n + r + cc] = x;
    }
    int m = n + r + cc;
    int rr = 0;
    sort(b + 1 , b + 1 + m);
    b[0] = -oo;
    FOR(i , 1 , m)
    {
        if(b[i] != b[i - 1]) {
            mp[b[i]] = ++rr;
            mm[rr] = b[i];
        }
    }
    FOR(i , 1 , n)
        a[i] = mp[a[i]];
    FOR(i , 1 , r)
        f[i].se = mp[f[i].se];
    k = pow(n , (double)2 / 3);
    sort(q + 1 , q + 1 + u , cmp);
    FOR(i , 1 , u)
    {
        MO(i);
        bool found = false;
        if (q[i].type == 2) { 
            for (int j = mp[q[i].val] ; j <= rr ; j++) {
                if(cnt[j])
                {
                    ans[q[i].id] = mm[j];
                    found = true;
                    break;
                }
            }
        }
        else {
            for (int j = mp[q[i].val] ; j >= 1 ; j--) {
                if (cnt[j]) {
                    ans[q[i].id] = mm[j]; 
                    found = true;
                    break;
                }
            }
        }
        if (!found) ans[q[i].id] = -1;
    }
    FOR(i , 1 , qq)
        if(ans[i] != 0)
            cout << ans[i] << "\n";
}
