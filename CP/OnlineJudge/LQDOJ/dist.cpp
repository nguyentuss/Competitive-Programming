#include <iostream>
#include <set>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int main(){
	boost;
	
	set <long long> s;
	int n;
	cin >> n;

	long long x;
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		s.insert(x);
	}

	cout << s.size();


	return 0;
}