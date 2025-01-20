#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//===========================================
const int MAX = 1e4+5;
ll dp[MAX], n, MOD;
bool p[MAX];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> MOD;
    for (int i = 0; i <= n; i++) dp[i] = 1;
    for (int i = 2; i <= n; i++){
        if (p[i]) continue;
        for (int j = i*i; j <= n; j+=i) p[j] = 1;
        for (int j = n; j; j--){
            int x = i;
            while (x <= j){
                dp[j] = (dp[j] + dp[j-x]*x)%MOD;
                x *= i;
            }
        }
    }
    cout << dp[n] << "\n";
}
