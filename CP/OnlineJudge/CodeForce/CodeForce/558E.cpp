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
const int MAX_N = 1e5 + 7;
const int MOD = 1e9 + 7;

struct seg{
    int val , lazy;
};

seg IT[26][4 * MAX_N];
char a[MAX_N];
int n , d;

int ch(char x) {
    return (int) (x - 'a');    
}

void down(int id , int type , int l , int r , int mid) {
    int x = IT[type][id].lazy;
    if (x != -1 && l != r) {
    IT[type][2 * id].val = (mid - l + 1)*x;
    IT[type][2 * id + 1].val = (r - mid)*x;
    IT[type][2 * id].lazy = x;
    IT[type][2 * id + 1].lazy = x;
    IT[type][id].lazy = -1;
    }
    return;
}

void update(int id , int l , int r , int L , int R , int type , int val) {
    if (l > R || r < L) return;
    if (l <= L && R <= r) {
        IT[type][id].val = val*(R - L + 1);
        IT[type][id].lazy = val;
        return;
    }
    int mid = (L + R)/2;
    down(id , type , L , R , mid);
    update(2 * id , l , r , L , mid , type , val);
    update(2 * id + 1 , l , r , mid + 1 , R , type , val);
    IT[type][id].val = IT[type][2 * id].val + IT[type][2 * id + 1].val; 
    return;
}

int get(int id , int l , int r , int L , int R , int type) {
    if (l > R || r < L) return 0;
    if (l <= L && R <= r) {
        return IT[type][id].val;
    }
    int mid = (L + R)/2;
    down(id , type , L , R , mid);
    return (get(2 * id , l , r , L , mid , type) + get(2 * id + 1 , l , r , mid + 1 , R , type));
}

void calc(int l , int r , int k) {
    vector<int> cnt(26 , 0);
    for (int i = 0 ; i < 26; i++) {
        cnt[i] = get(1 , l , r , 1 , n , i);
    }
    //cout << cnt[25] << '\n';
    for (int i = 0 ; i < 26 ; i++) {
        update(1 , l , r , 1 , n , i , 0);
    }
    int pp = l;
    if (k == 1) {
        for (int i = 0 ; i < 26 ; i++) {
            if (cnt[i] != 0) {
                update(1 , pp , pp + cnt[i] - 1 , 1 , n , i , 1);
                pp += cnt[i];
            }
        }
    }
    else {
        for (int i = 25 ; i >= 0 ; i--) {
            if (cnt[i] != 0) {
                update(1 , pp , pp + cnt[i] - 1 , 1 , n , i , 1);
                pp += cnt[i];
            }
        }
    }
    
    return;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> d;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        update(1 , i , i , 1 , n , ch(a[i]) , 1);
    }
    for (int i = 1 ; i <= d ; i++) {
        int l , r , k; cin >> l >> r >> k;
        calc(l , r , k);
    }
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j < 26 ; j++) {
            int x = get(1 , i , i , 1 , n , j);
            if (x != 0) {
                cout << (char) (j + 'a');
                break;
            }
        }
    }
    return 0;
}