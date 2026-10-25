#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX_N (int) (1e4 + 7)

ll a[MAX_N] , l[MAX_N] , r[MAX_N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    freopen("test.inp","r",stdin);
    ll n, ans = 0;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) 
    	cin >> a[i];
    for (int i = 1 ; i <= n ;i++) {
        l[i] = 1;
        for (int j = 1 ; j <= i - 1 ; j++) {
        	if(a[j] > a[i]) 
        		l[i] = max(l[i], l[j] + 1);
    	}
    }
    for (int i = n ; i >= 1 ; i--) {
        r[i] = 1;
        for (int j = i + 1 ; j <= n ; j++)  {
        	if(a[j] > a[i]) 
        		r[i] = max(r[i], r[j] + 1);
        }
        ans = max(l[i] + r[i] - 1, ans);
    }
    cout << ans;
    return 0;
}