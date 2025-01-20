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

int n , m; 
int a[N] , b[N];

struct node {
    bool isEnd;
    node *child[2];
};


node *createNode() {
    node *ret = new node;
    ret->isEnd = false;
    for (int i = 0 ; i < 2 ; i++) {
        ret->child[i] = NULL;
    }
    return ret;
}

node *root;

void insert(int x) {
    node *p = root;
    for (int i = 31 ; i >= 0 ; i--) {
        int bit = (x >> i)&1;
        if (p->child[bit] == NULL) {
            p->child[bit] = createNode();
        }
        p = p->child[bit];
    }
    return;
}

int calc(int x) {
    node *p = root;
    int ans = 0;
    for (int i = 31 ; i >= 0 ; i--) {
        int bit = (x >> i)&1;
        int rev = bit ^ 1;
        if (p->child[rev] != NULL) {
            ans = ans + rev*(1 << i);
            p = p->child[rev];
        }
        else {
            ans = ans + bit*(1 << i);
            p = p->child[bit];
        }
    }
    return ans;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n; 
    for (int i = 0 ; i < n ;i ++) cin >> a[i]; 
    cin >> m;
    for (int i = 0 ; i < m ;i ++) cin >> b[i];
    root = createNode();
    for (int i = 0 ; i < n ; i++) insert(a[i]); 
    for (int i = 0 ; i < m ; i++) {
        cout << calc(b[i]) << " ";
    }
    return 0;
}