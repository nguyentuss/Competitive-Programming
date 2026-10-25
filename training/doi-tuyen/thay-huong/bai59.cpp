#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check(string st) {
	string tam = st;
	reverse(tam.begin(),tam.end());
	return (tam == st);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	freopen("bai59.inp","r",stdin);
	freopen("bai59.out","w",stdout);
	string st;
	cin >> st;
	string tam = st , s; int n = st.length();
	for (int i = 0 ; i < n; i++)
	{
		if (check(st)) {
			cout << "YES";
			return 0;
		}
		s = st[n-1];
		st.erase(n-1,1);
		st.insert(0,s);
		//cout << st << '\n';
	}
	cout << "NO";
	return 0;
}