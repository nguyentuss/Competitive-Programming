/**
 * Author: Tus
 * Date: 2017-07-23
 * License: CC0
 * Source: https://cp-algorithms.com/data_structures/segment_tree.html#preserving-the-history-of-its-values-persistent-segment-tree
 * Description: Preserving the history of its values
 * Time: O(\log N)
 * Status: Tested on CSES 1737
 */

struct node {
    int sum; 
    node *l , *r; 
    node() {
        sum = 0; 
        l = r = nullptr;
    }
};

int get_sum(node *x) {
    if (!x) return 0; 
    return x->sum;
}

void build(node *cur , int l , int r) {
    if (l == r) {
        cur -> sum = b[l]; 
        return;
    }
    cur -> l = new node(); 
    cur -> r = new node();
    int mid = (l + r)/2; 
    build(cur -> l , l , mid);
    build(cur -> r , mid + 1 , r);
    cur -> sum = get_sum(cur->l) + get_sum(cur->r);
}

void update(node *cur , node *prev, int i , int l , int r , int val) {
    if (l == r) {
        cur -> sum = val;
        return;
    }
    int mid = (l + r)/2;
    if (i <= mid) {
        cur -> l = new node(); 
        cur -> r = prev -> r; 
        update(cur -> l, prev -> l , i , l , mid , val); 
    }
    else {
        cur -> r = new node();
        cur -> l = prev -> l;
        update(cur -> r, prev -> r , i , mid + 1 , r , val);
    }
    cur -> sum = get_sum(cur->l) + get_sum(cur->r);
    return;
}

int query(node *cur , int l , int r , int L , int R) {
    if (l > R || r < L) return 0; 
    if (L <= l && r <= R) return cur -> sum;
    int mid = (l + r)/2;
    return query(cur -> l , l , mid , L , R) + query(cur -> r , mid + 1 , r , L , R);
}
