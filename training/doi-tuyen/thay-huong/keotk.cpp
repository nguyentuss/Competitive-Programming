#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("keotk.inp","r",stdin);
	freopen("keotk.out","w",stdout);
	int n; cin >> n;
	vector <int> a(n);
	for (int i = 0 ; i < n ; i++)
		cin >> a[i];
	sort(a.begin(),a.end());
	for (int i = 0 ; i < n ; i++)
		cout << a[i] << " "; 
	return 0;
}