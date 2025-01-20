#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

vector <ii> arr;

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);

	int n , x , y; cin >> n;
	for (int i = 0; i < n ; i++) {
		cin >> x >> y;
		arr.push_back(ii(y,x));
	}
	sort(arr.begin() , arr.end() , greater<ii> ());
	//for (int i = 0 ; i < n ; i++) cout << arr[i].first << " " << arr[i].second << endl;

	long long A = 0 , B = 0;
	
	if (arr[0].first == 0) {
		cout << arr[0].second;
		return 0;
	}
	else {
		B += arr[0].first;
		A += arr[0].second;
	}
	for (int i = 1 ; i < n ; i++) {
		if (arr[i].first > 0) B = B - 1 + arr[i].first;
		else B --;
		A += arr[i].second;
		//cout << A << endl;
		if (B == 0) {
			cout << A;
			return 0;
		}
	}
	cout << A;

	return 0;
}

