#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
pair<int, int> es[100009];
int e_n;
int is_fib[100009];
int S1[100009], size1[100009];
int find1(int i) {
	if(S1[S1[i]] != S1[i]) S1[i] = find1(S1[i]);
	return S1[i];
}

int join1(int a, int b) {
	if(a == b) return 0;
	if(size1[a] < size1[b]) swap(a, b);
	size1[a] += size1[b];
	S1[b] = a;
	return 1;
}

int S2[100009], size2[100009];
int find2(int i) {
	if(S2[S2[i]] != S2[i]) S2[i] = find2(S2[i]);
	return S2[i];
}

int join2(int a, int b) {
	if(a == b) return 0;
	if(size2[a] < size2[b]) swap(a, b);
	size2[a] += size2[b];
	S2[b] = a;
	return 1;
}

int fib[100];

int main() {
	int t, i, u, v, c;
	scanf("%d", &t);
	fib[0] = fib[1] = 1;
	is_fib[1] = 1;
	int fib_n;
	for(fib_n = 2; ; fib_n++) {
		fib[fib_n] = fib[fib_n-1] + fib[fib_n-2];
		if(fib[fib_n] > 100000) break;
		is_fib[fib[fib_n]] = 1;
	}
	for(int tt = 1; tt <= t; tt++) {
		scanf("%d %d", &n, &m);
		int all = 0, white = 0;
		e_n = 0;
		for(i = 0; i < n; i++) {
			S1[i] = S2[i] = i;
			size1[i] = size2[i] = 1;
		}
		for(i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &c); u--; v--;
			if(c == 0) all += join1(find1(u), find1(v));
			else es[e_n++] = make_pair(u, v);
		}
		printf("Case #%d: ", tt);
		for(i = 0; i < e_n; i++) {
			all += join1(find1(es[i].first), find1(es[i].second));
			white += join2(find2(es[i].first), find2(es[i].second));
			if(is_fib[white] && all == n - 1) {
				puts("Yes");
				break;
			}
		}
		if(i == e_n) puts("No");
	}
	return 0;
}