/**
 * Author: Neko
 * Date: 2015-03-19
 * License: CC0
 * Source: Neko
 * Description: Various debugging tricks
 */
#pragma once

// converts converts segfaults into Wrong Answers.
// Similarly one can catch SIGABRT (assertion failures) and SIGFPE (zero divisions).
// _GLIBCXX_DEBUG failures generate SIGABRT (or SIGSEGV on gcc 5.4.0 apparently).
signal(SIGSEGV, [](int) { _Exit(0); });

// kills the program on NaNs (1), 0-divs (4), infinities (8) and denormals (16).
feenableexcept(29);

// kills the program on integer overflows (but is really slow).
#pragma GCC optimize ("trapv")

// mt19937 randomizer
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int RAND(int lo, int hi) {return uniform_int_distribution<int>(lo, hi)(rng);}

// runs until timeouts
double t = clock();
while ((clock() - t) / CLOCKS_PER_SEC < TIME_LIMIT) {}

