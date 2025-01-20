//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define int long long	
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e18 + 7;
int r = 0;
double x[1001],W,level;
bool found;

void solve() {  
    x[0] = 0.;
	cout.precision(2);
	cout << fixed;
    int m , n;
	while(cin >> m >> n && n && m){
		m*=n;
		for(int i=1;i<=m;i++) cin >> x[i];
		cin >> W;
		sort(x+1,x+m+1);
		found = false;
		for(int i=1;i<m;i++){
			level = (i)*(x[i+1]-x[i])*100;
			if(W>level) W-=level;
			else{
				found = true;
				if(!W){
					level = x[i-1];
					W = 100.*(i-1)/m;
				}
				else{
					level = W/(i)/100. + x[i];
					W = 100.*i/m;
				}
				break;
			}
		}
		if(!found){
			level = W/m/100. + x[m];
			W = 100.;
		}
		cout << "Region " << ++r << endl;
		cout << "Water level is " << level << " meters." << endl;
		cout << W << " percent of the region is under water." << endl << endl;
	}
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int test = 1; 
    //cin >> test; 
    while (test--) {
       solve();
    }
}