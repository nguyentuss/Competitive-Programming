#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

vector <long long> v;
priority_queue <long long> pq;
map <int , int> m;

int n , q , x; 
long long s , ans = 0 , sum = 0;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	cin >> n >> s;
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		ans += x*x;
		sum += x;
		m[x] ++;
		v.push_back(x);
		pq.push(x);
	}

	long long temp = pq.top() + (s - sum);
	ans = ans - pq.top()*pq.top() + temp*temp;
	int q /*, pos , before*/; cin >> q;
	/*for (int i = 0 ; i < q ; i++) {
		cin >> pos >> x;
		before = v[pos - 1];
		m[v[pos - 1]] --;
		m[x] ++;
		pq.push(x);
		while (!m[pq.top()]) pq.pop();
		sum = sum - before + x;
	}*/

	cout << ans;

	return 0;
}