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

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test;
    cin >> test;
    string ct; cin >> ct;
    while (test--) {
        string s; cin >> s;
        int n = s.size(); 
        if (ct == "encode") {
            s = "#" + s;
            vector<string> a;
            a.push_back(s);
            for (int i = 0 ; i < n ; i++) {
                a.push_back( s.substr(i + 1 , n - i) + s.substr(0 , i + 1));
            }
            sort(a.begin() , a.end()); 
            for (auto x : a) {
                cout << x[x.size() - 1];
            }
            for (auto x : a) {
                cerr << x << '\n'; 
            }
            cout << '\n';
        }
        if (ct == "decode") {
            vector<char> first , last;
            n--;
            for (auto x : s) {
                last.push_back(x); 
            }
            first = last;
            sort(first.begin() , first.end()); 
            vector<char> res(n);
            map<char , char> mp;
            for (int i = 0 ; i < (int) first.size() ; i++) {
                mp[last[i]] = first[i]; 
            }
            for (auto [key,value] : mp) {
                if (value == '#') {
                    res[n - 1] = key;
                }
            }
            res[0] = mp['#'];
            for (int i = 1 ; i < n - 1 ; i++) {
                res[i] = mp[res[i - 1]];
            }
            for (int i = 0 ; i < (int) res.size() ; i++) {
                cout << res[i];
            }
            cout << '\n';
        }

    }
    return 0;
}