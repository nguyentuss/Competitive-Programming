#include <iostream>
#include <algorithm>
#include <map>
#include <limits.h>
#include <unordered_map>
#include <stack>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

unsigned long long n , u , o , m;
unordered_map <unsigned long long , long long> path;
unordered_map <unsigned long long , bool> visited;
bool check = false;
long long ans = LLONG_MAX;

bool BFS(long long s) {
	stack<long long> q;
	q.push(s);
	while (!q.empty()){
		long long v = q.top();
		if (v == 1) return true;
		q.pop();
		if ((v % u == 0) && path[v / u] == 0) {
			path[v / u] = path[v] + 1;
			q.push(v / u);
		} 
		if ((v % o == 0) && path[v / o] == 0) {
			path[v / o] = path[v] + 1;
			q.push(v / o);
		} 
		if ((v % m == 0) && path[v / m] == 0) {
			path[v / m] = path[v] + 1;
			q.push(v / m);
		}
	}
	return false;
}

int main(){
	boost;

	int t; cin >> t;

	while (t --) {
		visited.clear();
		path.clear();
		check = false;	
		ans = LLONG_MAX;	
		cin >> n >> u >> o >> m;
		path[n] = 1;
		if (BFS(n)) cout << path[1] - 1<< endl;
		else cout << -1 << endl;
	}	

	return 0;
}