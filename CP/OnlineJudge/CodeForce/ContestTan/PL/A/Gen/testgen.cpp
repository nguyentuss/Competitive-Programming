#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

int random(int left = 0, int right = 1e8){
    if (left == right){
        return left;
    }
    return (rand() % (right - left + 1)) + left;
}


signed main(){
    srand(time(0));
    freopen("input.inp", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = random(1 , 7);
    cout << n << endl;
    for (int i = 1 ; i <= n ; i++) {
        int x = random(1 , 2);
        if (x == 1) cout << '<';
        else cout << '>';
    }

    return 0;
}
