#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int a , b; cin >> a >> b;
    if (a == 0 && b == 0) cout << 1;
    else cout << min(a , b);

    return 0;
}