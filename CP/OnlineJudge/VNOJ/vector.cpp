#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int> 
vector<ii> v(50);
map<ii , int> type1 , type2;
map<ii , int>::iterator it;
vector<int> X(50);
int n;

void calc(int start , int end) {
	long long x = 0 , y = 0;
	for (int i = start ; i <= end ; i++) {
		if (X[i] == 1) {
			x += v[i].first;
			y += v[i].second;
		}
	}
	if (end == n/2) type1[ii(x ,y)]++;
	else type2[ii(x , y)]++;
}

void backtr(int start , int end) {
	for (int j = 0 ; j <= 1 ; j++) {
		X[start] = j;
		if (start == end){
			if (end == n /2) calc(1 , end);
			else calc(n / 2 + 1 , end);
		}
		else backtr(start + 1 , end);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n; i++) 
		cin >> v[i].first >> v[i].second;
	int U , V;
	cin >> U >> V;
	backtr(1 , n / 2);
	backtr(n / 2 + 1, n);
	long long ans = 0;
	for (it = type1.begin() ; it != type1.end() ; it++) {
		ans += it->second*type2[ii(U - it->first.first , V - it->first.second)];
	}
	cout << ans;

	return 0;
}