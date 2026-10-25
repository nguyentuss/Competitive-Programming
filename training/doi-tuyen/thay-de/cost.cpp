#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (1e5 + 7)

struct pos {
	int id , x , y , z;
};
struct edge{ 
	int u , v , w;
};

pos a[MAX_N]; 
int root[MAX_N];
vector<edge> v;
int n; 
bool cmp1(const pos &c , const pos &d) {
	return c.x < d.x;
}
bool cmp2(const pos &c , const pos &d) {
	return c.y < d.y;
}
bool cmp3(const pos &c , const pos &d) {
	return c.z < d.z;
}
bool cmp(const edge &u , const edge &v) {
	return u.w < v.w;
}

void init() {
	for (int i = 1 ; i < MAX_N ; i++) {
		root[i] = i;
	}
	return;
}

int findroot(int u) {
	if (u == root[u]) return u;
	else {
		return root[u] = findroot(root[u]);
	}
}

void unionset(int u , int v) {
	u = findroot(u);
	v = findroot(v);
	if (u != v) {
		root[u] = v;
	} 
	return;
}

void addnode(int status) {
	for (int i = 1 ; i < n ;i++) {
		if (status == 1) v.push_back({a[i].id , a[i + 1].id , abs(a[i].x - a[i + 1].x)});
		if (status == 2) v.push_back({a[i].id , a[i + 1].id , abs(a[i].y - a[i + 1].y)});
		if (status == 3) v.push_back({a[i].id , a[i + 1].id , abs(a[i].z - a[i + 1].z)});
	}
}

int check(int u , int v) {
	u = findroot(u);
	v = findroot(v);
	return (u != v);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("cost.inp","r",stdin);
	freopen("cost.out","w",stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].id = i;
	}	
	init();
	sort(a + 1 , a + 1 + n , cmp1);
	addnode(1);
	sort(a + 1 , a + 1 + n , cmp2);
	addnode(2);
	sort(a + 1 , a + 1 + n , cmp3);
	addnode(3);
	//for (auto x : v) cout << x.w << '\n';
	sort(v.begin() , v.end() , cmp);
	int ans = 0;
	for (auto x : v) {
		int u = x.u , v = x.v , w = x.w;
		if (check(u , v)) {
			unionset(u , v);
			ans += w;
		}
	}
	cout << ans;
	return 0;
}