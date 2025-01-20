#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> IT(200005);
vector <int> v(50005);

void segment(int index, int l , int r) {
	if (l == r) {
		IT[index] = v[l];
		return;
	}
	int mid = (l + r)/2;
	segment(2*index , l , mid);
	segment(2*index + 1 , mid + 1 , r);
	IT[index] = max(IT[2*index] + IT[2*index + 1] , max(IT[2*index] , IT[2*index + 1]));
	return;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1 ; i <= n ; i++) 
		cin >> v[i];
	segment(1 , 1 , n);
	cout << IT[1];
	return 0;
}