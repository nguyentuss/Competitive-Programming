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
int li , ri;

void ins(int x , int i) {
    int val = *low.rbegin();
    if (val < x) {
        up.insert(x);
        ri += x;
        if (up.size() > k/2) {
            int vv = *up.begin();
            low.insert(*up.begin()); li -= vv;
            up.erase(up.find(*up.begin())); ri -= vv;
        }
    }
    else {
        low.insert(x);
        li -= x;
        if (low.size() > (k + 1)/2) {
            int vv = *low.rbegin();
            up.insert(*low.rbegin()); ri += vv;
            low.erase(low.find(*low.rbegin())); li += vv;
        }
    }
}

void era(int x) {
    if(up.find(x) != up.end()) {
        up.erase(up.find(x));
        ri -= x;
    }
	else {
        low.erase(low.find(x));
        li += x;
    }
	if(low.empty()){
        int vv = *up.begin();
		low.insert(*up.begin()); li -= vv;
		up.erase(up.find(*up.begin())); ri -= vv; 
	}
}

int median() {
    return (k % 2 == 0 ? 0 : *low.rbegin());
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0 ; i < n ;i ++) cin >> a[i];   
    low.insert(a[0]);
    li -= a[0]; 
    for (int i = 1 ; i < k ; i++) {
        ins(a[i] , i);
        //cerr << li << " " << ri << '\n';
    }
    cout << li + ri + median() << " ";
    for (int i = k ; i < n ; i++) {
        if (k == 1) {
            ins(a[i] , i);
            era(a[i - k]);
        }
        else {
            era(a[i - k]);
            ins(a[i] , i);
        }
        
        cout << li + ri + median() << " ";
    }
    return 0;
}