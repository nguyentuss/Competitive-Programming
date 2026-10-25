#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct edge
{
    ll val;
    ll index;
};
bool cmp(edge a,edge b)
{
    if(a.val==b.val) return a.index<b.index;
    else return a.val<b.val;
}
int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin >> n;
        edge arr[n];
        for(int i=0; i<n; i++)
        {
            cin >> arr[i].val;
            arr[i].index = i;
        }
        sort(arr , arr+n , cmp);
       	ll current = arr[0].val;
        ll ans = 0;
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i].val != current)
            {
                sum = arr[i].index+1;
                current = arr[i].val;
            }
            else
            {
                ans+=sum*(n-arr[i].index);
                sum += arr[i].index+1;
            }
        }
        cout << ans << '\n';
    }
}