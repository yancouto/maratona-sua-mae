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

#define lld I64d

const int MAXN = 110;
const int INF = 1000000009;

int n, m, out[MAXN], in[MAXN], FLOWM;

int d[MAXN][MAXN];

namespace f {

const int N = 205, M = 42025;
typedef int val;
typedef int num;
int es[N], to[M], nx[M], en, pai[N];
val fl[M], cp[M];
num cs[M], d[N];
const num inf = 1e9;
int seen[N], tempo;
int qu[N];

num tot;
bool spfa(int s, int t) {
	tempo++;
	int a = 0, b = 0;
	for(int i = 0; i < N; i++) d[i] = inf;
	d[s] = 0;
	qu[b++] = s;
	seen[s] = tempo;
	while(a != b) {
		int u = qu[a++]; if(a == N) a = 0;
		seen[u] = 0;
		for(int e = es[u]; e != -1; e = nx[e])
			if(cp[e] - fl[e] > val(0) && d[u] + cs[e] < d[to[e]]) {
				d[to[e]] = d[u] + cs[e]; pai[to[e]] = e ^ 1;
				if(seen[to[e]] < tempo) { seen[to[e]] = tempo; qu[b++] = to[e]; if(b == N) b = 0; }
			}
	}
	if(d[t] == inf) return false;
	tot += d[t];
	int u = t;
	while(u != s) {
		fl[pai[u]]--;
		fl[pai[u] ^ 1]++;
		u = to[pai[u]];
	}
	return true;
}

void init(int n) {
	en = 0;
	memset(es, -1, sizeof(int) * n);
}

val flow;
num mncost(int s, int t) {
	tot = 0; flow = 0;
	while(spfa(s, t)) flow++;
	//printf("FLOW %d\n", flow);
	if(flow != FLOWM) tot = -1;
	return tot;
}

void add_edge(int u, int v, val c, val rc, num s) {
	//printf("i %d j %d c %d rc %d s %d\n", u, v, c, rc, s);
	fl[en] = 0; cp[en] =  c; to[en] = v; nx[en] = es[u]; cs[en] =  s; es[u] = en++;
	fl[en] = 0; cp[en] = rc; to[en] = u; nx[en] = es[v]; cs[en] = -s; es[v] = en++;
}
}


int main (){
	freopen("rentacar.in", "r", stdin);
	freopen("rentacar.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int s = 0, t = 2*n + 1;
	f::init(2*n+5);
	for(int a=1;a<=n;a++){
		scanf("%d%d", &out[a], &in[a]);
		FLOWM += out[a];
		f::add_edge(s, a, in[a], 0, 0);
		f::add_edge(a+n, t, out[a], 0, 0);
	}
	for(int a=0;a<=n;a++){
		for(int b=0;b<=n;b++){
			d[a][b] = INF;
			if(a == b) d[a][b] = 0;
		}
	}
	for(int a=1;a<=m;a++){
		int i, j;
		int k;
		scanf("%d %d %d", &i, &j, &k);
		d[i][j] = min(d[i][j], k);
		d[j][i] = d[i][j];
		//printf("%d %d %lld\n", i, j, d[i][j]);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j =1;j<=n;j++){
				if(d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
	for(int a=1;a<=n;a++){
		for(int b=1;b<=n;b++){
			if(d[a][b] != INF)
				f::add_edge(a, b+n, out[b], 0, d[a][b]);
		}
	}
	printf("%d\n", f::mncost(s, t));
	return 0;
}