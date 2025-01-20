#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 3e5 + 7;
const int MOD = 1e9 + 7;

int IT[4*N];
int n , m;

void update(int id , int i , int l , int r , int val) {
    if (i > r || i < l) return;
    if (l == r){
        IT[id] += val;
        return;
    }
    int mid = (l + r)/2;
    update(2*id , i , l , mid , val);
    update(2*id + 1 , i , mid + 1 , r , val);
    IT[id] = IT[2 * id] + IT[2 * id + 1];
}

int get(int id , int l , int r , int val) {
    if (l == r) return l;
    int mid = (l + r)/2;
    if (IT[2 * id] >= val) {
        return get(2 * id , l , mid , val);
    }
    else {
        return get(2 * id + 1 , mid + 1 , r , val - IT[2*id]);
    }

}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for (int i = 1 ; i <= n ;i ++) {
        update(1 , i , 1 , n , 1);
    }
    int last = n;
    for (int i = 1 ; i <= m ; i++) {
        int x; cin >> x;
        if (x > last) {
            cout << 0 << '\n';
        }
        else {
            cout << get(1 , 1 , n , x) << '\n';
            update(1 , d , 1 , n , -1);
            last--;
        }
    }
    return 0;
}
