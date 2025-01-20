#include <bits/stdc++.h>

using namespace std;

int n , q;
int v[500005];
int ITmax[2000007];
int ITmin[2000007];

void calcmax(int index , int l , int r) {
	if (l == r) {
		ITmax[index] = v[l];
		return;
	}
	int mid = (l + r)/2;
	calcmax(2 * index , l , mid);
	calcmax(2 * index + 1 , mid + 1 , r);
	ITmax[index] = max(ITmax[2*index] , ITmax[2*index+1]);
	return;	
}

void calcmin(int index , int l , int r) {
	if (l == r) {
		ITmin[index] = v[l];
		return;
	}
	int mid = (l + r)/2;
	calcmin(2 * index , l , mid);
	calcmin(2 * index + 1 , mid + 1 , r);
	ITmin[index] = min(ITmin[2*index] , ITmin[2*index+1]);
	return;	
}

int findmax(int index , int l , int r , int L , int R) {
	if (L > r || R < l) return 1;
	if (l <= L && R <= r) return ITmax[index];
	int mid = (L + R)/2;
	int vLeft = findmax(2*index , l , r , L , mid);
	int vRight = findmax(2*index + 1 , l , r , mid + 1 , R);
	return max(vLeft , vRight);
}
int findmin(int index , int l , int r , int L , int R) {
	if (L > r || R < l) return 1000000;
	if (l <= L && R <= r) return ITmin[index];
	int mid = (L + R)/2;
	int vLeft = findmin(2*index , l , r , L , mid);
	int vRight = findmin(2*index + 1 , l , r , mid + 1 , R);
	return min(vLeft , vRight);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1 ; i <= n ; i++) 
		cin >> v[i]; 
	calcmax(1 , 1 , n);
	calcmin(1 , 1 , n);
	int l , r;
	for (int i = 1 ; i <= q ; i++) {
		cin >> l >> r;
		cout << findmax(1 , l , r , 1 , n) - findmin(1 , l , r , 1 , n) << '\n';
	}
	
	return 0;
}