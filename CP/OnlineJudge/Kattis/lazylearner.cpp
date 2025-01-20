// source:: https://open.kattis.com/problems/lazylearner
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;
template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second

const int inf = 1e9 + 7;
const int N = 2e4 + 7;
const int MOD = 1e9 + 7;

/*call f[i][similar_str] is the nearest position i subsequence
and the left position is f[i][similar_str];
when we run then character of the string from position 1 -> n
if (s[i] == first character of the word)
f[i][1] = i;
*/  
int ch(char c) {
    c -= 'a';
    return (int) c;
}

vector<ii> pos[507];
vector<int> adj[N];
vector<string> a; 
vector<int> f[507];
int g[N][507];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1;
    while (test--) {
        string s; cin >> s; 
        int len_s = s.size();
        s = " " + s;
       // cerr << s[len_s];
        int nn = 0;
        int n , q; cin >> n >> q;
        for (int i = 0 ; i < n ; i++) {
            string x; cin >> x;
            x = " " + x;
            nn = max(nn , (int) x.size());
            a.push_back(x);
        }
        sort(a.begin() , a.end());
        for (int i = 0 ; i <= s.size() ; i++) {
            f[i].assign(nn + 5 , -1);
        }
        for (int i = 1 ; i < N ; i++) {
            for (int j = 1 ; j < 507 ; j++) {
                g[i][j] = -1;
            }
        }
       // cerr << "DEBUG" << '\n';
        for (int c = 0 ; c < n ; c++) {
            auto t = a[c];
            int len = t.size() - 1;
            for (int i = 1 ; i <= len_s ; i++) {
                for (int j = 1 ; j <= len ; j++) {
                    f[i][j] = -1; 
                }
            }
            for (int i = 1 ; i <= len_s; i++) {
                for (int j = 1 ; j <= len ; j++) {
                    //cerr << i << " " << j << '\n';
                    if (s[i] == t[j]) {
                        if (j == 1) {
                            f[i][1] = i;
                        }
                        else {
                            f[i][j] = f[i - 1][j - 1];
                        }
                    }
                    else {
                        f[i][j] = f[i - 1][j];
                    }
                }
            }
            for (int i = 1 ; i <= len_s ; i++) {
                g[c][i] = f[i][a[c].size() - 1];
            }
        }
        //cerr << "DEBUG" << '\n';
        for (int c = 0 ; c < n ; c++) {
            for (int i = 1 ; i <= len_s ; i++) {
                if (g[c][i] != -1) {
                    pos[i].push_back(ii(g[c][i] , c));
                }
            }
            //cout << '\n';
        }
        //cerr << "DEBUG" << '\n';
        for (int i = 1 ; i <= len_s ; i++) {
            sort(pos[i].begin(),pos[i].end());
        }
        vector<ii> bp[507][n + 7];
        auto calc = [&](int x , int p) -> int {
            int l = 0 , r = pos[p].size() - 1; 
            int ans = -1;
            while (l <= r) {
                int mid = (l + r)/2;
                if (x <= pos[p][mid].fi) {
                    r = mid - 1;
                    ans = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            return ans;
        };
        int cnt = 0;
        vector<pair<int , int>> v;
        while (q--) {
            cnt ++;
            int l , r , k; cin >> l >> r >> k;
            int lf = calc(l , r); 
            if (lf == -1 || (lf != -1 && ((int) pos[r].size() - lf) < k)) {
                v.push_back(ii(cnt , -1));
            }
            else {
                int tt = pos[r][lf + k - 1].se;
                bp[r][lf].push_back(ii(k , cnt));
            }
        }
        indexed_set<int> st;
        for (int i = 1 ; i <= len_s ; i++) {
            st.clear();
            for (int j = pos[i].size() - 1 ; j >= 0 ; j --) {
                st.insert(pos[i][j].se);
                for (auto x : bp[i][j]) {
                    int k = x.first;
                    int id = x.second;
                    int val = *st.find_by_order(k - 1);
                    v.push_back(ii(id , val));
                }
            }
        }
        sort(v.begin(),v.end()); 
        for (auto x : v) {
            if (x.se == -1) {
                cout << "NO SUCH WORD" << '\n';
            }
            else {
                for (int i = 1 ; i < min(11 , (int)a[x.se].size()) ; i++) {
                    cout << a[x.se][i];
                }
               cout << '\n';
            }
        }
    }
    return 0;
}