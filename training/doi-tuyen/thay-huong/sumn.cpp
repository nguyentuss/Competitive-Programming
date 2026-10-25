#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

#pragma GCC optimize("Ofast")

unsigned long long n , x , m;
int main(){
	freopen("sumn.inp","r",stdin);
	freopen("sumn.out","w",stdout);
	cin >> n;
	
	x = n;
	while (n > 0) {
		m += n % 10;
		n /= 10;
	}
	cout << m + x; 


	return 0;
}