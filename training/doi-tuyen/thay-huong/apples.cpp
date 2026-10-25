#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct seg {
	ll x , y;
	ll id;
};

struct vec{
	ll x , y;
};


seg vect(seg A , seg B) {
	return (seg) {B.x - A.x , B.y - A.y , 0};
}

bool ccw(vec A, vec B) {
    return A.x * B.y > A.y * B.x;
}

seg A;
bool cmp(seg &B , seg &C) {
	seg tmp;
	tmp = vect(A , B);
	vec AB = (vec) {tmp.x , tmp.y};
	tmp = vect(A , C);
	vec AC = (vec) {tmp.x , tmp.y};
	ll x = ccw(AB , AC);
	//cout << x << '\n';
	if (x > 0) return false;
	return true;
}

ll n;
vector <seg> v;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("apples.inp","r",stdin);
	freopen("apples.out","w",stdout);
	cin >> n;
	ll xmin = LLONG_MAX;
	seg tmp;
	for (ll i = 0 ; i < n; i++) {
		ll x , y ; cin >> x >> y;
		if (xmin > y) {
			xmin = y;
			tmp.x = x , tmp.y = y , tmp.id = i;
		}
		v.push_back((seg) {x , y , i});
	}
	//cout << tmp.x << " " << tmp.y << '\n';

	swap(v[0] , v[tmp.id]);
	A.x = tmp.x , A.y = tmp.y;
	sort(v.begin() + 1 , v.end() , cmp);
	//for (auto e : v) cout << e.x << " " << e.y << " " << e.id << '\n';
	cout << v[0].id + 1 << " " << v[n/2].id + 1;
	return 0;
}