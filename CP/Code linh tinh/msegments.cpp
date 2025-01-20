#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

struct seg {
	int val;
	int lazy;
};

struct vvv {
    int fi , se , id;
};

seg IT[4*N];
vvv a[N];
int n , m;

void down(int id) {
	int x = IT[id].lazy;
	IT[2*id].lazy += x;
	IT[2*id].val += x;
	IT[2*id + 1].lazy += x;
	IT[2*id + 1].val += x;
	IT[id].lazy = 0;
}

void update(int id , int l , int r , int queryL , int queryR , int x) {
	if (r < queryL || l > queryR) return;
	if (queryL <= l && r <= queryR) {
		IT[id].val += x;
		IT[id].lazy += x;
		return;
	}
	down(id);
	int mid = (l + r)/2;
	update(2*id , l , mid , queryL , queryR , x);
	update(2*id + 1 , mid + 1 , r , queryL , queryR , x);
	IT[id].val = max(IT[2*id].val , IT[2*id + 1].val);
	return ;
}

int get(int id , int l , int r , int queryL , int queryR) {
	if (r < queryL || l > queryR) return 0;
	if (queryL <= l && r <= queryR) return IT[id].val;
	down(id);
	int mid = (l + r)/2;
	return max(get(2*id , l , mid , queryL , queryR) ,
		get(2*id + 1 , mid + 1 , r , queryL , queryR));

}

bool cmp(vvv a , vvv b) {
    return (a.se < b.se || (a.se == b.se && a.fi > b.fi));
}

main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n , k; cin >> n >> k;
    for (int i = 1 ; i <= n ;i ++) {
        cin >> a[i].fi >> a[i].se;
        a[i].id = i;
    }
    sort(a + 1 , a + 1 + n , cmp);
    // for (int i = 1 ; i <= n ;i ++) {
    //     cout << a[i].fi << " " << a[i].se << '\n';
    // }
    int ans = 0;
    vector<int> trace;
    for (int i = 1 ; i <= n ;i ++) {
        int val = get(1 , 1 , N - 1 , a[i].fi , a[i].se);
        if (val == k) {
            ans++; 
            trace.push_back(a[i].id); 
        }
        else update(1 , 1 , N - 1 , a[i].fi , a[i].se , 1);
    }
    cout << ans << '\n'; 
    for (auto x : trace) {
        cout << x << " ";
    }
	return 0;
}
