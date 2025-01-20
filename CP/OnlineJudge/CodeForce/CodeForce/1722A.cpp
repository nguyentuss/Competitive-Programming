#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t ;cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int cnt1 = 0; 
        int cnt2 = 0;
        int cnt3 = 0; 
        int cnt4 = 0;
        int cnt5 = 0;
        for (int i = 0 ; i < s.size() ; i++) {
            if (s[i] == 'T') cnt1++;
            if (s[i] == 'i') cnt2++;
            if (s[i] == 'm') cnt3++;
            if (s[i] == 'u') cnt4++;
            if (s[i] == 'r') cnt5++;
        }
        if (cnt1 == 1 && cnt2 == 1 && cnt3 == 1 && cnt4 == 1 && cnt5 == 1) {
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }
}