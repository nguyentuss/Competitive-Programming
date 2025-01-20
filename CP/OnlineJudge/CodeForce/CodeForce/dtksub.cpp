#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

const int base = 26;
const int MAX_N = 50007;

int n , k , len;
string s;
vector <int> POW(MAX_N) , hashA(MAX_N);
//vector <int> m(100007);

long long gethash(int i , int j) {
	return (hashA[j] - hashA[i - 1]*POW[j - i + 1]);
}

bool check(int val) {
	unordered_map<long long , long long> m;	
	for (int i = 1 ; i <= len - val + 1 ; i++) {
		int j = i + val - 1;
		long long tmp = gethash(i , j);
		m[tmp] ++;
		if (m[tmp] >= k) return true;
	}
	return false;
}

int main(){
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
	//cout.tie(NULL);
	cin >> n >> k;
	cin >> s;
	len = s.size();
	s = ' ' + s;
	POW[0] = 1;
	for (int i = 1 ; i <= n; i++) 
		POW[i] = POW[i - 1]*base;
	for (int i = 1 ; i <= n; i++)
		hashA[i] = hashA[i - 1]*base + s[i] - 'a' + 1;

	int l = 1 , r = len , ans = 0;
	while (l <= r) {
		int mid = (l + r)/2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	//for (int i = 1 ; i <= n ; i ++) cout << hashA[i] << " ";
	cout << ans;
	return 0;
}