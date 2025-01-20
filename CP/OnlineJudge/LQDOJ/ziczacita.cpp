#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

long long num1 = 0 , num2 = 0;
vector <int> v;

int main() {
	boost;

	long long n , x; cin >> n;

	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		v.push_back(x);
	}


	long long first , second;
	for (int i = 1 ; i < n - 1 ; i ++) {
		first = 0 , second = 0;
		for (int j = 0 ; j < i ; j++) 
			if (v[j] > v[i]) first ++;
		for (int j = i + 1 ; j < n; j ++) 
			if (v[j] > v[i]) second ++;
		num2 += first * second;
	}

	num1 = (n * (n - 1) * (n - 2)) / 6;
	cout << fixed << setprecision(6) << (double) num2 / num1;
	return 0;
}