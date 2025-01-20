#include <iostream>
using namespace std;

long m , n , k , dem;

int main() {
    cin >> m >> n >> k;
    while ((m+n) >= k){
        m-=2;
        n-=1;
        if (((m+n)>= k) && (m >= 0) && (n>=0)) 
            dem++;
    }

    cout << dem << "\n";
    return 0;
    
}
