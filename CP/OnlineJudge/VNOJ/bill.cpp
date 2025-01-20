#include <bits/stdc++.h>

using namespace std;

long long x , y;

int vnd[5] = {0 , 200 , 300 , 500 , 700};
long long kwh[5] = {0 ,100 , 9900 , 990000 , 19000000};

long long changevnd(int a) {
	long long tmp = 0 , ans = 0;
	for (int i = 1 ; i <= 4 ; i++) {
		if (tmp + kwh[i] <= a) {
			ans += kwh[i]*vnd[i];
			tmp += kwh[i];
		}
		else {
			ans += (a - tmp)*vnd[i];
			return ans;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> x >> y;
	long long tmp = 0;
	long long kwhtotal = 0;
	for (int i = 1 ; i <= 4 ; i++) {
		if (tmp + kwh[i]*vnd[i] <= x) {
			tmp += kwh[i]*vnd[i];
			kwhtotal += kwh[i];
		}
		else {
			kwhtotal += (x - tmp)/vnd[i];
			break;
		}
	}
	int l = 0 , r = kwhtotal / 2 , ans = -1;
	while (l <= r) {
		int mid = (l + r)/2;
		long long Nam = changevnd(mid);
		long long Viet = changevnd(kwhtotal - mid);
		if (Viet - Nam == y) {
			cout << Nam;
			return 0;
		}
		if (Viet - Nam < y) r = mid - 1;
		else l = mid + 1;
	}
	return 0;
}