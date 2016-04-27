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
const int N = 412345;
int tr[N * 32][2], a[N], all[N], d[N], o[N], ans[N], r[N], sz[N], p[N];

int n, en, mx;
void check(int v, int x) {
	//printf("checking %d on %d\n", x, v);
	int m = 0;
	for(int i = 29; i >= 0; i--) {
		int b = ((x >> i) & 1);
		if(tr[v][!b]) {
			v = tr[v][!b];
			m |= (1 << i);
		} else v = tr[v][b];
	}
	//printf("got %d\n", m);
	mx = max(mx, m);
}

void add(int l, int id, bool al=true) {
	//printf("\n\nADD(%d, %d)\n", l, a[id]);
	o[id] = l;
	sz[l]++;
	all[l] ^= a[id];
	int x = (al? all[l] : a[id])  ^ d[l];
	//printf("adding %d to %d\n", x, l);
	int v = r[l];
	for(int i = 29; i >= 0; i--) {
		int &nx = tr[v][(x >> i) & 1];
		if(!nx) nx = en++;
		v = nx;
	}
	//printf("\n\n===CHECKING====\n");
	check(r[l], x);
	check(r[l], d[l]);
	//printf("===============\n");
}

void dfs(int u, int x) {
	int any = 0;
	for(int i = 0; i <= 1; i++)
		if(tr[u][i])
			dfs(tr[u][i], (x << 1) | i), any = 1;
	if(!any) printf("%d, ", x);
}

void deb(int l) {
	int r = l, k = l;
	while(o[r + 1] == o[r]) r++;
	while(o[l - 1] == o[l]) l--;
	printf("[%d..%d] = {", l, r);
	dfs(::r[k], 0);
	printf("}\n");
}

void join(int l, int r) {
	if(sz[o[l]] > sz[o[r]]) {
		for(int i = r; i <= n && o[i]; i++)
			add(o[l], i);
		//deb(o[l]);
	} else {
		for(int i = l; i >= 1 && o[i]; i--) {
			d[o[r]] ^= a[i];
			add(o[r], i, false);
		}
		//deb(o[r]);
	}
}

int tryhard() {
	int M = 0;
	int bl, br;
	for(int i = 1; i <= n; i++) {
		int x = 0;
		for(int j = i; j <= n && o[j]; j++) {
			x ^= a[j];
			if(x > M)
				bl = i, br = j;
			M = max(M, x);
		}
	}
	printf("(%d, %d) = %d\n", bl, br, M);
	return M;
}

// breaks with args=115 n=5
int main(int argn, char **args) {
	srand(atoi(args[1]));
	int i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		a[i] = rand() % 1000000001,
		p[i] = i;
	random_shuffle(p, p + n);
	for(i = 1; i <= n; i++)
		printf("%d ", a[i]);
	putchar('\n');
	for(i = 1; i <= n; i++)
		printf("%d ", p[i]);
	putchar('\n');

	//for(i = 1; i <= n; i++)
	//	scanf("%d", &a[i]);
	//for(i = 1; i <= n; i++)
	//	scanf("%d", &p[n - i + 1]);
	for(int j = 1; j <= n; j++) {
		i = p[j];
		r[i] = en++;
		o[i] = i;
		add(i, i);
		//deb(i);
		if(o[i - 1]) join(i - 1, i);
		if(o[i + 1]) join(i, i + 1);
		ans[n - j + 1] = mx;
		int k = tryhard();
		printf("[%d] %d vs tryhard(%d)\n", j, mx, k);
		tryhard();
		assert(mx == tryhard());
		puts("==================");
	}
	for(i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
}
