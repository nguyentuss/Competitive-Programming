//source:: https://codeforces.com/gym/489781/problem/B
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
    string st; cin >> st;
    while (test--) {
        if (st == "encode") {
            int n; cin >> n;
            vector<int> adj[n];
            for (int i = 0 ; i < n - 1 ; i++) {
                int u , v ; cin >> u >> v;
                u--; v--;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            min_heap<int> pq;
            vector<int> sz(n);
            for (int i = 0 ; i < n ; i++) {
                sort(adj[i].begin() , adj[i].end());
                if (adj[i].size() == 1) {
                    //cerr << i << " ";
                    pq.push(i);
                }
                sz[i] = adj[i].size();
            }
            vector<bool> vis(n , false);
            vector<int> ans;
            int num_ver = n;
            while (!pq.empty()) {
                int u = pq.top();
                pq.pop();
                vis[u] = true;
                if (num_ver < 3) break;
                num_ver--;
                if (!sz[u]) continue;
                for (auto v : adj[u]) {
                    if (!vis[v]) {
                        sz[v]--; 
                        ans.push_back(v + 1);
                        if (sz[v] == 1) {
                            pq.push(v);
                        }
                    }
                }
            }
            for (auto u : ans) cout << u << " ";
            cout << '\n';
        }
        else {
            int n; cin >> n;
            vector<int> a;
            vector<int> prufer(n , 0);
            for (int i = 0 ; i < n - 2 ; i++) {
                int x; cin >> x;
                x--;
                a.push_back(x);
                prufer[x]++;
            }
            set<ii> s;
            for (int i = 0 ; i < n ; i++) {
                s.insert(ii(prufer[i] , i));
            }
            // for (auto [pr , id] : s) {
            //     cout << pr << " " << id << '\n';
            // }
            // cout << '\n';
            for (auto c : a) {    
                auto it = ii(prufer[c] , c);
                s.erase(it);
                for (auto [pr,id] : s) {
                    if (pr == 0) {
                        cout << c + 1 << " " << id + 1 << '\n';
                        prufer[id] = -1;
                        prufer[c]--;
                        if (prufer[c] != -1) {
                            s.insert(ii(it.fi - 1 , it.se));
                        }
                        //cerr << s.size() << " ";
                        s.erase(s.find(ii(pr , id)));
                        //cerr << s.size() << " "; 
                        break;
                    }
                }
            }
            bool status = 0;
            // for (int i = 0 ; i < n ; i++) {
            //     cerr << prufer[i] << " ";
            // }
            for (int i = 0 ; i < n ; i++) {
                if (!prufer[i] && !status) {
                    cout << i + 1 << " ";
                    status = 1;
                }
                else if (!prufer[i] && status) {
                    cout << i + 1<< " "; 
                    break;
                }
            }
            cout << '\n';
        }
    }
    return 0;   
}