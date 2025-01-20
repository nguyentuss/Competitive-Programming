//source:: 
#include <bits/stdc++.h>

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

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

ii a[N];
int b[N];
int f[N];
int fw[N];

void update(int x,int k){
    for (int i = x; i <= N;i += i&-i) {
        fw[i] = max(fw[i] , k);
    }
}
int query(int x){
    int ans = 0;
    for (int i = x;i;i-= i&-i){
        ans = max(ans,fw[i]);
    }
    return ans;
}
 

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int test = 1; 
    //cin >> test;
    while (test--) {
		int n; cin >> n;
		for (int i = 1 ; i <= n ; i++) {
			cin >> b[i];
			a[i].second = b[i];
			a[i].first = i - b[i];
		}
		sort(a + 1 , a + 1 + n , [&](const ii &a , const ii &b){
			if (a.fi == b.fi) return a.se < b.se;
			return a.fi < b.fi;
		});
		int ans = 0;
		for (int i = 1 ; i <= n ; i++) {
			if (a[i].first < 0) continue;
			f[i] = query(a[i].second) + 1;
			update(a[i].second + 1, f[i]); 
			ans = max(ans , f[i]);
		}
		cout << ans; 
	}
    return 0;
}