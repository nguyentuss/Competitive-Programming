#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e6 + 7)

#define int long long

int n;
int L[MAX_N] , R[MAX_N];
int v[MAX_N] , sum[MAX_N];
int IT_min[4*MAX_N] , IT_max[4*MAX_N];

void update_min(int id , int l , int r , int i) {
    if (i < l || i > r) return;
    if (l == r) {
        IT_min[id] = sum[i];
        return;
    }
    int mid = (l + r)/2;
    update_min(2*id , l , mid , i);
    update_min(2*id + 1 , mid + 1, r , i);
    IT_min[id] = min(IT_min[2*id] , IT_min[2*id + 1]);
    return;
}

void update_max(int id , int l , int r , int i) {
    if (i < l || i > r) return;
    if (l == r) {
        IT_max[id] = sum[i];
        return;
    }
    int mid = (l + r)/2;
    update_max(2*id , l , mid , i);
    update_max(2*id + 1 , mid + 1 , r , i);
    IT_max[id] = max(IT_max[2*id] , IT_max[2*id + 1]);
    return;
}

int get_min(int id , int l , int r , int L , int R) {
    if (l > R || L > r) return LLONG_MAX;
    if (L <= l && r <= R) return IT_min[id];
    int mid = (l + r)/2;
    return min(get_min(2*id , l , mid , L , R) ,
               get_min(2*id + 1, mid + 1 , r , L , R));
}

int get_max(int id , int l , int r , int L , int R) {
    if (l > R || L > r) return LLONG_MIN;
    if (L <= l && r <= R) return IT_max[id];
    int mid = (l + r)/2;
    return max(get_max(2*id , l , mid , L , R) ,
               get_max(2*id + 1 , mid + 1 , r , L , R));
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    cout.tie(NULL);
    //freopen("1359D.inp","r",stdin);
    //freopen("1359D.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
        cin >> v[i];
    update_min(1 , 0 , n , 0);
    update_max(1 , 0 , n , 0);
    for (int i = 1 ; i <= n ; i++) {
        sum[i] = sum[i - 1] + v[i];
        update_min(1 , 0 , n , i);
        update_max(1 , 0 , n , i);
    }
    deque<int> dq;
    v[0] = LLONG_MAX;
    dq.push_back(0);
    for (int i = 1 ; i <= n ;i++) {
        while (dq.size() && v[dq.back()] <= v[i]) dq.pop_back();
        if (dq.empty()) L[i] = i;
        else L[i] = dq.back() + 1;
        dq.push_back(i);
    }
    while (dq.size()) dq.pop_back();
    v[n+1] = LLONG_MAX;
    dq.push_back(n + 1);
    for (int i = n ; i >= 1 ; i--) {
        while (dq.size() && v[dq.back()] <= v[i]) dq.pop_back();
        if (dq.empty()) R[i] = i;
        else R[i] = dq.back() - 1;
        dq.push_back(i);
    }
    int ans = LLONG_MIN;
    for (int i = 1 ; i <= n ;i ++) {
        int right = sum[i];
        int left = get_min(1 , 0 , n , L[i] - 1 , i - 1);
        if (i + 1 <= R[i]) right = get_max(1 , 0 , n , i , R[i]);
        //cout << L[i] << " " << R[i] << " " << left << " " << right << " " << sum[i - 1] - left << " " << right - sum[i] << '\n';
        ans = max(ans , sum[i - 1] - left + right - sum[i]);
    }
    cout << ans;
    return 0;
}
