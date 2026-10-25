#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

bool p[N];
int f[N]; // f[i] la cach ma thang dau tien co the thang
// f[i - j] thang dau tien se khogn the thang
// game theory => 2 thang deu toi uu , chuyen trang thai thang doi thu cung se toi uu theo

void eratosthenes() {
    p[0] = true;
    p[1] = true;
    for (int i = 2 ; i < N ; i++) {
        if (!p[i]) {
            for (int j = 2 * i; j < N; j += i) {
                p[j] = true;
            }
        }
    }
}

void solve() {
    eratosthenes();
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 1 ; j <= 3 ; j++) {
            if ((i - j) >= 0 && p[i - j] && !f[i - j]) {
                f[i] = true;
            }
        }
    }
    //for (int i = 0 ; i <= n ; i++) cout << f[i] << " ";
    cout << (f[n] ? 1 : 2);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}