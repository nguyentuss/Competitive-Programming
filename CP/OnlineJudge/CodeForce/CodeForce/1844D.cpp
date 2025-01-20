#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
vector<int> res;
int cnt[N];
char a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        res.clear();
        for (int i = 1 ; i * i <= n ; i++) {
            if (!(n % i)) {
                res.push_back(i);
                if (i != (n/i)) res.push_back(n/i);
            }
        }
        for (int i = 1 ; i <= n ; i++) {
            for (auto x : res) {
                if ((i - x) > 0) {
                    cnt[a[i - x]] = 1;
                }
            }
            for (char j = 'a' ; j <= 'z' ; j++) {
                if (!cnt[j]) {
                    a[i] = (char)j;
                    break;
                }
            }
            for (auto x : res) {
                if ((i - x) > 0) {
                    cnt[a[i - x]] = 0;
                }
            }
        }
        for (int i = 1 ; i <= n ; i++) {
            cout << a[i];
        }
        cout << '\n';
    }

    return 0;
}