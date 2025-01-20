#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("chocolate.inp","r",stdin);
#define fo freopen("chocolate.out","w",stdout);

typedef pair<unsigned long long,unsigned long long> ii;

int main() {
	boost; 
	//fi;fo;

	unsigned long long n, b; cin >> n >> b;

	vector<ii> v;

	unsigned long long x, y;

	for (unsigned long long i = 0 ; i < n; i++) {
		cin >> x >> y ;
		v.push_back(ii(x,y));
	}
	sort(v.begin(),v.end ());

	unsigned long long ans = 0;

	for (unsigned long long i = 0 ; i < n ; i++) {
		if (b / v[i].first >= v[i].second) {
			ans += v[i].second;
			b -= v[i].first*v[i].second;
		}	
		else {
			ans += (unsigned long long) b / v[i].first;
			break;
		}
	}

	cout << ans;

	return 0;
}	