/**
 * Author: Neko
 * Date: 2015-03-19
 * License: CC0
 * Source: me
 * Description: Random number generators.
 */
#pragma once

mt19937 rng(time(NULL)); // or mt19937_64
rng(); // random 32 bits
shuffle(perm.begin(), perm.end(), rng); // shuffle permutation

int RAND(int lo, int hi) { // uniform distribution
	uniform_int_distribution<int>(lo, hi) dst;
	return dst(rng);
}

