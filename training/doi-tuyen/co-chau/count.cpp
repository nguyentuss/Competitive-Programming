#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);
//#define fi freopen("count.inp","r",stdin);
//	#define fo freopen("count.out","w",stdout);

string str;

int main() {
	boost;
	fi;fo;
	string a , str = "";
	while(cin >> a) {
		str += a;
	}
	vector <int> v;
	for (int i = 0 ; i < (int) str.size() ; i++) {
		if (str[i] == str[i + 1] && str[i] == '1' && str[i + 1] == '1'){
			v.push_back(i);
		}
	}
	v.push_back((int) str.size() - 1);
	long long ans = 0;
	int l = 0;
	for (int i = 0 ; i < (int) v.size() ; i++) {
		ans += (v[i] - l + 1)*(v[i] - l + 2)/2; 
		l = v[i] + 1;
	}
	cout << ans;


	return 0;
}