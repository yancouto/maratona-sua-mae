#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const int MAX = 200012;
int bit[MAX];
int get(int i) {
	i += 2;
	int sum = 0;
	while(i) {
		sum += bit[i];
		i -= (i & -i);
	}
	return sum;
}
void add(int i, int val) {
	i += 2;
	for(; i < MAX; i += (i & -i))
		bit[i] += val;
}
void add(int i, int j, int val) {
	add(i, val); add(j + 1, -val);
}


int last[100009], n, m;
int main() {
	int i, x;
	for_tests(t, tt) {
		memset(bit, 0, sizeof bit);
		scanf("%d %d", &n, &m);
		for(i = 0; i < n; i++) {
			last[n - i] = i;
			add(0, n - i - 1, 1);
		}
		add(0, n - 1, -1);
		scanf("%d", &x);
		printf("%d", get(last[x]));
		add(last[x], n - 1, 1);
		last[x] = n;		
		for(i = 1; i < m; i++) {
			scanf("%d", &x);
			printf(" %d", get(last[x]));
			add(last[x], n - 1 + i, 1);
			last[x] = n - 1 + i + 1;
		}
		putchar('\n');
	}
	return 0;
}