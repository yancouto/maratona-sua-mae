#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int MAX = 200009;
int bit[MAX];
int get(int i) {
	int sum = 0;
	for(i += 2; i; i -= (i & -i))
		sum += bit[i];
	return sum;
}
int get(int i, int j) { return get(j) - get(i - 1); }
int add(int i, int x) {
	for(i += 2; i < MAX; i += (i & -i))
		bit[i] += x;
}


int p[MAX];
int main() {
	int i, n, m, x;
	for_tests(t, tt) {
		scanf("%d %d", &n, &m);
		memset(bit, 0, sizeof bit);
		for(i = 0; i < n; i++)
			p[i] = n - 1 - i;
		for(i = 0; i < n; i++)
			add(i, 1);
		for(i = 0; i < m; i++) {
			scanf("%d", &x); x--;
			printf("%d", get(p[x], n + m + 2) - 1);
			if(i != m - 1) putchar(' ');
			add(p[x], -1);
			add(p[x] = n + i, 1);
		}
		putchar('\n');
	}
}
