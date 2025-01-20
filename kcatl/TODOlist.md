## TODO list

- [ ] Ternary XOR
	- https://oj.vnoi.info/src/3936282
	- NTU_LYB notebook
	- May update normal FWHT as well
- [ ] Lyndon factorization
	- Run enumeration?
- [ ] Main-Lorentz algorithm
	- https://cp-algorithms.com/string/main_lorentz.html
- [X] Circle circle intersection area
	- Added
	- Sanity-checked by Chillee but untested
	- Not imported due to space limitations
- [X] Mo's algorithm with updates
	- https://codeforces.com/contest/940/problem/F
	- Do we need template for this? Or just a small note? UPD: Opted for just a small note
	- Idea: Sort "answer" queries by (time/BLK, L/BLK, R)
	- BLK = $N^{2/3}$ (NOT $\sqrt{N}$)
- [X] Matroid intersection (weighted) 
- [X] New LCT
	- https://github.com/kth-competitive-programming/kactl/pull/124/files
- [X] Triconnected component
	- https://github.com/wesley-a-leung/Resources/blob/main/Content/C%2B%2B/graph/components/ThreeEdgeConnectedComponents.h
- [ ] Rotating calipers
	- Powered by Zigui notebook
	- Maybe reference HullDiameter?
- [ ] Highly composites, large primes list
- [X] Everything [here](https://judge.yosupo.jp/submissions?problem=&user=hieplpvip&status=&lang=&order=-id&page=0&pagesize=100)
- [ ] (After everything else) Trim notebook down to 25 pages

## Candidates for removal

- [ ] Table of content (can write by hand)
- Contest
	- [ ] Troubleshoot (may be more useful in appendix)?
- Math
	- [ ] Weird distributions (risky if WF)
- Data structures
	- [ ] Normal DSU (we have rollback DSU)
	- [ ] Wavelet tree (can always be solved with persistent 2D seg tree)
	- [ ] Matrix (matrix mul/pow should be doable)
	- [ ] Hashmap (not faster than normal gnu pbds hashmap
- Numerical
	- [ ] XorBasis (easy to code by heart)
	- [ ] FastSubsetTransform (if replaced with full FWHT)
- Number theory
	- [ ] ModularArithmetic (never used)
	- [ ] ModPow (easy to code by heart)
	- [ ] Mobius Function (should be remembered?)
- Combinatorial
- Graph
	- [ ] BellmanFord (nothing special, should be self-codeable)
	- [ ] EulerWalk (not difficult to code, but takes some effort)
 	- [ ] DFSMatching (we have hopcroftKarp)
	- [ ] MaximumIndependentSet (is literally just maximum clique)
	- [ ] TreeIsomorphism (idea is easy)
- Geometry
	- [ ] kdTree (rarely used, but high risk if left out)
- String
	- [ ] KMP (codeable, plus we have aho corasick)
	- [ ] Manacher	(we have eertree)
- Various
	- [ ] TernarySearch (easy to code by hand)
	- [ ] Transversal Matroid (if you know matroids you probably should know this)
	- [ ] Java (why???)


