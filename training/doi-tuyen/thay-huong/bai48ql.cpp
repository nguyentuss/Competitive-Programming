#include <iostream>
using namespace std;

bool chk[1001];
int n, a[21], x[21], tmp;

void chknghiem(){
    tmp = 0;
    for (int i = 1; i <= n; i++){
        tmp += x[i] * a[i];
    }
    chk[tmp] = true;
}

void chon(int i){
    for (int j = 0; j <= 1; j++){
        x[i] = j;
        if (i == n) chknghiem();
        else chon(i + 1);
    }
}

int main(){
    freopen("BAI48QL.inp", "r", stdin);
    freopen("BAI48QL.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
        
    chon(1);

    for (int i = 1; i <= 100000; i++)
        if (!chk[i]) {
            cout << i;
            return 0;
        }
    return 0;
}
