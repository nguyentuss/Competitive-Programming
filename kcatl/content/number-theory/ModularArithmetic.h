/**
 * Author: tomatoes
 * Date: 2023-07-03
 * License: CC0
 * Description: Operators for modular arithmetic.
 */
#pragma once

#include "euclid.h"

template <int m, bool prime = false>
struct ModInt {
	int x; ModInt(int x=0) : x(x) {}
	ModInt &operator+=(ModInt b) {x += b.x; x -= (x >= m) * m;
		return *this; }
	ModInt &operator-=(ModInt b) {x -= b.x; x += (x < 0) * m;
		return *this; }
	ModInt &operator*=(ModInt b) {x = 1LL * x * b.x % m;
		return *this; }
	ModInt &operator/=(ModInt o) {return (*this) *= o.invert();}
	ModInt operator+(ModInt b) const {return ModInt(*this) += b;}
	ModInt operator-(ModInt b) const {return ModInt(*this) -= b;}
	ModInt operator*(ModInt b) const {return ModInt(*this) *= b;}
	ModInt operator/(ModInt b) const {return ModInt(*this) /= b;}
	ModInt invert() const {
		if (prime) return (*this) ^ (m - 2);
		ll x, y, g = euclid(this->x, m, x, y);
		assert(g == 1); return ModInt((x + m) % m);
	}
	ModInt operator^(ll e) const {
		ModInt r = 1, a = *this;
		for (; e; e >>= 1, a *= a) if (e & 1) r *= a;
		return r;
	}
};

