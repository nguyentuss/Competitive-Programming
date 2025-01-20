#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (3*1e5 + 7)

struct edge {
	int u , v , c;
};

struct gr3D{
	int ID , x , y , z;
};

bool cmp1(gr3D &a , gr3D &b) {
	return a.x < b.x;
}

bool cmp2(gr3D &a , gr3D &b) {
	return a.y < b.y;
}

bool cmp3(gr3D &a , gr3D &b) {
	return a.z < b.z;
}

bool cmp(edge &a , edge &b) {
	return a.c < b.c;
}

vector<edge> adj;
vector<gr3D> v; 
int root[MAX_N];

void addnode(int status) {
	for (int i = 0 ; i < v.size() - 1 ; i ++) {
		int id = v[i].ID , next = v[i + 1].ID;
		int val;
		if (status == 1) val = abs(v[i].x - v[i + 1].x);
		if (status == 2) val = abs(v[i].y - v[i + 1].y);
		if (status == 3) val = abs(v[i].z - v[i + 1].z);
		adj.push_back({id , next , val});
	}
}

int findroot(int u) {
	if (u == root[u]) return u;
	else {
		root[u] = findroot(root[u]);
		return root[u];
	}
}

void unionset(int u , int v) {
	int rootu = findroot(u);
	int rootv = findroot(v);
	if (rootu != rootv) {
		root[rootu] = rootv;
	}
}

bool check(int u , int v) {
	int rootu = findroot(u);
	int rootv = findroot(v);
	return (rootu == rootv);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1 ; i <= n ; i++) {
		int x , y , z; cin >> x >> y >> z;
		v.push_back({i , x , y , z});
	}
	for (int i = 1 ; i < MAX_N ; i++) root[i] = i;
	sort(v.begin() , v.end() , cmp1);
	addnode(1);
	sort(v.begin() , v.end() , cmp2);
	addnode(2);
	sort(v.begin() , v.end() , cmp3) ;
	addnode(3);
	sort(adj.begin() , adj.end() , cmp);
	int ans = 0;
	for (auto e : adj) {
		if (!check(e.u , e.v)) {
			unionset(e.u , e.v);
			ans += e.c;
		}
	}
	cout << ans << '\n';
	return 0;
}