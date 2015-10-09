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
const int MAX = 505;
const int oo = 100000000;

int n, m, bi, bj, ei, ej;
vector<int> g[MAX*MAX];
int tab[MAX][MAX];

bool isOK(int i, int j) { return i >= 0 && i < m && j >= 0 && j < n; }
int getPos(int i, int j) { return i * n + j; }

void add_edge(int i, int j) {
	int pos = i * n + j;
	if(isOK(i-1, j)) g[pos].pb(getPos(i-1, j));
	if(isOK(i+1, j)) g[pos].pb(getPos(i+1, j));
	if(isOK(i, j-1)) g[pos].pb(getPos(i, j-1));
	if(isOK(i, j+1)) g[pos].pb(getPos(i, j+1));
	if(isOK(i+1, j+1)) g[pos].pb(getPos(i+1, j+1));
	if(isOK(i+1, j-1)) g[pos].pb(getPos(i+1, j-1));
	if(isOK(i-1, j+1)) g[pos].pb(getPos(i-1, j+1));
	if(isOK(i-1, j-1)) g[pos].pb(getPos(i-1, j-1));
	
}

struct Quad {
	int pos, tot, ch;
	Quad() {}
	Quad(int p, int t, int c) : pos(p), tot(t), ch(c) {}
	bool operator <(const Quad &e) const {
		if(e.ch == ch) return e.tot < tot;
		return e.ch < ch;
	}
};

int mark[MAX*MAX];
Quad dik(int beg) {
	priority_queue<Quad> pq;
	pq.push(Quad(beg, 1, 0));
	while(!pq.empty()) {
		Quad no = pq.top();
		pq.pop(); 
		if(mark[no.pos]) continue;
		mark[no.pos] = 1;
		int x = no.pos / n;
		int y = no.pos % n;
		if(x == ei && y == ej) return no;
		for(int i = 0; i < g[no.pos].size(); i++) {
			int v = g[no.pos][i];
			if(mark[v]) continue;
			if(!tab[v/n][v%n]) continue;
			pq.push(Quad(v, no.tot+1, no.ch+(tab[x][y]!=tab[v/n][v%n])));			
		}
	}
	return Quad(0, oo, oo);
}

int main() {
	char c;
	scanf("%d %d", &m, &n);
	scanf("%d %d %d %d", &bi, &bj, &ei, &ej);
	bi--; bj--; ei--; ej--;
	for(int	i = 0; i < m; i++)
		for(int j = 0; j < n; j++) {
			scanf(" %c", &c);
			tab[i][j] = c - '0';
			add_edge(i, j);
		}
	Quad ans = dik(getPos(bi, bj));
	if(ans.ch == oo && ans.tot == oo) puts("0 0");
	else printf("%d %d\n", ans.tot, ans.ch);
	return 0;
}
