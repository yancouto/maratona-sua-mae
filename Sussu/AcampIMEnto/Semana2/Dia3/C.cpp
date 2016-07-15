#include <bits/stdc++.h>
#define mp make_pair
#define debug(args...) fprintf(stderr, args)
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 3123;

int n, v[MAXN];
map<int, int> m;
int lazy[MAXN];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		lazy[i] = 1;
	}
	for(int i = 0; i < n; i++) {
		debug("indice %d\n", i);
		for(pii p : m) {
			debug("Terminando em %d tamanho %d\n", p.ff, p.ss);
		}
		for(int j = i + 1; j < n; j++) {
			if(m.find(v[j] - v[i]) != m.end())
				lazy[j] = max(lazy[j], m[v[j] - v[i]] + 2);
		}
		m[v[i]] = max(m[v[i]], lazy[i]);
	}
	int ans = 0;
	for(pii p : m) {
		debug("Terminando em %d tamanho %d\n", p.ff, p.ss);
		ans = max(ans, p.ss);
	}
	printf("%d\n", ans);
	return 0;
}
