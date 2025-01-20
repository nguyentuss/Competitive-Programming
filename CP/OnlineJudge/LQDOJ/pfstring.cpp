#include <iostream>
#include <algorithm>
#include <cmath> 
#include <vector> 
#include <string>

using namespace std;

vector <int> v(257,0);

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

string s;

int main(){ 
	boost;

	int n; cin >> n;
	cin >> s;

	for (int i = 0 ; i < (int) s.size() ; i++) 
		v[(int) s[i]] ++;

	long long ans = 0;

	for (int i = (int) 'a' ; i <= (int) 'z' ; i++){ 
		if (v[i] != 0) {
			//cout << v[i] << endl;
			ans += ((v[i] - 1)*v[i])/2;
		}
	}

	cout << ans;

	return 0;
}