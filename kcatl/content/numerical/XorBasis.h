/**
 * Author: DrSwad
 * License: CC0
 * Description: Maintains a xor basis of d bits. Can change to bitsets for larger d.
 * add() returns true if vector is inserted, otherwise false. sz holds the current size of the basis.
 * Time: O(d)
 * Status: tested
 */
#pragma once

struct xor_basis{
	int d, sz;
	vector<ll> basis;
	xor_basis(int d) {
		this->d = d; sz = 0; basis.resize(d);
	}
	bool add(ll mask) {
		rep(i, 0, d) {
			if (mask & (1LL << i)) {
				if (!basis[i]) {
					basis[i] = mask; sz++;
					return 1;
				}
				mask ^= basis[i];
			}
		}
		return 0;
	}
};
