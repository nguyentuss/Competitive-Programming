#include <bits/stdc++.h>

using namespace std;

#define ll long long
multiset<ll> s;

ll findmax(multiset<ll> &s)
{
  
    ll max_element;
    if (!s.empty())
        max_element = *s.rbegin();
  
    return max_element;
}
  
ll findmin(multiset<ll> &s)
{
  
    ll min_element;
    if (!s.empty())
        min_element = *(--s.rend());
    return min_element;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	ll n , m , k; cin >> k >> m >> n;
	for (ll i = 1 ; i <= n ;i++) {
		ll x; cin >> x;
		s.insert(x);
	}
	ll ans = findmax(s) - findmin(s);
	for (ll i = 1 ; i <= m ;i++) {
		ll x = findmax(s) , y = findmin(s);
		s.erase(s.find(x)) , s.erase(s.find(y)); 
		if (x == y) {
			ans = 0;
			break;
		}
		else {
			if (x < k) {
				ans = 0;
				break;
			}
			s.insert(x - k); s.insert(y + k);
			ans = min(ans , findmax(s) - findmin(s));
		}
	}
	cout << ans;
	return 0;
}