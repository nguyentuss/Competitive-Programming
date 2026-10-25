#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int> 

int a , b;
vector <int> cha , chb , res;	
long long POW[30];
map<ii , int> m;

vector <int> change(int x) {
	vector <int> tmp;
	while (x > 0) {	
		tmp.push_back(x % 3);
		x /= 3;
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("ternary.inp","r",stdin);
	freopen("ternary.out","w",stdout);
	m[ii(0 , 1)] = 1 , m[ii(1 , 0)] = 2 , m[ii(1 , 1)] = 0 , m[ii(2 , 0)] = 1;
	m[ii(0 , 2)] = 2 , m[ii(2 , 1)] = 2 , m[ii(1 , 2)] = 1 , m[ii(2 , 2)] = 0;
	cin >> a >> b;
	cha = change(a);
	chb = change(b);
	while (cha.size() < chb.size()) cha.push_back(0);
	while (cha.size() > chb.size()) chb.push_back(0);
	for (int i = 0 ; i < (int) cha.size() ; i++) {
		res.push_back(m[ii(cha[i] , chb[i])]);
	}
	POW[0] = 1;
	for (int i = 1 ; i <= 20 ; i++) 
		POW[i] = POW[i - 1]*3;
	reverse(res.begin() , res.end());
	//for (auto e : res) cout << e;
	int cnt = res.size() - 1;
	long long ans = 0;
	for (int i = 0 ; i < res.size() ; i++) 
		ans += res[i]*POW[cnt--];
	cout << ans;
	return 0;
}