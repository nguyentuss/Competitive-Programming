#include <bits/stdc++.h>

using namespace std;

int main() {
    int m , b; cin >> m >> b; 
    int ans = 0;
    for (int y = 0 ; y <= b ; y++) {
        int x = -(y - b)*m;
        ans = max(ans , (y + 1)*x*(x + 1)/2 + (x + 1)*y*(y + 1)/2);
    }
    cout << ans << '\n';
    return 0;
}