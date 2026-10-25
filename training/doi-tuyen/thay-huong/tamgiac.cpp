#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main(){

	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("tamgiac.inp","r",stdin);
	freopen("tamgiac.out","w",stdout);
	ll n ; cin >> n; 
	bool check = false;
	vector <ll> a(n);
	for (int i = 0 ; i < n ; i++)
		cin >> a[i];
	sort(a.begin(),a.end(),greater<int>());
	//for (int i = 0 ; i < n ; i++) cout << a[i] << " ";
	for (int i = 0 ; i < n-2 ; i++)
	{
		if (a[i] < a[i+1] + a[i+2]) {
			cout << a[i] << " " << a[i+1] << " " << a[i+2];
			return 0;
		}
	}
	cout << -1;
	return 0;
}