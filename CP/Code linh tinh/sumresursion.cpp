#include <iostream>
#include <vector>

using namespace std;

int a[101], n;

bool check(int l , int r){
    if (l >= r) return true;
    else if (a[l] == a[r] && check(l + 1, r - 1)) 
        return true;
} 

int main() {
    cin >> n;
    for (int i = 1 ; i <= n;i++) cin >> a[i];
    if (check(1,n)) cout << "YES";
    else cout << "NO";
    
    return 0;
}