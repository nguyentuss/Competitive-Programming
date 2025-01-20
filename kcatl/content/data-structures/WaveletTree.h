/**
 * Author: ei1333
 * Date: 2023-11-27
 * Source: https://ei1333.github.io/library/structure/wavelet/wavelet-bvrix.hpp
 * Description: Similar to merge sort tree but faster. Works even faster if values are compressed (i.e. permutation).
 * Time: O(N \log N)
 * Status:
 *  - tested on yosupo:range_kth_smallest
 *  - tested on yosupo:static_range_frequency
 */

template <class T>
struct WaveletMatrix {
	struct BitVec {
		int len, blks; vl bit; vi sum;
		BitVec(int len) : len(len), blks((len + 63) >> 6) {
			bit.assign(blks, 0); sum.assign(blks, 0);
		}
		void set(int k) { bit[k >> 6] |= 1LL << (k & 63); }
		void build() { rep(i, 1, blks)
			sum[i] = sum[i - 1] + __builtin_popcountll(bit[i - 1]);
		}
		int rank(int k) {
			ll t = bit[k >> 6] & ((1LL << (k & 63)) - 1);
			return sum[k >> 6] + __builtin_popcountll(t);
		}
		int rank(bool f, int k) { return f ? rank(k) : k-rank(k); }
	};

	int n, lg; vi mid; vector<BitVec> bv;
	WaveletMatrix(vector<T> v) : n(sz(v)), lg(1) {
		if (n) lg = __lg(max(T(1), *max_element(all(v)))) + 1;
		mid.resize(lg); bv.assign(lg, BitVec(n + 1));
		vector<T> l(n), r(n);
		for (int i = lg, lt, rt; i--;) { lt = rt = 0;
			rep(j,0,n) if ((v[j] >> i) & 1)
				r[rt++] = v[j], bv[i].set(j);
			else l[lt++] = v[j];
			bv[i].build(); mid[i] = lt; v.swap(l);
			rep(j,0,rt) v[lt + j] = r[j];
		}
	}
	pii succ(bool f, int l, int r, int i) {
		return {bv[i].rank(f, l) + mid[i] * f,
						bv[i].rank(f, r) + mid[i] * f};
	}
	T kth(int l, int r, int k) { // kth (0-index) number in [l,r)
		T ret = 0;
		for (int i = lg; i--;) {
			int cnt = bv[i].rank(0, r) - bv[i].rank(0, l);
			tie(l, r) = succ(cnt <= k, l, r, i);
			if (cnt <= k) ret |= T(1) << i, k -= cnt;
		}
		return ret;
	}
	int cnt_eq(int l, int r, T x) {  // count == x in [l,r)
		for (int i = lg; i--; tie(l, r) = succ((x>>i)&1, l, r, i));
		return r - l;
	}
	int cnt_lt(int l, int r, T x) { // count < x in [l,r)
		int ret = 0;
		for (int i = lg; i--; tie(l, r) = succ((x>>i)&1, l, r, i))
			if ((x>>i)&1) ret += bv[i].rank(0, r) - bv[i].rank(0, l);
		return ret;
	}
};
