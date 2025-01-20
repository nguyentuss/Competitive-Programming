#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define ii pair<int , int>
#define f first
#define s second

const int N = 2e5 + 7;

struct iii {
    int l , r , id;
};

bool cmp_1(iii &a , iii &b) {
    return (a.r < b.r || (a.r == b.r && a.l > b.l));
}

bool cmp_2 (iii &a , iii &b) {
    return (a.r > b.r || (a.r == b.r && a.l < b.l));
}

iii a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a + 1 , a + 1 + n , cmp_1);

    ordered_set<int> o_set;
    vector<int> ck_1(n + 1) , ck_2(n + 1);
    for (int i = 1 ; i <= n ; i++) {
        int num_smaller = (o_set.order_of_key(a[i].l));
        ck_1[i] = i - num_smaller - 1;
        o_set.insert(a[i].l);
    }   
    vector<ii> change_id;
    for (int i = 1 ; i <= n ;i ++) {
        change_id.push_back(ii(a[i].id , ck_1[i]));
    }
    sort(change_id.begin() , change_id.end());
    for (auto x : change_id) {
        cout << (x.second ? 1 : 0) << " ";
    }
    cout << '\n';
    sort(a + 1 , a + 1 + n , cmp_2);
    o_set.clear();
    for (int i = 1 ; i <= n ;i ++) {
        int num_smaller = (o_set.order_of_key(a[i].l + 1));
        ck_2[i] = num_smaller; 
        o_set.insert(a[i].l);
    }
   
    change_id.clear();
    for (int i = 1 ; i <= n ;i ++) {
        change_id.push_back(ii(a[i].id , ck_2[i]));
    }
    sort(change_id.begin() , change_id.end());
    for (auto x : change_id) {
        cout << (x.second ? 1 : 0) << " ";
    }
    return 0;
}