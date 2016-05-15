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
const int N = 512345;

int st[N], f[N], in[N], deg[N], sn;

int main() {
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &f[i]), f[i]--;
		deg[f[i]]++;
		in[i] = 1;
	}
	for(i = n; i < 2*n; i++) {
		scanf("%d", &f[i]), f[i]--;
		if(deg[i] == 0) st[sn++] = i;
	}
	while(sn) {
		i = st[--sn];
		in[i] = 1;
		if(in[f[i]]) {
			in[f[i]] = 0;
			if(--deg[f[f[i]]] == 0) st[sn++] = f[f[i]];
		}
	}
	for(i = 0; i < 2*n; i++)
		if(in[i])
			printf("%d ", i + 1);
	putchar('\n');
}
