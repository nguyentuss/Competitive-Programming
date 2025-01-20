#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAX_N (int) (2e5 + 7)

struct node {
    int lv;
    bool isEnd;
    node *child[26];
};

node *root[2];
int f[MAX_N];
node *createNode() {
    node *ret = new node;
    ret -> isEnd = false;
    ret -> lv = 0;
    for (int i = 0 ; i <= 25 ; i++) {
        ret->child[i] = NULL;
    }
    return ret;
}


void add(string &s , int status) {
    node *p = root[status];
    int lv = 0;
    for (int i = 0 ; i < s.size() ; i++) {
        int pos = s[i] - 'a';
        if (p->child[pos] == NULL) {
            p->child[pos] = createNode();
        }
        p->lv = ++lv;
        p = p->child[pos];
    }
    p -> isEnd = true;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    root[0] = createNode();
    root[1] = createNode();
    cerr << "DEBUG";
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        add(s , 0);
    }
    int m; cin >> m;
    while (m--) {
        string s; cin >> s;
        add(s , 1);
    }
    
    return 0;
}