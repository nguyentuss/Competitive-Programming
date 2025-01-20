#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

struct segment{
	double a,b,c;
}v[300005];

bool compare(segment &a, segment &b) {
	return (a.c < b.c);
}

int main() {
	boost;
	int n;
	cin >> n;
	for (int i = 1 ;i <= n; i++){
		cin >> v[i].a >> v[i].b;
		v[i].c = v[i].a / v[i].b;
	}

	sort(v+1,v+n+1,compare);
	for (int i = 1 ; i <= n ; i++) 
		cout << v[i].a << " " << v[i].b << endl;


	return 0;
}