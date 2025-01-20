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
const int inf = 1e18 + 7;
const int MAX_N = 2e5 + 7;
const int MOD = 1e9 + 7;

struct iterval {
    int maxi , mini , idmin , idmax;
};

iterval IT[4 * MAX_N];

int n , m;
int d[2 * MAX_N];
int h[2 * MAX_N];
int f[2 * MAX_N];
int f1[2 * MAX_N];
int f2[2 * MAX_N];

void update(int id , int i , int L , int R , int type , int val) {
    if (i < L || i > R) return;
    if (L == R) {
        if (type) {
            //if (IT[id].maxi < val) {
                IT[id].maxi = val;
                IT[id].idmax = i;
           // }
            //IT[id].maxi = max(IT[id].maxi , val);
        }
        else {
            //if (IT[id].mini > val) {
                IT[id].mini = val;
                IT[id].idmin = i;
            //}
            //IT[id].mini = min(IT[id].mini , val);
        }
        return;
    }
    int mid = (L + R)/2;
    update(2 * id , i , L , mid , type , val);
    update(2 * id + 1 , i , mid + 1 , R , type , val);
    if (IT[2 * id].maxi > IT[2 * id + 1].maxi) {
        IT[id].maxi = IT[2 * id].maxi;
        IT[id].idmax = IT[2 * id].idmax;
    }
    else {
        IT[id].maxi = IT[2 * id + 1].maxi;
        IT[id].idmax = IT[2 * id + 1].idmax;
    }
    //IT[id].maxi = max(IT[2 * id].maxi , IT[2 * id + 1].maxi);
    if (IT[2 * id].mini < IT[2 * id + 1].mini) {
        IT[id].mini = IT[2 * id].mini;
        IT[id].idmin = IT[2 * id].idmin;
    }
    else {
        IT[id].mini = IT[2 * id + 1].mini;
        IT[id].idmin = IT[2 * id + 1].idmin;
    }
    //IT[id].mini = min(IT[2 * id].mini , IT[2 * id + 1].mini);
    return;
}

pair<int , int> get(int id , int l , int r , int L , int R , int type) {
    if (r < L || l > R) {
        if (type) return ii(0 , 0);
        else return ii(inf , 0);
    }
    if (l <= L && R <= r) {
        if (type) return ii(IT[id].maxi , IT[id].idmax);
        else return ii(IT[id].mini , IT[id].idmin);
    }
    int mid = (L + R)/2;
    if (type) {
        auto tmp1 = get(2 * id , l , r , L , mid , type);
        auto tmp2 = get(2 * id + 1 , l , r , mid + 1,  R , type);
        if (tmp1.first > tmp2.first) {
            return tmp1;
        }
        else {
            return tmp2;
        }
        //return max(get(2 * id , l , r , L , mid , type) , get(2 * id + 1, l , r , L , mid , type));
    }
    else {
        auto tmp1 = get(2 * id , l , r , L , mid , type);
        auto tmp2 = get(2 * id + 1 , l , r , mid + 1,  R , type);
        if (tmp1.first < tmp2.first) {
            return tmp1;
        }
        else {
            return tmp2;
        }
        //return min(get(2 * id , l , r , L , mid , type) , get(2 * id + 1 , l , r , mid + 1 , R , type));
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n , m; cin >> n >> m;
    for (int i = 1 ; i <= n ; i++) {
        cin >> d[i];
    }
    for (int i = 1 ; i <= n ; i++) {
        cin >> h[i];
    }
    for (int i = n + 1 ; i <= 2*n - 1 ; i++) {
        h[i] = h[i - n];
        d[i] = d[i - n];
    }
    for (int i = 1 ; i <= 2*n - 1 ; i++) {
        f[i] = f[i - 1] + d[i];
        f1[i] = f[i - 1] - 2*h[i];
        f2[i] = f[i - 1] + 2*h[i];
        update(1 , i , 1 , 2 * n - 1 , 0 , f1[i]);
        update(1 , i , 1 , 2 * n - 1 , 1 , f2[i]);
    }
    for (int i = 1 ; i <= 2 * n - 1 ; i++) {
        cerr << f1[i] << " ";
    }
    cerr << '\n';
    for (int i = 1 ; i <= 2 * n - 1 ; i++) {
        cerr << f2[i] << " ";
    }
    for (int i = 1 ; i <= m ; i++) {
        int a , b; cin >> a >> b;
        if (a <= b) {
            //cout << b + 1 << " " << b + (n - (b - a + 1)) << '\n';
            auto max1 = get(1 , b + 1 , b + (n - (b - a + 1)) , 1 , 2 * n - 1 , 1);
            auto min1 = get(1 , b + 1 , b + (n - (b - a + 1)) , 1 , 2 * n - 1 , 0);
            update(1 , min1.se , 1 , 2 * n - 1 , 0 , inf);
            auto min2 = get(1 , b + 1 , b + (n - (b - a + 1)) , 1 , 2 * n - 1 , 0);
            update(1 , min1.se , 1 , 2 * n - 1 , 0 , f1[min1.se]);
            update(1 , max1.se , 1 , 2 * n - 1 , 1 , -inf);
            auto max2 = get(1 , b + 1 , b + (n - (b - a + 1)) , 1 , 2 * n - 1 , 1);
            update(1 , max1.se , 1 , 2 * n - 1 , 1 , f2[max1.se]);
            int ans = -inf;
            //cout << max1.fi << " " << max2.fi << " " << min1.fi << " " << min2.fi << '\n';
            if (max1.se == min1.se) 
                ans = max({ans , max1.fi - min2.fi , max2.fi - min1.fi});
            else ans = max(ans , max1.fi - min1.fi);
            cout << ans << '\n';
            //cout << x.first << " " << x.second << '\n';
            //cout << get(1 , b + 1 , b + (n - (b - a + 1)) , 1 , 2 * n - 1 , 1) - get(1 , b + 1 , b + (n - (b - a + 1) - 1) , 1 , 2 * n - 1 , 0) << '\n';
        }
        else {
            b += n;
            //auto x = get(1 , b - n + 1, a - 1 , 1 , 2 * n - 1 , 1);
            auto max1 = get(1 , b - n + 1, a - 1 , 1 , 2 * n - 1 , 1);
            auto min1 = get(1 , b - n + 1, a - 1 , 1 , 2 * n - 1 , 0);
            update(1 , min1.se , 1 , 2 * n - 1 , 0 , inf);
            auto min2 = get(1 , b - n + 1, a - 1 , 1 , 2 * n - 1 , 0);
            update(1 , min1.se , 1 , 2 * n - 1 , 0 , f1[min1.se]);
            update(1 , max1.se , 1 , 2 * n - 1 , 1 , -inf);
            auto max2 = get(1 , b - n + 1, a - 1 , 1 , 2 * n - 1 , 1);
            update(1 , max1.se , 1 , 2 * n - 1 , 1 , f2[max1.se]);
            int ans = -inf;
            if (max1.se == min1.se) 
                ans = max({ans , max1.fi - min2.fi , max2.fi - min1.fi});
            else ans = max(ans , max1.fi - min1.fi);
            cout << ans << '\n';
            //cout << get(1 , b - n + 1, a - 1 , 1 , 2 * n - 1 , 1) - get(1 , b - n + 1 , a - 1 , 1 , 2 * n - 1 , 0) << '\n';
        }
    }
    return 0;
}


//i : 1 2 3 4 5 6 7 8 9

//d : 2 2 2 2 2 2 2 2 2 
//h : 3 5 2 1 4 3 5 2 1