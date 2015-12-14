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
const int N = 100009;
int a[N], p[10]; char s[N][5];
int ct[10];
int has[10][256];

int sz;
char *str = "ABP";
ll solve() {
	ll tot = 0; int i;
	for(char *c = str; *c; c++)
		for(i = 0; i < sz; i++)
			if(has[p[i]][*c] && (!i || !has[p[i - 1]][*c]))
				tot++;
	return tot;
}


int b[N];
int main() {
	int i, n, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%s", s[i]);
		b[i] = a[i] = s[i][0] * 256 * 256 + s[i][1] * 256 + s[i][2]; 
	}
	sort(b, b + n);
	sz = unique(b, b + n) - b;
	for(i = 0; i < n; i++) {
		a[i] = lower_bound(b, b + sz, a[i]) - b;
		ct[a[i]]++;
		has[a[i]][s[i][0]] = 1;
		has[a[i]][s[i][1]] = 1;
		has[a[i]][s[i][2]] = 1;
	}
	for(i = 0; i < sz; i++)
		p[i] = i;
	ll mn = LLONG_MAX;
	do {
		mn = min(mn, solve());
	} while(next_permutation(p, p + sz));
	printf("%lld\n", mn);
	do {
		if(solve() == mn) {
			for(i = 0; i < sz; i++)
				for(j = 0; j < n; j++)
					if(a[j] == p[i])
						printf("%d ", j + 1);
			putchar('\n');
			return 0;
		}
	} while(next_permutation(p, p + sz));
}
