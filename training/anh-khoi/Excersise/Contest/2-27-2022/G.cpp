#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
#define ii pair<int , int>
#define f first
#define s second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t;  cin >> t;
    map<string , string> winner;
    winner["Alice"] = "Bob";
    winner["Bob"] = "Alice";
    while (t--) {
        vector<int> pr;
        int x; cin >> x;
        string str; cin >> str;
        int N = x , num_of_prime = 0 , total_of_base = 0;
        for (int i = 2 ; i * i <= N ; i ++) {
            if (N % i == 0) {
                int cnt = 0;
                num_of_prime++;
                while (N % i == 0) {
                    cnt++;
                    total_of_base++;
                    N /= i;
                }
                pr.emplace_back(cnt);
            }
        }
        if (N > 1) num_of_prime++ , total_of_base++ , pr.emplace_back(1);
        if (num_of_prime > 2) {
            cout << "tie" << '\n';
        }
        else {
            if (num_of_prime == 1) {
                if (total_of_base % 2) {
                    cout << str << '\n';
                }
                else cout << winner[str] << '\n';
            }
            else {
                int last = total_of_base - min(pr[0] , pr[1])*2;
                if (!last) cout << winner[str] << '\n';
                else {
                    if (last >= 2) cout << "tie" << '\n';
                    else cout << str << '\n';
                }
            }
        }
    }
    return 0;
}