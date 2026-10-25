#include <bits/stdc++.h>
using namespace std;

int t, n, m, sx, sy, ex, ey;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("sweet.inp", "r", stdin); 
    freopen("sweet.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> sx >> sy >> ex >> ey;
        if (sx == 1 && sy == 1) {
            if (ex % 2 == 0) {
                if (ey == 1) 
                    cout << (ex == n ? "Over\n" : "Back\n");
                else
                    cout << "Left\n";
            } else {
                if (ey == m)
                    cout << (ex == n ? "Over\n" : "Back\n");
                else
                    cout << "Right\n";
            }
        } else if (sx == 1 && sy == m) {
            if (ex % 2 == 0) {
                if (ey == m) 
                    cout << (ex == n ? "Over\n" : "Back\n");
                else
                    cout << "Right\n";
            } else {
                if (ey == 1)
                    cout << (ex == n ? "Over\n" : "Back\n");
                else
                    cout << "Left\n";
            }
        } else if (sx == n && sy == 1) {
            if ((n - ex + 1) % 2 == 1) {
                if (ey == m) 
                    cout << (ex == 1 ? "Over\n" : "Front\n");
                else 
                    cout << "Right\n";
            } else {
                if (ey == 1) 
                    cout << (ex == 1 ? "Over\n" : "Front\n"); 
                else
                    cout << "Left\n";
            }
        } else {
            if ((n - ex + 1) % 2 == 1) {
                if (ey == 1) 
                    cout << (ex == 1 ? "Over\n" : "Front\n");
                else 
                    cout << "Left\n";
            } else {
                if (ey == m) 
                    cout << (ex == 1 ? "Over\n" : "Front\n"); 
                else
                    cout << "Right\n";
            }
        }  
    }
    return 0;
}