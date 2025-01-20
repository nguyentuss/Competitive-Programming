#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

long maxn = 0;
int n,i,j,t;
string a[101],s;
int main(){
    
    cin >> n;
    for (i=1;i<=n;i++) cin >> a[i];
    for (i=1;i<=n-1;i++){
        for (j=i+1;j<=n;j++){
            s = a[i] + a[j];
            int t = atoi(s);
            if (t > maxn) maxn = t;    
        }
    }
    cout << maxn;
    return 0;
}