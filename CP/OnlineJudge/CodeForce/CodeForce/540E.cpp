#include <bits/stdc++.h>
 
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
 
#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long
const int inf = 1e9 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

struct iterval {
   int v1 , v2 , v3;
};

bool cmp1(iterval &a , iterval &b) {
    return a.v2 < b.v2;
}

bool cmp2(iterval &a , iterval &b) {
    return a.v2 > b.v2;
}

map<int , int> m;
ii a[MAX_N];
int n;
iterval IT[4 * MAX_N];

void update(int id , int i , int l , int r, int type , int val) {
    if (i < l || i > r) return;
    if (l == r) {
        if (type == 1) IT[id].v1 = val;
        else if (type == 2) IT[id].v2 = val;
        else if (type == 3) IT[id].v3 = val;
        return;
    }
    int mid = (l + r)/2;
    update(2 * id , i , l , mid , type , val);
    update(2 * id + 1, i , mid + 1 , r , type , val);
    if (type == 1) IT[id].v1 = IT[2 * id].v1 + IT[2 * id + 1].v1;
    if (type == 2) IT[id].v2 = IT[2 * id].v2 + IT[2 * id + 1].v2;
    if (type == 3) IT[id].v3 = IT[2 * id].v3 + IT[2 * id + 1].v3;
    return;
}

int get(int id , int l , int r , int L , int R , int type) {
    if (l > R || r < L) return 0;
    if (l <= L && R <= r) {
        if (type == 1) return IT[id].v1;
        if (type == 2) return IT[id].v2;
        if (type == 3) return IT[id].v3;
    }
    int mid = (L + R)/2;
    return (get(2 *id , l , r , L , mid , type) + get(2 * id + 1 , l , r , mid + 1 , R , type));
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i].fi >> a[i].se;
        if (!m[a[i].se]) m[a[i].se] = a[i].se;
        if (!m[a[i].fi]) m[a[i].fi] = a[i].fi;
        swap(m[a[i].se] , m[a[i].fi]);
    }
    map<int , int> pos;
    vector<iterval> arr;
    int cnt = 0;
    for (auto x : m) {
        arr.push_back({x.fi , x.se , ++cnt});
        pos[x.fi] = cnt;
        //cout << x.fi << " " << x.se << " " << cnt << '\n';
        // v1 , v1 , v3;   
    }
    for (auto x : arr) 
        update(1 , x.v3 , 1 , 2*n , 1 , 1);
    int ans = 0;
    for (auto x : arr) {
        int l = pos[x.v2];
        int r = x.v3;
        if (l > r) swap(l , r);
        //cerr << l << " " << r << '\n';
        if (l <= r) {
            int len = abs(x.v1 - x.v2) + 1;
            //cerr << len << " ";
            //cerr << len - get(1 , l , r , 1 , 2*n , 1) << '\n';
            ans = ans + len - get(1 , l , r , 1 , 2 * n , 1);
        }
    }
    int total = 0;
    vector<iterval> b;
    b = arr;
    sort(b.begin() , b.end() , cmp1);
    for (auto x : b) {
        update(1 , x.v3 , 1 , 2*n , 2 , 1);
        update(1 , x.v3 , 1 , 2*n , 3 , 1);
    }
    int counted = 0;
    for (auto x : b) {
        update(1 , x.v3 , 1 , 2 * n , 2 , 0);
        total += get(1 , 1 , x.v3 - 1 , 1 , 2 * n  , 2);
        //cerr << get(1 , 1 , x.v3 - 1 , 1 , 2 * n  , 1) << '\n';
    }
    sort(b.begin() , b.end() , cmp2);
    for (auto x : b) {
        update(1 , x.v3 , 1 , 2 * n , 3 , 0);
        total += get(1 , x.v3 + 1 , 2 * n , 1 , 2 *n , 3);
        //cerr << get(1 , x.v3 + 1 , 2 * n , 1 , 2 *n , 3) << '\n';
    }
    cout << ans + total/2;
    return 0;
}

// ta sẽ xử lí được những thằng nào đã đổi và đang đưng vị trí ở đâu

// ta gọi len = b[a[i]] - a[i] + 1

// với index của a[i] (gọi là b[a[i]]) sau khi swap mà > a[i]
// ta sẽ kiểm tra trong đoạn [a[i] , b[a[i]]] có bao nhiêu số nhỏ hơn a[i] , ta gọi nó là lấy len - đám đó


// với index của a[i] (gọi là b[a[i]]) sau khi swap mà < a[i]
// ta sẽ kiểm tra trong đoạn [a[i] , b[a[i]]] có bao nhiêu số nhỏ hơn a[i] , ta gọi nó là lấy len - đám đó