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
const int MAX = 100009;
struct no {
	int a, b, i;
	bool operator < (no o) const { return pii(a, b) < pii(o.a, o.b); }
	bool operator == (no o) { return a == o.a && b == o.b; }
} l[MAX];
int p[MAX][19], r[MAX], lc[MAX], n;
char s[MAX];
int lcp(int i, int j) {
	int t = 0;
	for(int k = 18; k >= 0; k--)
		if(p[i + t][k] == p[j + t][k] && i + t + (1 << k) <= n && j + t + (1 << k) <= n)
			t += 1 << k;
	return t;
}

int main() {
	int i, j;
	while(true) {
		scanf("%s", s); n = strlen(s);
		if(s[0] == '*') return 0;
		for(i = 0; i < n; i++)
			p[i][0] = s[i];
		for(j = 1; j < 19; j++) {
			for(i = 0; i < n; i++)
				l[i] = no{p[i][j - 1], i + (1 << (j - 1)) < n? p[i + (1 << (j - 1))][j - 1] : -1, i};
			sort(l, l + n);
			for(i = 0; i < n; i++)
				p[l[i].i][j] = i && l[i] == l[i - 1]? p[l[i - 1].i][j] : i;
		}
		for(i = 0; i < n; i++)
			r[p[i][18]] = i;
		for(i = 0; i < n - 1; i++)
			lc[i] = lcp(r[i], r[i + 1]);
		int tot = lc[0], last = lc[0];
		for(i = 1; i < n - 1; i++)
			if(lc[i] > lc[i-1])
				tot += lc[i] - lc[i-1];
		printf("%d\n", tot);
	}
}
