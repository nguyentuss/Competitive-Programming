#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

struct node {
    array<node *, 26> son; 
    node *link = nullptr;
    node *up = nullptr;
    vector<int> pos;
};

vector<int> adj[N];

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        node *rt = new node();
        auto add_string = [&] (string &s , int index) -> void {
            node *p = rt;
            for (auto c : s) {
                c -= 'a';
                if (!p->son[c]) {
                    p -> son[c] = new node();
                }
                p = p -> son[c];
            }
            p -> up = p;
            p -> pos.push_back(index);
        };
        auto build = [&] () -> void {
            queue<node *> q;
            node *p = rt;
            for (auto &p : rt -> son) {
                if (p) {
                    p -> link = rt;
                    if (!p -> up) {
                        p -> up = rt;
                    }
                    q.push(p);
                }
                else p = rt;
            }
            while (!q.empty()) {
                auto p = q.front();
                q.pop();
                int c = 0;
                for (auto &v : p->son) {
                    if (v) {
                        v->link = p->link->son[c];
                        if (!v->up)
                            v->up = v->link->up;
                            q.push(v);
                    } else
                        v = p->link->son[c];
                    c++;
                }
            }
        };
        string s; cin >> s;
        int q; cin >> q;
        vector<string> a;
        for (int i = 0 ; i < q ; i++) {
            string t; cin >> t;
            add_string(t , i);
            a.push_back(t);
        }
        build();
        node *p = rt;
        int cnt = 0;
        for (auto c : s) {
            c -= 'a'; 
            cnt++;
            p = p -> son[c]; 
            auto v = p -> up; 
            while (v != rt && v) {
                for (auto x : v -> pos) {
                    adj[cnt].push_back(x);
                }
                v = v -> link -> up;
            }
        }
        int n = s.size();
        vector<int> f(n + 1 , 0);
        f[0] = 1;
        for (int i = 1 ; i <= n ; i++) {
            for (auto j : adj[i]) {
                (f[i] += f[i - a[j].size()])%=MOD;
            }
        }
        cout << f[n];
    }
    return 0;
}