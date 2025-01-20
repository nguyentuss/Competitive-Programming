	#include <iostream>
	#include <algorithm>
	#include <map>
	#include <limits.h>
	#include <vector>

	using namespace std;

	typedef pair<long long  , long long > ii;

	int main() {
		ios::sync_with_stdio(0); cin.tie(NULL);

		//freopen("input.inp","r",stdin);
		//freopen("output.out","w",stdout);

		long long n , a , minimum = LLONG_MAX;	cin >> n;
		map <long long , long long> m;
		map <long long , long long>::iterator it;
		vector <long long> v; 
		for (long long i = 1; i <= n  ; i++){
			cin >> a;
			v.push_back(a);
			m.insert(ii (a , i));
		}
		
		for (long long i = v.size() - 1 ; i >= 0 ; i--) {
			if (!m.empty()){
				it = m.upper_bound(v[i]);
				if (it != m.end()){
					minimum = min(minimum , it -> first - v[i]);
					it = m.find(v[i]);
					m.erase(it);
				}
			}
		}
		cout << minimum;

		return 0;
	}