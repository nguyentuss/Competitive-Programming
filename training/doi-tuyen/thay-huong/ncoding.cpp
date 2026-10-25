#include <iostream>
#include <string>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("ncoding.inp","r",stdin);
	freopen("ncoding.out","w",stdout);

	int n , k ;
	cin >> n >> k;
	k = k % n;
	string s;
	cin >> s;
	cout << s.substr(n-k,k) << s.substr(0,n-k);
	return 0;
}
