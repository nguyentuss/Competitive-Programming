#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("vaohang.inp","r",stdin);
	freopen("vaohang.out","w",stdout);

	int n ; cin >> n;
	vector <long long> a(n);
	for (int i = 0 ; i < n ; i++)
		cin >> a[i];
	vector <long long> b(n);
	for (int i = 0 ; i < n ; i++)
		cin >> b[i];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	long long s = abs(a[0] - b[0]);
	for (int i = 1 ; i < n ; i++)
		s = max(s,abs(a[i] - b[i]));

	cout << s;

}