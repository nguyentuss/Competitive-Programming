#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int a = 0 , b = 0;
        int pos = -1 , sum = 0;
        for (int i = 0 ; i < (s.size() - 1) ; i++) {
            a = s[i] - '0' , b = s[i + 1] - '0';
            if (a + b >= 10) {
                sum = a + b;
                pos = i;
            }
        }
        if (pos == -1) {
            a = s[0] - '0' , b = s[1] - '0';
            cout << a + b;
            for (int i = 2 ; i < s.size() ; i++) {
                cout << s[i];
            }
            cout << '\n';
        }
        else {
            for (int i = 0 ; i < pos ; i++) cout << s[i];
            cout << sum;
            for (int i = pos + 2 ; i < s.size() ; i++) cout << s[i];
            cout << '\n';
        }
    }

    return 0;
}