// problem set: https://vjudge.net/problem/UVA-10679

#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

struct node {
    array<node *, 52> son = {};
    node *in[52];
    node *link = nullptr;
    node *up = nullptr;
    int dep = 0;
    int nd = 0;
    vector<int> pos;
};

int change(char c) {
    if  (c == tolower(c)) c -= 'a'; 
    else {
        c -= 'A'; 
        c = c + (int) 26;
    }
    return c;
}

int cnt = 0;
main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        
        node *rt = new node();
        string s; cin >> s;
        int q; cin >> q;
        auto insert = [&](string &s , int index) -> void {
            node *p = rt; 
            for (auto c : s) {
                c = change(c);    
                if (!p->son[c]) {
                    p->son[c] = new node(); 
                    p->son[c]->dep = p->dep + 1;
                    p->son[c]->nd = ++cnt;
                }
                p = p->son[c];
            }
            p -> up = p;
            p -> pos.push_back(index);
        };

        auto buildAC = [&]() -> void {
            queue<node *> q;
            for (auto &p : rt->son) {
                if (p) {
                    p->link = rt;
                    if (!p->up) {
                        p->up = rt;
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
        for (int i = 0 ; i < q ; i++) {  
            string T; cin >> T;
            insert(T , i);
        }
        buildAC();
        s = " " + s;
        vector<bool> ans(q,false);
        auto p = rt;    
        for (int i = 1 ; i < s.size() ; i ++) {
            char c = change(s[i]);
            p = p -> son[c];
            auto v = p -> up;
            while (v && v != rt) {
                for (auto x : v -> pos) {
                    ans[x] = true;
                }
                v = v -> link -> up;
            }
        }
        for (int i = 0 ; i < q ; i++) {
            cout << (ans[i] ? 'y' : 'n') << '\n';
        }
    }
    return 0;
}

