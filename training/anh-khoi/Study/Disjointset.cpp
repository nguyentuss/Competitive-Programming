void init() {
	for (int i = 1 ; i <= n ; i++) 
		root[i] = i;
}
int findroot(int u) {
	if (u == root[u]) return u;
	else {
		root[u] = findroot(root[u]);
		return root[u];
	}
}
void unionset(int u , int v) {
	int rootu = findroot(u);
	int rootv = findroot(v);
	if (rootu != rootv)
		root[root[u]] = rootv;
}	
