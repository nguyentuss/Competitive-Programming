#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 1) cout << 1 << '\n';
        else if (n == 2) cout << 2 << " " << 1 << '\n';
        else {
            cout << 2 << " ";
            int half1 = 0 , half2 = 0;
            if (n % 2 == 0) half1 = (n - 3)/2 , half2 = half1 + 1;
            else half1 = half2 = (n - 3)/2;
            for (int i = 1 ; i <= half1 ; i++) {
                cout << 3 + i << " ";
            }
            cout << 1 << " ";
            for (int i = 1 ; i <= half2 ; i++) {
                cout << 3 + half1 + i << " ";
            }
            cout << 3 << '\n';
        }
    }

    return 0;
}