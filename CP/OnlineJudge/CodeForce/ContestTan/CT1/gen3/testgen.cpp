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

    int n = random(1000 , 1000);
    cout << n << " " << 3 << endl;

    for (int i = 1; i <= 3; i++){
        for (int j = 1 ; j <= n ; j++) {
            cout << random(1,1000 * 1000 * 1000) << " ";
        }
        cout << '\n';
    }

    return 0;
}
