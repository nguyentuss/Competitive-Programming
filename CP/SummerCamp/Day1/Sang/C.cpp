#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
const int inf = 1e9 + 7;
const int MAX_N = 2e5 + 7 ;
const int MOD = 1e9 + 7;

struct node{
	int sum , ver;
    node *l , *r;
    node() {
        sum = ver = 0;
        l = r = nullptr;
    }
};

int a[MAX_N];
node *tree[MAX_N];

int sum(node *x) {
    if (!x) return 0;
    return x -> sum;
}

void build(node *cur , int l , int r) {
	if (l == r) {
        cur -> sum = 0; 
        return;
    }   
    cur -> l = new node();
    cur -> r = new node();
    int mid = (l + r)>>1;
    build(cur -> l , l , mid);
    build(cur -> r , mid + 1 , r);
    cur->sum = sum(cur->l) + sum(cur->r);
    return;
}

void update(node *cur, node *prev , int i , int l , int r , int val , int ver) {
    if (i > r || i < l) return;
    if (l == r) {
        cur -> sum = val;
        return;
    }
    int mid = (l + r)>>1; 
    if (i <= mid) {
        if (!cur->l || cur->l->ver < ver) {
            cur -> l = new node();
            cur -> l -> ver = ver;
        }
        update(cur->l , prev->l , i , l , mid , val , ver);
        if (!cur->r) cur -> r = prev -> r;
    }
    else {
        if (!cur->r || cur->r->ver < ver) {
            cur -> r = new node();
            cur -> r -> ver = ver;
        }
        update(cur->r , prev->r , i , mid + 1 , r , val , ver);
        if (!cur->l) cur->l = prev -> l;
    }
    cur->sum = sum(cur->l) + sum(cur->r);
    return;
}

int get(node *cur , int l , int r , int L , int R) {
    if (l > R || r < L) return 0;
    //cerr << L << " " << R << cur->sum << '\n';
    if (l <= L && R <= r) return cur->sum;
    int mid = (L + R)>>1;
    
    int x1 = get(cur->l , l , r , L , mid);
    int x2 = get(cur->r , l , r , mid + 1 , R);
    return (x1 + x2);
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n , q; cin >> n >> q;
	for (int i = 1 ; i <= n ;i ++)
		cin >> a[i];
    tree[0] = new node(); 
    build(tree[0] , 1 , n);
    map<int , int> last;
    for (int i = 1 ; i <= n ; i++) {
        tree[i] = new node();
        tree[i] -> ver = i;
        if (last.count(a[i])) {
            update(tree[i] , tree[i - 1] , last[a[i]] , 1 , n , 0 , i);
        }
        last[a[i]] = i;
        update(tree[i] , tree[i-1] , i , 1 , n , 1 , i);
    }
    int tmp = 0;
    for (int i = 1 ; i <= q ; i++) {
        int u , v ; cin >> u >> v;
        int lp = ((u + tmp)%n) + 1;
        int rp = ((v + tmp)%n) + 1;    
        int l = min(lp , rp);
        int r = max(lp , rp);
        tmp = get(tree[r] , l , r , 1 , n);
        cout << tmp << '\n';
    }
    return 0;
}