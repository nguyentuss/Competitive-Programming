#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0) ; cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fast;
	//freopen("wc5.inp","r",stdin);
	//freopen("wc5.out","w",stdout);
	int t ; cin >> t;
	while (t--){
			string s1 , s2 , s3;
			cin >> s1 >> s2 >> s3;
			int d1 = s1.size();
			int d3 = s3.size();
			s1.erase(d1-4,4);
			s3.erase(d3-2,2);
			cout << s1 << "COO" << s3 << endl;
	}
	return 0;
}