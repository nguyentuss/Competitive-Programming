#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    int left = 0 , right = 0;
    int any = 0;
    map<string , bool> ml;
    map<string , bool> mr;
    map<string , int> many;
    bool status = 0;
    int cnt_any = 0;
    for (int i = 0 ; i < n ; i++) {
        string s1 , s2; cin >> s1 >> s2;
        int num; cin >> num;
        if (s2 == "left") {
            left += num;
            ml[s1] = true;
        }
        if (s2 == "right") {
            right += num; 
            mr[s1] = true;
        }
        if (s2 == "any") {
            status = 1;
            any += num;
            many[s1] += num;
            cnt_any ++;
        }
    }
    auto solve = [&]() -> int {
        bool stat = 0;
        int ans = 0;
        for (auto [key , value] : ml) {
            if (value > 0 && mr[key] > 0) {
                stat = 1;
                ans = max(ans , (max(value , mr[key]) + 1 + left + right - value - mr[key] + cnt_any - many[key]);
            }
        }
        if (stat) return ans;
        for (auto [key , value] : many) {
            if (value >= 1 && (ml[key] > 0 || mr[key] > 0)) {
                if ()
            }
        }
        return 0;
    };
    int ans = solve();
    if (!ans) cout << "impossible";
    else cout << ans;
    return 0;
}