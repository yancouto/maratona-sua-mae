#include <bits/stdc++.h>
#define mp make_pair
#define debug(args...) //fprintf(stderr, args)
#define pb push_back
#define ff first
#define ss second
using namespace std;

const int MAXN = 30010;

vector<int> seg[4*MAXN];
int arr[MAXN];

void build(int l, int r, int node) {
	if(l == r) {
		seg[node].pb(arr[l]);
		return;
	}
	int m = (l + r) / 2;
	build(l, m, 2*node);
	build(m + 1, r, 2*node + 1);
	int idxA = 0, idxB = 0;
	while(idxA < seg[2*node].size() && idxB < seg[2*node + 1].size())
		if(seg[2*node][idxA] < seg[2*node + 1][idxB])
			seg[node].pb(seg[2*node][idxA++]);
		else
			seg[node].pb(seg[2*node + 1][idxB++]);
	while(idxA < seg[2*node].size()) seg[node].pb(seg[2*node][idxA++]);
	while(idxB < seg[2*node + 1].size()) seg[node].pb(seg[2*node + 1][idxB++]);
}

int query(int l, int r, int node, int i, int j, int k) {
	if(i > j) return 0;
	if(l >= i && r <= j)
		return seg[node].end() - upper_bound(seg[node].begin(), seg[node].end(), k);
	if(l > j || r < i)
		return 0;
	int m = (l + r) / 2;
	return query(l, m, 2*node, i, j, k) + query(m + 1, r, 2*node + 1, i, j, k);
}

int main() {
	int n, q, ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
	build(0, n - 1, 1);
	scanf("%d", &q);
	while(q--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int i = a ^ ans;
		int j = b ^ ans;
		int k = c ^ ans;
		i--, j--;
		debug("QUERY %d %d %d\n", i, j, k);
		printf("%d\n", ans = query(0, n - 1, 1, max(i, 0), min(j, n - 1), k));
	}
	return 0;
}
