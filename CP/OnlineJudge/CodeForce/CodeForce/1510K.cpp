#include <bits/stdc++.h>

using namespace std;

map <vector <int> , int> m;
vector <int> v;
int n , x;

vector <int> change1(vector <int> a) {
	for (int i = 0 ; i < (int) a.size() ; i+= 2) 
		swap(a[i] , a[i + 1]);
	return a;
}

vector <int> change2(vector <int> a) {
	for (int i = 0 ; i < n ; i++) 
		swap(a[i] , a[n + i]);
	return a;
}


void calc() {
	vector <int> adj;
	for (int i = 0 ; i < 2*n ; i++) 
		adj.push_back(i + 1);
	queue <vector <int>> q;
	q.push(adj);
	m[adj] = 0;
	while (!q.empty()){
		vector <int> temp = q.front(); q.pop();
		vector <int> go1 = change1(temp);
		vector <int> go2 = change2(temp);
		if (!m.count(go1)) {
			m[go1] = m[temp] + 1;
			q.push(go1);
		}
		if (!m.count(go2)) {
			m[go2] = m[temp] + 1;
			q.push(go2);
		}
	}

}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	cin >> n;
	for (int i = 0 ; i < 2*n ; i++) {
		cin >> x;
		v.push_back(x);
	}
	calc(); 
	if (!m.count(v)) cout << -1;
	else cout << m[v];
	return 0;
}