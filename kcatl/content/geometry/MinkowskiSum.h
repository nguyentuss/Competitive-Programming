/**
 * Author: cp-algorithms
 * Date: 2019-11-02
 * License: CC0
 * Source: Tomatoes
 * Description: Minkowski sum of two polygons
 * Time: O(N + M)
 * Status: idk lol probably works
 */
#pragma once
#include "Point.h"

template<class P>
vector<P> minkowski(vector<P> &A, vector<P> &B) {
	int i = 0, j = 0, m = sz(A), n = sz(B);
	vector<P> C;
	C.push_back(A[0] + B[0]);
	while (i < m || j < n) {
		P last = C.back();
		P v1 = A[(i + 1) % m] - A[i];
		P v2 = B[(j + 1) % n] - B[j];
		if (j == n || (i < m && v1.cross(v2) >= 0)) {
			C.push_back(last + v1); ++i;
		} else {
			C.push_back(last + v2); ++j;
		}
	}
	C.pop_back();
	return C;
}

