#include <bits/stdc++.h>

using namespace std;

#define M (int) (727355608)
#define MAX_N (int) (1e6 + 7)
#define ll long long

ll num1 , num2 , num3;
string s;
ll f[MAX_N];

void solvepow() {
	f[0] = 1;
	for (int i = 1 ; i <= s.size() ; i++) {
		f[i] = (f[i - 1]*4%M)%M;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	//freopen("inp.inp","r",stdin);
	//freopen("out.out","w",stdout);
	ll S; cin >> S;
	cin >> num1 >> num2 >> num3;
	int num0 = S - num1 - num2 - num3;
	int du1 = num1 % 2 , du2 = num2 % 2 , du3 = num3 % 2 , du0 = num0 % 2;
	if ((num1 + num2 + num3) == 1) return (cout << "Bedao!" , 0);
	if ((num1 + num2 + num3) == 0 && S > 1) return (cout << "Bedao!" , 0);
	if ((du1 + du2 + du3) > 1) return (cout << "Bedao!" , 0);
	if (((du1 + du2 + du3) >= 1) && du0) return (cout << "Bedao!" , 0);
	bool check1 = false , check2 = false , check3 = false;
	if (num1 >= 2) s += '1' , check1 = true;
	else if (num2 >= 2) s += '2' , check2 = true;
	else if (num3 >= 2) s += '3' , check3 = true;
	for (int i = 0 ; i < (num0 / 2) ; i++) s += '0';
	for (int i = (check1 ? 1 : 0) ; i < (num1 / 2) ; i++) s += '1';
	for (int i = (check2 ? 1 : 0) ; i < (num2 / 2) ; i++) s += '2';
	for (int i = (check3 ? 1 : 0) ; i < (num3 / 2) ; i++) s += '3';
	if (du1) s += '1';
	else if (du2) s += '2';
	else if (du3) s += '3';
	else if (du0) s += '0';
	for (int i = (check3 ? 1 : 0) ; i < (num3 / 2) ; i++) s += '3';
	for (int i = (check2 ? 1 : 0) ; i < (num2 / 2) ; i++) s += '2';
	for (int i = (check1 ? 1 : 0) ; i < (num1 / 2) ; i++) s += '1';
	for (int i = 0 ; i < (num0 / 2) ; i++) s += '0';
	if (num1 >= 2) s += '1';
	else if (num2 >= 2) s += '2';
	else if (num3 >= 2) s += '3';
	solvepow();
	//for (auto e : s) cout << e;
	//cout << '\n';
	int mu = s.size() - 1;
	ll ans = 0LL;
	for (int i = 0 ; i < s.size() ; i++) {
		ans = (ans + ((s[i] - '0')*f[mu--])%M)%M;
	}
	cout << ans%M;
	return 0;
}