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
const int inf = 1e9 + 7;
const int MAX_N = 1e6 + 1;
const int MOD = 1e9 + 7;

vector<int> IT(4 * MAX_N , inf);
int n , k;
int a[MAX_N];
vector<int> c(MAX_N , 0);

void update(int id , int i , int L , int R , int val) {
    if (i > R || i < L) return;
    if (L == R) {
        IT[id] = val;
        return;
    }
    int mid = (L + R)>>1;
    update(2 * id , i , L , mid , val);
    update(2 * id + 1 , i , mid + 1 , R , val);
    IT[id] = min(IT[2 * id + 1] , IT[2 * id]);
}

void build(int id , int l , int r) {
    if (l == r) {
        IT[id] = c[l];
        return;
    }
    int mid = (l + r)>>1;
    build(2*id , l , mid);
    build(2 * id + 1 , mid + 1 , r);
    IT[id] = min(IT[2 *id] , IT[2 * id + 1]); 
    return;
}

int get(int id , int l , int r , int L , int R) {
    if (l > R || r < L) return inf;
    if (l <= L && R <= r) {
        return IT[id]; 
    }
    int mid = (L + R)>>1; 
    return min(get(2 * id , l , r , L , mid),
    get(2 * id + 1 , l , r , mid + 1 , R));
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("tongmin.inp","r",stdin);
    freopen("tongmin.out","w",stdout);
    cin >> n >> k;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i];
    }
    sort(a + 1 , a + 1 + n);
    vector<int> f(MAX_N , inf);
    for (int i = 2 ; i <= n ; i++) {
        c[i] = a[i] - a[i - 1];
        //update(1 , i , 1 , n , a[i] - a[i - 1]);
    }
    c[1] = inf;
    build(1 , 1 , n);
    int left = 1;
    int ans = inf;
    for (int i = (n - k) ; i <= n ; i++) {
        int maxi = a[i] - a[left]; 
        int mini = get(1 , left , i , 1 , n);
        if (ans > (maxi + mini)) {
            ans = maxi + mini;
        }
        left++;
    }
    cout << ans;
    return 0;
}