#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

string N;

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);

	cin >> N;
	sort(N.begin() , N.end() , greater<int>());
	int len = N.size() - 1;
	if (N[len] != '0') {
		cout << -1;
		return 0;
	} 
	long long sum = 0;
	for (int i = 0 ; i < (int) N.size() ; i++)
		sum += N[i] - '0';

	if (sum % 3 == 0) cout << N;
	else cout << -1;
	return 0;
}