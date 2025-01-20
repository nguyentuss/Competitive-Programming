#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
    int n , k; cin >> n >> k;
    ordered_set<int> ss;
    for (int i = 1 ; i <= n ; i++) {
        ss.insert(i);
    }
    int start = 0; 
    while (ss.size()) {
        start %= ss.size();
        int positionToRemove =  (start+k)%ss.size();
        start = positionToRemove;
        auto t = ss.find_by_order(positionToRemove);
        cout << *t << " ";
        ss.erase(t);
    }

}