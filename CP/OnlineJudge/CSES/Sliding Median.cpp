#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;

int n , k;
multiset<int> low , up;

void ins(int x) {
    int val = *low.rbegin();
    if (val < x) {
        up.insert(x);
        if (up.size() > k/2) {
            low.insert(*up.begin());
            up.erase(up.find(*up.begin()));
        }
    }
    else {
        low.insert(x);
        if (low.size() > (k + 1)/2) {
            up.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void era(int x) {
    if(up.find(x) != up.end()) up.erase(up.find(x));
	else low.erase(low.find(x));
	if(low.empty()){
		low.insert(*up.begin());
		up.erase(up.find(*up.begin()));
	}
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0 ; i < n ;i ++) cin >> a[i];   
    low.insert(a[0]); 
    for (int i = 1 ; i < k ; i++) ins(a[i]);
    cout << *low.rbegin() << " ";
    for (int i = k ; i < n ; i++) {
        if (k == 1) {
            ins(a[i]);
            era(a[i - k]);
        }
        else {
            era(a[i - k]);
            ins(a[i]);
        }
        cout << *low.rbegin() << " ";
    }
    return 0;
}