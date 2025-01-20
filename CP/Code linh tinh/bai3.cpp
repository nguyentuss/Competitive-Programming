#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

struct segment{
	int a,b;
	double c;
}v[300005];

bool compare(segment &a, segment &b) {
	return (a.c < b.c);
}

int main() {
	boost;
	// freopen("inp.inp","r",stdin);
	int n;
	cin >> n;
	for (int i = 1 ;i <= n; i++){
		cin >> v[i].a >> v[i].b;
		v[i].c = (double) v[i].a / v[i].b;
	}

	sort(v+1,v+n+1,compare);
	for (int i = 1 ; i <= n ; i++){ 
		double divide =__gcd(v[i].a,v[i].b);
		if (v[i].b / divide != 1 && v[i].b / divide != -1)cout << (v[i].a / divide) << " " << (v[i].b / divide) << endl;
		else cout << v[i].a / divide << endl; 
	}

	return 0;
}