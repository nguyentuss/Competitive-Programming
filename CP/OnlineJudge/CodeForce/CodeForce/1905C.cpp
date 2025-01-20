//source:: 
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

bool issorted(string &s) {
    string a = s; 
    sort(a.begin() , a.end());
    return (a == s);
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (issorted(s)) {
        cout << 0 << '\n';
    }
    else {
        map<char , vector<int>> mp;    
        int pos = 0;
        for (char c : s) mp[c].push_back(pos++);
        int prev = -1;
        vector<int> b;
        string tm = "";
        for (int i = 'z' ; i >= 'a' ; i--) {
            char c = (char) i; 
            int mx = -1;
            for (auto j : mp[c]) {
                if (j > prev) {
                    mx = j; 
                    b.push_back(j);
                    tm += c;
                }
            }
            if (mx != -1) prev = mx;
        }
        reverse(tm.begin() , tm.end());
        int it = 0; 
        for (auto c : tm) {
            s[b[it++]] = c;
        }
        string aa = s;
        sort(aa.begin() , aa.end());
        if (aa == s) {
            cout << (int) b.size() - 1 - (int) mp[tm[(int) tm.size() - 1]].size() + 1 << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test; 
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}