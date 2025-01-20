#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
 
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 57;
const int MOD = 1e9 + 7;

int a[MAX_N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1 ; i <= n ;i ++) {
            cin >> a[i];
        }
        if(n % 2 == 1)
            cout << "Mike" << endl;
        else
        {
            int s1 = 1e18;
            int s2 = 1e18;
            int u = 1e18 , v = 1e18;
            for(int i = 1 ; i <= n ; i += 2)
            {
                if(s1 > a[i])
                {
                    s1 = a[i];
                    u = i;
                }
            }
            for(int i = 2; i <= n ; i += 2)
            {
                if(s2 > a[i])
                {
                    s2 = a[i];
                    v = i;
                }
            }
            if(s2 < s1)
                cout << "Mike" << endl;
            else if(s2 > s1)
                cout << "Joe" << endl;
            else
            {
                if(u < v)
                    cout << "Joe" << endl;
                else
                    cout << "Mike" << endl;
            }
        }
        
    }
 
    return 0;
}
