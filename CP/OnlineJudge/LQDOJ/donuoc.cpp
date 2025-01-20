#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	long long a , b , N; cin >> a >> b >> N;
	cout << (N - 1)*(b - a) + a;
	return 0;
}