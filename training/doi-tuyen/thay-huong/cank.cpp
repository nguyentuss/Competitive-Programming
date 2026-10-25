#include <bits/stdc++.h>

using namespace std;

int n , k ,  total = 0 , total1 , total2;
vector <int> x(30);
vector <int> v(30);
bool check = false;

void write() {
	total1 = k , total2 = 0;
	for (int j = 1 ; j <= n; j++){ 
		if (x[j] == 1) total1 += v[j];
		else if (x[j] == 2) total2 += v[j];
	}
	if (total1 == total2) check = true;
}

int backtr(int i) {
	for (int j = 1 ; j <= 3 ; j++){
		x[i] = j;
		if (i == n) write();
		else backtr(i + 1);
	} 
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	freopen("cank.inp","r",stdin);
	freopen("cank.out","w",stdout);
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++){
		cin >> v[i];
		total += v[i];
	}
	backtr(1);
	if (check == false) cout << "NO";
	else cout << "YES";
	return 0;
}