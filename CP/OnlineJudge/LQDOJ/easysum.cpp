#include <iostream>

using namespace std;

int main(){
	long long n; cin >>n;

	cout << (long long) n*(n + 1)/2 - 2*(n/2)*(n/2+1);

	return 0;
}