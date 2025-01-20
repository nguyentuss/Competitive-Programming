//source:: https://open.kattis.com/problems/classy
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ii pair<string , string>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
typedef unsigned __int128 ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;

bool cmp(const ii &a , const ii &b) {
    if (a.first == b.first) return (a.second < b.second); 
    return a.first > b.first;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    cin >> test;
    while (test--) {
        int n; cin >> n;
        vector<ii> a;
        for (int i = 0 ; i < n ; i++) {
            string tmp; cin >> tmp; 
            string s = "", name = "";
            for (int j = 0 ; j < (int) tmp.size() - 1 ; j++) name += tmp[j];
            cin >> tmp;
            int l = 0;
            while (l < (int) tmp.size()) {
                if (tmp[l] == 'u') l += 6 , s += '2';
                else if (tmp[l] == 'm') l += 7 , s += '1'; 
                else if (tmp[l] == 'l') l += 6 , s += '0';
            }
            //reverse(s.begin() , s.end());
            while ((int) s.size() < 10) {
                s = "1" + s;
            }
            reverse(s.begin() , s.end());
            //cerr << name << " " << s << '\n';
            a.push_back(ii(s , name));
            cin >> tmp;
        }
        sort(a.begin() , a.end() , cmp);
        for (auto [tm , nm] : a) {
            //cout << tm << " " << nm << '\n';
            cout << nm << '\n';
        }
        for (int i = 0 ; i < 30 ; i++) cout << "=";
        cout << '\n';
    }
    return 0;
}