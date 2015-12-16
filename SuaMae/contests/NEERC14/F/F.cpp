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
const int N = 1010;
int a[N];
bitset<1020> b[N];

char s[N];
int mrk[N], val[256];
void read(bitset<1020> &bs) {
	scanf("%s", s);
	for(int i = 0; s[i]; i++)
		for(int j = 0; j < 4; j++)
			bs.set(4 * i + j, val[s[i]] & (1 << j));
}

void prn(bitset<1020> &bs) {
	for(int i = 0; i < 30; i++)
		printf("%d", (int)bs[i]);
	putchar('\n');
}

int main() {
	freopen("filter.in", "r", stdin);
	freopen("filter.out", "w", stdout);
	int i = 0, m, f, q, n, j, u;
	for(char c : "0123456789abcdef") val[c] = i++;
	scanf("%d %d", &m, &f);
	for(i = 0; i < f; i++) scanf("%d", &a[i]);
	scanf("%d", &n);
	for(i = 0; i < n; i++) read(b[i]);
	scanf("%d", &q);
	for(i = 0; i < q; i++) {
		scanf("%d", &u);
		bitset<1020> bs;
		bs.reset();
		for(j = 0; j < f; j++) bs.set((ll(u) * ll(a[j])) % m);
		for(j = 0; j < n; j++)
			if(!mrk[j] && (bs | b[j]) == b[j])
				mrk[j] = 1;
	}
	printf("%d", accumulate(mrk, mrk + n, 0));
	for(i = 0; i < n; i++)
		if(mrk[i])
			printf(" %d", i);
	putchar('\n');
}
