#include <iostream>
#include <cmath>

using namespace std;

long long a , b;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> a >> b;
	if ((a + b)%2 == 0) cout << "YES";
	else cout << "NO";
	return 0;
}