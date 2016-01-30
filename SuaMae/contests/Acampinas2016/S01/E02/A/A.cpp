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

int e[10009], w[10009];
int val(int i) {
	return e[i] + w[i + 1];
}

int main() {
	int i, n, m, j; char c;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++)
		for(j = 1; j <= n; j++) {
			scanf(" %c", &c);
			if(c == 'W') w[j]++;
			else e[j]++;
		}
	for(i = 1; i <= n; i++) e[i] += e[i - 1];
	for(i = n - 1; i >= 0; i--) w[i] += w[i + 1];
	int besti = 0;
	for(i = 1; i <= n; i++)
		if(val(besti) > val(i))
			besti = i;
	printf("%d %d\n", besti, besti + 1);
}
