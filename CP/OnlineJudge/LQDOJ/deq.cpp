#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

vector <int> v , ans;

int main() {
	boost;
	int n , x; cin >> n;

	for (int i = 0 ; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	stack <int> s;
	s.push(0); s.push(v[0]);
	ans.push_back(0);
	for (int i = 1 ; i < n; i ++){
		while (v[i] < s.top() && !s.empty()) s.pop();
		ans.push_back(s.top());
		s.push(v[i]);
	} 

	for (int i = 0 ; i < n ; i++) cout << ans[i] << " " ;

	return 0;
}