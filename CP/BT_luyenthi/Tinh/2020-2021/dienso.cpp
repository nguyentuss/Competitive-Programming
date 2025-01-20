#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){

	freopen("dienso.inp","r",stdin);
	freopen("dienso.out","w",stdout);

	ll n; cin >> n;
	string st ; cin >> st;
	vector <ll> arr[2] ;
	ll dem = 0 ;
	bool check1 = false , check2 = false;

	for (ll i = 0 ; i < st.size() ; i++){
		if (st[i] == '>') {
			if (check2) {
				arr[0].push_back(dem);
				dem = 0;
				check2 = false;
			}
			dem ++;
			check1 = true;
		}
		else {
			if (check1) {
				arr[1].push_back(dem);
				dem = 0;
				check1 = false;
			}
			dem++;
			check2 = true;
		}
	}
	arr[(check1)? 1 : 0].push_back(dem);

	ll start = (st[0] == '>')? 1 : 0;
	ll pre = 0;
	ll s = 0;
	check1 = true;
	//cout << arr[1].size();
	for (ll i = 0 , u = start ; i < arr[u].size(); ){
		if (u == 0)
		{
			s += (arr[u][i] + 1) * arr[u][i] /2;
		}
		else
		{
			s += (arr[u][i] + 1) * arr[u][i] /2;
			if (pre > arr[u][i]) s -= arr[u][i];
			else s -= pre;
			//cout << s << " " << arr[u][i] << '\n';
		}
		//cout << u << " " << i << " " << s << " " << arr[u][i] << '\n';
		pre = arr[u][i];
		//cout << pre << '\n';
		u = u ^ 1;
		if (u == start) ++i;
		//cout << i << '\n';
	}
	cout << s;
	return 0;
}