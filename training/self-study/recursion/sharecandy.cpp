#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxn = 30;
int n , s = 0 , res = 1e9,a[maxn] , x[maxn];

void ghinghiem() {
    int s2 = 0 , s1 = 0;
    for (int i = 1 ; i <= n ; i++) 
        s1 = s1 + (x[i] * a[i]);
    s2 = s - s1;
    res = min(res , abs(s1 - s2));
    //cout << abs(s1 - s2) << " ";
}
void backtr(int i){
    for (int j = 0 ; j <= 1 ; j++){
        x[i] = j;
        if (i == n) ghinghiem();
        else backtr(i+1);
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        s += a[i];
    }
    backtr(1);
    cout << res << '\n';
    return 0;
}