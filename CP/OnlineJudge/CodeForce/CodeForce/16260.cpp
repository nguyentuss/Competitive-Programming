#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e3 + 7)

string s;

int main() {    
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        cin >> s;
        sort(s.begin() , s.end());
        cout << s << '\n';
    }
    return 0;
}