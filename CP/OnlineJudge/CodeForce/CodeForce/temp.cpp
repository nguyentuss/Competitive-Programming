#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    const auto sum = [term, next](int a, int b) {
    auto sum_impl = [term, next](int a, int b, auto& sum_ref) mutable {
        if (a > b) {
            return 0;
        }
        return term(a) + sum_ref(next(a), b, sum_ref);
    };
    return sum_impl(a, b, sum_impl);
};
    return 0;
}