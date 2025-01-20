#include <bits/stdc++.h>

using namespace std;

#define int long long
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ii pair<int , int>

int n , q , a[2007][2007] , k;
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1 ; i <= n ; i++)
        for (int j = 1 ; j <= n ; j++) 
            cin >> a[i][j];
    while(q--)
    {
        int k; cin >> k;
        int x = n , y = 1;
        while (true) {
            if (a[x][y] == k) {
                cout << x << " " << y << '\n';
                break;
            }
            if (y == n) x--;
            else if (a[x][y] > k) {
                x--;
            }
            else if (a[x][y] < k) y++;
        }
    }
}