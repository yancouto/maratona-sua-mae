#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 8*100010;

int n, deg, mrk[MAXN], c[MAXN];

map<ll, int> indi, indj;

stack<int> s;

vector <int> adj[MAXN], inv[MAXN];

inline int sim(int v){
	return 2*v;
}

inline int nao(int v){
	return sim(v)+1;
}

void dfs(int v){
	mrk[v] = 1;
	for(int nxt: adj[v]){
		if(mrk[nxt]) continue;
		dfs(nxt);
	}
	s.push(v);	
}

void go(int v){
	for(int nxt: inv[v]){
		if(c[nxt]) continue;
		c[nxt] = c[v];
		go(nxt);
	}
}

void add(int i,int j){
	adj[i].pb(j);
	inv[j].pb(i);
}

struct ares{
	int i, j;
	char s1, s2;
} ar[MAXN];

int main(){
	scanf("%d", &n);
	deg = 1;
	for(int a=0;a<n;a++){
		ll i, j;
		char s1, s2;
		cin >> i >> j;
		scanf(" %c1 %c1", &s1, &s2);
		if(indi.find(i) == indi.end())
			indi[i] = deg++;
		if(indj.find(j) == indj.end())
			indj[j] = deg++;	
		int x = indi[i];
		int y = indj[j];
		ar[a].i = x; ar[a].j = y;
		ar[a].s1 = s1; ar[a].s2 = s2;

	}
	int i = 0, f = n-1;
	while(i < f){
		int m = (i+f+1)/2;
		for(int a=0;a<=m;a++){
			int x = ar[a].i, y = ar[a].j;
			if(ar[a].s1 == ar[a].s2){
				add(sim(x), sim(y));
				add(nao(x), nao(y));
				add(sim(y), sim(x));
				add(nao(y), nao(x));
			}
			else{
				add(sim(x), nao(y));
				add(nao(x), sim(y));
				add(sim(y), nao(x));
				add(nao(y), sim(x));
			}
		}
		for(int a=sim(1);a<=nao(deg-1);a++){
			if(!mrk[a])
				dfs(a);
		}
		int cor = 1;
		while(!s.empty()){
			int v = s.top();
			s.pop();
			if(c[v])continue;
			c[v] = cor++;
			go(v);
		}
		int res = 1;
		for(int a=1;a <= deg-1;a++){
			if(c[sim(a)] == c[nao(a)]){
				res = 0;
				break;
			}
		}
		if(res) i = m;
		else f = m-1;

		for(int a=sim(1);a<=nao(deg-1);a++){
			adj[a].clear();
			inv[a].clear();
			mrk[a] = 0;
			c[a] = 0;
		}
	}
	for(int a=0;a<n;a++){
		if(a <= i) puts("Yes");
		else puts("No");
	}
}