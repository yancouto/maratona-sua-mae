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

const int MAXN = 510;
int CNT = 10004;

int n, S, T;

struct itv{
	int i, j;
} seq[MAXN];

namespace f {
	const int maxv = 500009;
	const int maxe = 900009 * 2;
	typedef int num;
	num inf = INT_MAX;
	int n = maxv;

	int to[maxe], en, nx[maxe], es[maxe], lv[maxv], qu[maxv], cr[maxv];
	num cp[maxe], fl[maxe];


	bool bfs(int s, int t) {
		memset(lv, -1, sizeof(int) * n);
		lv[s] = 0;
		int a = 0, b = 0;
		qu[b++] = s; cr[s] = es[s];
		while(a < b) {
			for(int i = es[qu[a]]; i != -1; i = nx[i]) {
				if(cp[i] > fl[i] && lv[to[i]] == -1) {
					lv[to[i]] = lv[qu[a]] + 1;
					qu[b++] = to[i];
					cr[to[i]] = es[to[i]];
					if(to[i] == t) return true;
				}
			}
			a++;
		}
		return false;
	}

	num dfs(int u, int t, num mx) {
		if(u == t) return mx;
		for(int &i = cr[u]; i != -1; i = nx[i])
			if(cp[i] > fl[i] && lv[to[i]] == lv[u] + 1)
				if(int a = dfs(to[i], t, min(mx, cp[i] - fl[i]))) {
					fl[i] += a;
					fl[i ^ 1] -= a;
					return a;
				}
		return 0;
	}


	num max_flow(int s, int t) {
		num fl = 0, a;
		while(bfs(s, t))
			while(a = dfs(s, t, inf))
				fl += a;
		return fl;
	}

	void reset_all(int n2=maxv) { n = n2; en = 0; memset(es, -1, sizeof(int) * n); }
	void reset_flow() { memset(fl, 0, sizeof(num) * en); }

	void add_edge(int a, int b, num c, num rc=0) {
		fl[en] = 0; to[en] = b; cp[en] = c;  nx[en] = es[a]; es[a] = en++;
		fl[en] = 0; to[en] = a; cp[en] = rc; nx[en] = es[b]; es[b] = en++;
	}
}


void pre(){
	f::reset_flow();
	f::reset_all();
	for(int a=0;a<=10000;a++)
		f::add_edge(S, a, 1);

	for(int a=0;a<n;a++){
		for(int b = seq[a].i; b < seq[a].j;b++){
			f::add_edge(b, a+CNT, 1);
		}
	}
}

int main (){
	scanf("%d", &n);
	int mind = INT_MAX;
	S = 10001;
	T  = 10002;
	for(int a=0;a<n;a++){
		scanf("%d%d", &seq[a].i, &seq[a].j);
		mind = min(mind, seq[a].j-seq[a].i);
	}
	int i = 0, j = 10001;
	while(i < j){
		pre();
		int m = (i+j+1)/2;
		for(int a=CNT;a<n+CNT;a++)
			f::add_edge(a, T, m);
		int flow = f::max_flow(S, T);
		//printf("%d %d 	%d - flow %d\n", i,m, j, flow);
		if(flow == m*n)
			i = m;
		else
			j = m-1;
	}
	printf("%d\n", i*n);
}