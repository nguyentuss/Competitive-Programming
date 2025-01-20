#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
#define fi freopen("pearl.inp","r",stdin);
#define fo freopen("pearl.out","w",stdout);

vector <long long > ti;
vector <long long > teo;
long long  a , b;

struct segment{
	long long l , r , ID;
	bool operator <(const segment &b) {
		if (l < b.l || (l == b.l && r < b.r))
			return true;
		else return false;
	}
}v[300005];

int main() {
	boost;
	fi;fo;
	long long  n; cin >> n;
	for (long long  i = 0 ; i < n; i++) {
		cin >> a;
		ti.push_back(a);
	}
	for (long long  i = 0 ; i < n ;i ++) {
		cin >> b;
		teo.push_back(b);
	}
	for (long long  i = 0 ; i < n; i++) {
		if (ti[i] > teo[i]) {
			v[i].l = ti[i];
			v[i].r = teo[i];
			v[i].ID = i;
		}
		else {
			v[i].l = teo[i];
			v[i].r = ti[i];
			v[i].ID = i;
		}
	}
	sort(v,v + n);
	reverse(v,v + n);

	//for (long long  i = 0 ; i < n ;i ++) cout << v[i].l << " " << v[i].r << " " << v[i].ID << endl;

	a = 0 , b = 0 ;

	for (long long  i = 0 ; i < n ;i ++ ) {
		if ((i + 1) % 2 != 0) {
			a += ti[v[i].ID];
		}
		else {
			b += teo[v[i].ID];
		}
	}

	cout << a - b;

	return 0; 
}