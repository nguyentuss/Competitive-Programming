#include <bits/stdc++.h>

using namespace std;

int main() {
	set<int , greater<int>> s;
	s.insert(5);
	s.insert(9);
	auto it = s.lower_bound(10);
	cout << *it;


	return 0;
}