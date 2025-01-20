#include <bits/stdc++.h>

using namespace std;

#define MAX_N (int) (2*1e5 + 7)

int n , m;
vector<int> positive , negative;
vector<int> a , b;
int x;
int f1[MAX_N];
int f2[MAX_N];

bool check1(int x , int l , int r) {
	int pos = -1;
	while (l <= r) {
		int mid = (l + r)/2;
		if (x < positive[mid]) {
			r = mid - 1;
		}
		else if (x > positive[mid]) {
			l = mid + 1;
		}
		else if (x == positive[mid]) {
			pos = mid;
			break;
		}
	}
	if (pos == -1) return false;
	return true;
}

bool check2(int x , int l , int r) {
	int pos = -1;
	while (l <= r) {
		int mid = (l + r)/2;
		if (x < negative[mid]) {
			r = mid - 1;
		}
		else if (x > negative[mid]) {
			l = mid + 1;
		}
		else if (x == negative[mid]) {
			pos = mid;
			break;
		}
	}
	if (pos == -1) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	freopen("test.inp","r",stdin);
	int t; cin >> t;
	while (t--) {
		positive.clear() , negative.clear() , b.clear();
		a.clear();
		cin >> n >> m;
		
		for (int i = 0 ; i < n ; i++) {
			cin >> x;
			if (x < 0) negative.push_back(abs(x));
			else positive.push_back(x);
		}
		//for (auto e : positive) cout << e << " ";
		for (int i = 0 ; i < m ; i++) {
			cin >> x;
			if (x < 0) a.push_back(abs(x));
			else b.push_back(x);
		}
		reverse(a.begin() , a.end());
		for (int i = b.size() - 1 ; i >= 0 ; i--){ 
			f1[i] = f1[i + 1] + check1(b[i] , 0 , positive.size() - 1);
		}
		reverse(negative.begin() , negative.end());
		for (int i = a.size() - 1 ; i >= 0 ; i--) 
			f2[i] = f2[i + 1] + check2(a[i] , 0 , negative.size() - 1);
		reverse(negative.begin() , negative.end());
		reverse(positive.begin() , positive.end());
		int ans1 = 0;
		int ans2 = 0;
		for (int i = 0 ; i < b.size() ; i++) {
			int pos_1 = lower_bound(positive.begin() , positive.end() , b[i] , greater<int>()) - positive.begin();
			int last = positive.size() - pos_1;
			int pos_2 = lower_bound(b.begin() , b.end() , b[i] - last + 1) - b.begin();
			int len = i - pos_2 + 1;	
			ans1 = max(ans1 , len + f1[i + 1]);
		}
		for (int i = 0 ; i < a.size() ; i++) {
			int pos_1 = lower_bound(negative.begin() , negative.end() , a[i] , greater<int>()) - negative.begin();
			int last = negative.size() - pos_1;
			int pos_2 = lower_bound(a.begin() , a.end() , a[i] - last + 1) - a.begin();
			int len = i - pos_2 + 1;
			ans2 = max(ans2 , len + f2[i + 1]);
		}
		cout << ans1 + ans2 << '\n';
		for (int i = 0 ; i <= m ; i++) {
			f1[i] = 0;
			f2[i] = 0;
		}
	}

	return 0;
}