//source:: 
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
  
const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

struct node {
    int sum , ver;
    node *l , *r; 
    node() {
        sum = 0 , l = r = nullptr;
        ver = 0;
    }
};

node *IT[N];
int a[N];

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
    int mid = (l + r) >> 1;
    build(cur -> l , l , mid);
    build(cur -> r , mid + 1 , r);
    cur -> sum = sum(cur->l) + sum(cur->r);
}

void update(node *cur , node *prev , int l , int r , int pos) {
    if (pos > r || pos < l) return;
    if (l == r) {
        cur -> sum = prev -> sum + 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        if (!cur -> l) {
            cur -> l = new node();
            //cur -> l -> ver = ver;
        }
        update(cur -> l , prev -> l , l , mid , pos);
        if (!cur -> r) cur -> r = prev -> r;
    }
    else {
        if (!cur -> r) {
            cur -> r = new node();
            //cur -> r -> ver = ver;
        }
        update(cur -> r , prev -> r , mid + 1 , r , pos);
        if (!cur -> l) cur -> l = prev -> l;
    }
    cur->sum = sum(cur->l) + sum(cur->r);
}

int get(node *left , node *right , int l , int r , int k) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int left_count = (right->l->sum) - (left->l->sum);
    //cerr << l << " " << mid << " " << left_count << '\n';
    if (left_count >= k) 
        return get(left -> l, right -> l , l , mid , k);
    else 
        return get(left -> r,right -> r , mid + 1 , r , k - left_count);
    //return 0;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
        int n , q; cin >> n >> q;
        set<int> s;
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        int num = 0;
        map<int , int> mp;
        map<int , int> rev;
        for (auto x : s) mp[x] = num++;
        int tl = 0 , tr = num - 1;
        IT[0] = new node(); 
        build(IT[0] , tl , tr);
        for (int i = 1 ; i <= n ; i++) {
            rev[mp[a[i]]] = a[i];
        }
        for (int i = 1 ; i <= n ; i++) {
            a[i] = mp[a[i]];
            //cout << a[i] << " ";
            IT[i] = new node();
            update(IT[i] , IT[i - 1] , tl , tr , a[i]);
        }
        //cout << '\n';
        while (q--) {
            int l , r , k; cin >> l >> r >> k;
            cout << rev[get(IT[l] , IT[r] , tl , tr , k + 1)] << '\n';
        }
    }
    return 0;
}   