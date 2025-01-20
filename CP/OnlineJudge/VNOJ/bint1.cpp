#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD (int) (1e9 + 7)
int catalan[10007];
 
void catalanDP()
{
    catalan[0] = catalan[1] = 1;
 
    for (int i = 2; i < 10007; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] = (catalan[i]%MOD + catalan[j] * catalan[i - j - 1]%MOD)%MOD;
    }
 
}
 
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    catalanDP();
    while (t--) {
        int n; cin >> n;
        cout << catalan[n] << '\n';
    }
    return 0;
}