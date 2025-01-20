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
int a[N];
void update(int id, int l, int r, int i, int val)
{
    if (i < l || i > r){
        return;
    }
    if (l == r)
    {
        IT[id] = val;
        return;
    }
    int mid = (l + r)/2;
    update(id*2, l, mid, i , val);
    update(id*2 + 1, mid + 1, r, i , val);
    IT[id] = max(IT[id*2], IT[id*2 + 1]);
    return;
}

int get(int id, int l, int r, int L, int R){
    if (L > r || R < l) return 0;
    if (L <= l && R >= r) return IT[id];
    int mid = (l + r)/2;
    int curr1 = get(id * 2, l, mid, L, R);
    int curr2 = get(id*2 + 1, mid + 1, r, L, R);
    return max(curr1, curr2);
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1 ; i <= 4*n ; i++) {
            IT[i] = 0; 
        }
        int ans = 0;
        for (int i = 1 ; i <= n ; i++) {
            cin >> a[i];
        }
        update(1, 1, n, a[1], 1);
        int cnt = 0;
        for (int i = 2 ; i <= n ; i++) {
            int x = get(1 , 1 , n , 1 , a[i]);
            if (x == true) {
                ans ++;
            }
            update(1 , 1 , n , a[i] , x + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}