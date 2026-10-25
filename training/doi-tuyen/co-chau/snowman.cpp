#include <bits/stdc++.h>

using namespace std;

#define u_b upper_bound
#define ii pair<int,int>
#define f first
#define s second

struct num {
	int a , b , c;
};

vector<num> v;
priority_queue<ii , vector<ii>> pq;

unordered_map<int , int> m;

bool check() {
	return (pq.size());
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("snowman.inp","r",stdin);
	freopen("snowman.out","w",stdout);
	int n; cin >> n;
	for (int i = 0 ; i < n ; i++) {
		int x; cin >> x;
		m[x]++;
	}
	for (auto it : m) 
		pq.push(ii(it.second , it.first));
	while (!pq.empty()) {
		auto a = pq.top();
		if (check()) pq.pop();
		else break;
		auto b = pq.top();
		if (check()) pq.pop();
		else break;
		auto c = pq.top();
		if (check()) pq.pop();
		else break;
		if ((a.f - 1)) pq.push(ii(a.f - 1 , a.s));
		if ((b.f - 1)) pq.push(ii(b.f - 1 , b.s)); 
		if ((c.f - 1)) pq.push(ii(c.f - 1 , c.s));
		v.push_back({a.s , b.s , c.s});
	}
	cout << v.size() << '\n';
	for (auto it : v) {
		vector<int> tmp;
		tmp.push_back(it.a);
		tmp.push_back(it.b);
		tmp.push_back(it.c);
		sort(tmp.begin() , tmp.end() , greater<int>());
		for(auto e : tmp) cout << e << " ";
		cout << '\n';
	}
	return 0;
}	