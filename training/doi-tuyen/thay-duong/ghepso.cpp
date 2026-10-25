#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	freopen("ghepso.inp","r",stdin);
	freopen("ghepso.out","w",stdout);	
	vector <string> a;

	string s;

	int n; cin >> n;
	for (int i = 0 ; i < n; i ++) {
		cin >> s;
		a.push_back(s); 
	}

	sort(a.begin(),a.end());

	for (int i = (int) a.size() - 1 ; i >= 0 ; i--) cout << a[i];

	return 0;
}