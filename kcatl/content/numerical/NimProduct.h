/**
 * Author: tomatoes
 * Date: 2023-10-18
 * Description: Product of nimbers is associative, commutative, and distributive
 * over addition (xor). Forms finite field of size $2^{2^k}$.
 * Defined by $ab=\text{mex}(\{a'b+ab'+a'b':a'<a,b'<b\})$. Application:
 * Given 1D coin turning games $G_1,G_2$ $G_1\times G_2$ is the 2D coin turning
 * game defined as follows. If turning coins at $x_1,x_2,\ldots,x_m$ is legal
 * in $G_1$ and $y_1,y_2,\ldots,y_n$ is legal in $G_2$, then turning coins at
 * all positions $(x_i,y_j)$ is legal assuming that the coin at $(x_m,y_n)$
 * goes from heads to tails. Then the grundy function $g(x,y)$ of $G_1\times G_2$
 * is $g_1(x)\times g_2(y)$.
 * Usage: NimProduct nim; nim.mult(2, 3);
 * Source: https://github.com/bqi343/cp-notebook/blob/master/Implementations/content/combinatorial%20(11.2)/NimProduct.h
 * Time: $64$ xors per multiplication
 * Status:
 *  - tested on https://judge.yosupo.jp/problem/nim_product_64
 *  - tested on https://oj.vnoi.info/problem/winstrat
 */

typedef unsigned long long ull;
struct NimProduct {
	ull tmp[64][64], y[8][8][256];
	unsigned char x[256][256];
	NimProduct() {
		rep(i,0,256) rep(j,0,256) x[i][j] = mult_naive(i, j);
		rep(i,0,8) rep(j,0,8) rep(k,0,256)
			y[i][j][k] = mult_naive(prod2(8 * i, 8 * j), k);
	}
	ull prod2(int i, int j) {  // nim prod of 2^i, 2^j
		ull& u = tmp[i][j];
		if (u) return u;
		if (!(i & j)) return u = 1ULL << (i | j);
		int a = (i & j) & -(i & j);
		return u = prod2(i^a,j)^prod2((i^a)|(a-1),(j^a)|(i&(a-1)));
	}
	ull mult_naive(ull a, ull b) {
		ull c = 0; rep(i,0,64) if (a >> i & 1)
			rep(j,0,64) if (b >> j & 1) c ^= prod2(i, j);
		return c;
	}
	ull mult(ull a, ull b) const {
		ull c = 0; rep(i,0,8) rep(j,0,8)
			c ^= y[i][j][x[a >> (i * 8) & 255][b >> (j * 8) & 255]];
		return c;
	}
};
