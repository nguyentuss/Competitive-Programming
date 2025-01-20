#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("nksgame.inp","r",stdin);
#define fo freopen("nksgame.out","w",stdout);
#define ii pair<int,bool>
#define INF (long long) 1e-18 + 7;

vector <ii> v;
int ans = 0;

int main() {
	boost;
	//fi;fo;
	int n , x; cin >> n;

	for (int i = 1 ; i <= n ; i++) {
		cin >> x;
		v.push_back(ii(x,true));
	}
	for (int i = 1 ; i <= n ; i++) {
		cin >> x;
		v.push_back(ii(x,false));
	}
	ans = INF;
	sort(v.begin() , v.end());
	for (int i = 0 ; i < (int) v.size() - 1; i++) {
		if ((v[i].second == true && v[i+1].second == false) || (v[i].second == false && v[i+1].second == true)) {
			ans = min(ans,v[i] + v[i+1]);
		}
	}

	cout << ans;
	return 0;;
}