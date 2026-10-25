#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int n , q , c1 , c2; 
vector <int> v(1e5 + 7) , IT(400001 , 0);
int ans;

int query(int index , int L , int R , int left , int right) {
    if (left <= L && R <= right) 
        return IT[index];
    if (left > R || L > right) return -1;
    int mid = (L + R)/2;
    int vLeft = query(2 * index , L , mid , left , right);
    int vRight = query(2 * index + 1 , mid + 1 , R , left , right);
    return max(vLeft , vRight);
}

void segmenttree(int index, int left , int right) {
    if (left == right) {
        IT[index] = v[left];
        return;
    }
        int mid = (left + right) / 2;
        segmenttree(2*index , left , mid);
        segmenttree(2*index + 1 , mid + 1 , right);
        IT[index] = max(IT[2 * index] , IT[2 * index + 1]);
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(NULL);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) cin >> v[i];
    segmenttree(1 , 1 , n);
    cin >> q;
    for (int i = 0 ; i < n ; i++) {
        cin >> c1 >> c2;
        cout << query(1 , 1 , n , c1 , c2) << endl;
    }
    return 0;
}