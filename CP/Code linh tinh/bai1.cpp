#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define boost ios::sync_with_stdio(0); cin.tie(NULL);

int main() {
	boost;
	int n, x; cin >> n;
	
	vector <int> arr;

	for (int i = 0 ;i < n ; i++) {
		cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(),arr.end());

	for (int i = 0 ; i < (int) arr.size() ;i ++)
		cout << arr[i] << " ";
	cout << endl;
	sort(arr.begin(),arr.end(),greater<int>());

	for (int i = 0 ;i < (int) arr.size() ; i++) 
		cout << arr[i] << " ";

	return 0;
}