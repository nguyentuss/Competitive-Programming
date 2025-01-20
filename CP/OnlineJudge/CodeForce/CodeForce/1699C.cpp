#include<bits/stdc++.h>

using namespace std;

#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define ll long long
#define oo 1e17
#define int long long

const int N = 1e6 + 5;
int q , n , mod = 1e9 + 7;
int p[N] , pos[N] , a[N];

int add(int a , int b)
{
    return (a + b) % mod;
}

int mul(int a , int b)
{
    return (a * b) % mod;
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    p[0] = 1;
    for (int i = 1 ; i <= 100000 ; i++)
        p[i] = mul(p[i - 1] , i);
    while(q--)
    {
        cin >> n;
        for (int i = 1 ; i <= n ;i ++)
        {
            cin >> a[i];
            pos[a[i]] = i;
        }
        int l = pos[0];
        int r = pos[0];
        int ans = 1;
        int cnt = 1;
        for (int i = 1 ; i < n ; i++) 
        {
            if(l > pos[i])
            {
                cnt += 1;
                l = min(l , pos[i]);
            }
            else if(r < pos[i])
            {
                cnt += 1;
                r = max(r , pos[i]);
            }
            else
            {
                ans = mul(ans , r - l + 1 - cnt);
                cnt += 1;
            }
        }
        cout << ans << "\n";
    }
}