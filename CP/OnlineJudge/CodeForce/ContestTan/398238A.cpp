#include <bits/stdc++.h>

using namespace std;

#define ii pair<int , int>  
#define iv pair<ii , ii>
#define iii pair<int , ii>
#define fi first
#define se second
#define int long long

const int inf = 1e18 + 7;
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
const double esp = 1e-6;

// t = (s - s0)/v
// s = s0 + v.(t - t0)


double a[N];
int n , pos = n + 1;

int check(double x) {
    int li = 0 , ri = n + 1;
    double posl = 0 , posr = pos;
    double timel = 0 , timer = 0;
    int vl = 1 , vr = 1;
    while (li <= n && timel < x + esp) {
        li++;
        if ((timel +(a[li] - a[li - 1])/vl) > x + esp) break;
        timel = timel + (a[li] - a[li - 1])/vl;   
        posl = a[li];
        vl++;
    }   
    posl = posl + vl*(x - timel);

    while (ri >= 1 && timer < x + esp) {
        ri--;
        if ((timer + (a[ri + 1] - a[ri])/vr) > x + esp) break;
        timer = timer + (a[ri + 1] - a[ri])/vr;
        posr = a[ri];
        vr++;
    }
    //cerr << vl << " " << vr << '\n';
    posr = posr - vr*(x - timer);
    // cerr << fixed << setprecision(10) << posl << '\n';
    // cerr << fixed << setprecision(10) << posr << '\n';
    // if ((posl - posr) <= esp) {
    //     cout << "YES";
    // }
    if (abs(posr - posl) <= esp) return 1;
    if (posl < posr) return 0;
    if (posl > posr) return 2;
}

main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> pos;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    a[n + 1] = pos;
    double l = 0 , r = 1e9 , ans = 1e9;
    for (int k = 0 ; k < 100 ; k++) {
        double mid = (l + r)/2.0;
        int status = check(mid);
        //cerr << l << " " << mid << " " << r << " " << status << '\n';;
        //cerr << status << '\n';
        //cerr << status << '\n';
        if (status == 0) l = mid;
        if (status == 1) {
            ans = mid;
            break;
        }
        if (status == 2) r = mid;
    }
    //cout << check(2.047619048);
    cout << fixed << setprecision(6) << ans;

    return 0;
}