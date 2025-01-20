#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int pre[N << 1];

signed main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        n <<= 1;
        string str;
        cin >> str;
        str = ' ' + str;
        int flag = 1;
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + (str[i] == '(' ? 1 : -1);
            flag &= (pre[i] >= 0);
        }
        if (flag) {
            puts("0");
            continue;
        }
        int L = 1e9, R = -1e9;
        for (int i = 1; i <= n; ++i) {
            if (pre[i] < 0) {
                L = min(L, i);
                R = max(R, i);
            }
        }
        --L, ++R;
        int fst = (!L ? 1 : max_element(pre + 1, pre + L + 1) - pre + 1), lst = (R == n ? n : max_element(pre + R, pre + n + 1) - pre);
        reverse(str.begin() + fst, str.begin() + lst + 1);
        int now = 0;
        flag = 1;
        for (int i = 1; i <= n; ++i) {
            now += (str[i] == '(' ? 1 : -1);
            flag &= (now >= 0);
        }
        if (flag) {
            puts("1");
            printf("%d %d\n", fst, lst);
            continue;
        }
        puts("2");
        int wh = max_element(pre + 1, pre + n + 1) - pre;
        printf("1 %d\n", wh);
        printf("%d %d\n", wh + 1, n);
    }
    return 0;
}