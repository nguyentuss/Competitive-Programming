#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int ans = 0;
    int i = 1;
    while (ans <= 1e13) {
        ans = ans + i*(floor(sqrt(i)) + ceil(i / 2));
        i++;
    }
    cout << i - 1;

    return 0;
}