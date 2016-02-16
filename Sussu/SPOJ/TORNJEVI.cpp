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

const int MAXN = 10010*8, MAXT = 110;

#define DL 1
#define DR 2
#define UR 3
#define UL 4

stack<int> s;

int n, m, proi[MAXN][5], ind[MAXT][MAXT], c[MAXN];
int u[MAXT][MAXT], l[MAXT][MAXT], r[MAXT][MAXT], d[MAXT][MAXT];
pii <int,int> pos[MAXN];

char M[MAXT][MAXT];

bool valid(int i,int j){
	return (i>0 && j>0 && i<=n && j<=m); 
}

bool validp(pii a){
	return valid(a.fst, a.snd);
}

bool eht(int v){
	return (v > 0);
}

int pos(int v,int p){
	return v*4+p-1;
}

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
	for(int nxt: adj[v]){
		if(c[nxt]) continue;
		c[nxt] = c[v];
		go(nxt);
	}
}

void tudoadd(int v){
	for(int a=1;a<deg;a++){
		for(int b=sim(pos(a,1)); b<=nao(pos(a,4)); b++){
			add(b, v);
		}
	}
}

int main (){
	scanf("%d%d", &n, &m);
	int deg = 1;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			scanf(" %c", &M[a][b]);
			if(M[a][b] == 'T'){
				ind[a][b] = deg++;
				pos[ind[a][b]] = pii(a, b);
				add(sim(pos(ind[a][b],UL)), nao(pos(ind[a][b],UR)));
				add(sim(pos(ind[a][b],UL)), nao(pos(ind[a][b],DL)));
				add(sim(pos(ind[a][b],UL)), nao(pos(ind[a][b],DR)));
				add(sim(pos(ind[a][b],UR)), nao(pos(ind[a][b],UL)));
				add(sim(pos(ind[a][b],UR)), nao(pos(ind[a][b],DL)));
				add(sim(pos(ind[a][b],UR)), nao(pos(ind[a][b],DR)));
				add(sim(pos(ind[a][b],DL)), nao(pos(ind[a][b],UR)));
				add(sim(pos(ind[a][b],DL)), nao(pos(ind[a][b],UL)));
				add(sim(pos(ind[a][b],DL)), nao(pos(ind[a][b],DR)));
				add(sim(pos(ind[a][b],DR)), nao(pos(ind[a][b],UR)));
				add(sim(pos(ind[a][b],DR)), nao(pos(ind[a][b],UL)));
				add(sim(pos(ind[a][b],DR)), nao(pos(ind[a][b],DL)));
			}
		}
	}
	for(int a=1;a<=n;a++){
		int ult = 0;
		for(int b=1;b<=m;b++){
			l[a][b] = ult;
			if(M[a][b] == 'T' || M[a][b] == '#')
				ult = ind[a][b];

		}
	}
	for(int a=1;a<=n;a++){
		int ult = 0;
		for(int b=m;b>0;b--){
			r[a][b] = ult;
			if(M[a][b] == 'T' || M[a][b] == '#')
				ult = ind[a][b];
		}
	}
	for(int b=1;b<=m;b++){
		int ult = 0;
		for(int a=1;a<=n;a++){
			u[a][b] = ult;
			if(M[a][b] == 'T' || M[a][b] == '#')
				ult = ind[a][b];
		}
	}
	for(int b=1;b<=m;b++){
		int ult = 0;
		for(int a=n;a>0;a--){
			d[a][b] = ult;
			if(M[a][b] == 'T' || M[a][b] == '#')
				ult = ind[a][b];
		}
	}

	for(int a=1;a<=n;a++){
		for(int b=1;b<=m;b++){
			if(M[a][b] != 'n') continue;
			int dd = d[a][b], uu = u[a][b],
			 ll = l[a][b], rr = r[a][b];
			if(eht(uu) + eht(dd) + eht(ll) + eht(rr) == 3){
				if(!eht(uu)){
					add(nao(pos(dd, UL)), sim(pos(dd, UR)));
					add(nao(pos(dd, UR)), sim(pos(dd, UL)));
					tudoadd(nao(pos(dd, DL)));
					tudoadd(nao(pos(dd, DR)));
					tudoadd(nao(pos(ll, UR)));
					tudoadd(nao(pos(ll, DR)));
					tudoadd(nao(pos(rr, UL)));
					tudoadd(nao(pos(rr, DL)));
				}
				else if(!eht(dd)){
					add(nao(pos(uu, DL)), sim(pos(uu, DR)));
					add(nao(pos(uu, DR)), sim(pos(uu, DL)));
					tudoadd(nao(pos(uu, UL)));
					tudoadd(nao(pos(uu, UR)));
					tudoadd(nao(pos(ll, UR)));
					tudoadd(nao(pos(ll, DR)));
					tudoadd(nao(pos(rr, UL)));
					tudoadd(nao(pos(rr, DL)));
				}
				else if(eht(ll) == 0){
					add(nao(pos(rr, UL)), sim(pos(rr, DL)));
					add(nao(pos(rr, DL)), sim(pos(rr, UL)));
					tudoadd(nao(pos(rr, UR)));
					tudoadd(nao(pos(rr, DR)));
					tudoadd(nao(pos(uu, DL)));
					tudoadd(nao(pos(uu, DR)));
					tudoadd(nao(pos(dd, UL)));
					tudoadd(nao(pos(dd, UR)));
				}
				else{
					add(nao(pos(ll, UR)), sim(pos(ll, DR)));
					add(nao(pos(ll, DR)), sim(pos(ll, UR)));
					tudoadd(nao(pos(ll, UL)));
					tudoadd(nao(pos(ll, DL)));
					tudoadd(nao(pos(uu, DL)));
					tudoadd(nao(pos(uu, DR)));
					tudoadd(nao(pos(dd, UL)));
					tudoadd(nao(pos(dd, UR)));
				}
			}
			else if(eht(uu) + eht(dd) + eht(ll) + eht(rr) == 2){
				if(eht(uu) + eht(ll) == 2){
					 add(sim(pos(ll, UL), nao(pos(uu, UL))));
					 add(sim(pos(ll, UL), nao(pos(uu, UR))));
					 add(sim(pos(ll, DL), nao(pos(uu, UL))));
					 add(sim(pos(ll, DL), nao(pos(uu, UR))));

					 add(sim(pos(uu, UL), nao(pos(ll, UL))));
					 add(sim(pos(uu, UL), nao(pos(ll, DL))));
					 add(sim(pos(uu, UR), nao(pos(ll, UL))));
					 add(sim(pos(uu, UR), nao(pos(ll, DL))));
				}
				else if(eht(uu) + eht(rr) == 2){
					 add(sim(pos(rr, UR), nao(pos(uu, UL))));
					 add(sim(pos(rr, UR), nao(pos(uu, UR))));
					 add(sim(pos(rr, DR), nao(pos(uu, UL))));
					 add(sim(pos(rr, DR), nao(pos(uu, UR))));

					 add(sim(pos(uu, UL), nao(pos(rr, UR))));
					 add(sim(pos(uu, UL), nao(pos(rr, DR))));
					 add(sim(pos(uu, UR), nao(pos(rr, UR))));
					 add(sim(pos(uu, UR), nao(pos(rr, DR))));
				}
				else if(eht(dd) + eht(ll) == 2){
					 add(sim(pos(ll, UL), nao(pos(dd, DL))));
					 add(sim(pos(ll, UL), nao(pos(dd, DR))));
					 add(sim(pos(ll, DL), nao(pos(dd, DL))));
					 add(sim(pos(ll, DL), nao(pos(dd, DR))));

					 add(sim(pos(dd, DL), nao(pos(ll, UL))));
					 add(sim(pos(dd, DL), nao(pos(ll, DL))));
					 add(sim(pos(dd, DR), nao(pos(ll, UL))));
					 add(sim(pos(dd, DR), nao(pos(ll, DL))));
				}
				else{
					 add(sim(pos(rr, UR), nao(pos(dd, DL))));
					 add(sim(pos(rr, UR), nao(pos(dd, DR))));
					 add(sim(pos(rr, DR), nao(pos(dd, DL))));
					 add(sim(pos(rr, DR), nao(pos(dd, DR))));

					 add(sim(pos(dd, DL), nao(pos(rr, UR))));
					 add(sim(pos(dd, DL), nao(pos(rr, DR))));
					 add(sim(pos(dd, DR), nao(pos(rr, UR))));
					 add(sim(pos(dd, DR), nao(pos(rr, DR))));
				}
			}
			else{
				if(eht(uu)){
					add(nao(pos(uu, DL), sim(pos(uu, DR))));
					add(nao(pos(uu, DR), sim(pos(uu, DL))));
					tudoadd(nao(pos(uu, UR)));
					tudoadd(nao(pos(uu, UL)));
				}
				if(eht(dd)){
					add(nao(pos(dd, UL), sim(pos(dd, UR))));
					add(nao(pos(dd, UR), sim(pos(dd, UL))));
					tudoadd(nao(pos(dd, DR)));
					tudoadd(nao(pos(dd, DL)));
				}
				if(eht(ll)){
					add(nao(pos(ll, UR), sim(pos(ll, DR))));
					add(nao(pos(ll, DR), sim(pos(ll, UR))));
					tudoadd(nao(pos(ll, DL)));
					tudoadd(nao(pos(ll, UL)));
				}
				else{
					add(nao(pos(rr, DL), sim(pos(rr, UL))));
					add(nao(pos(rr, UL), sim(pos(rr, DL))));
					tudoadd(nao(pos(rr, UR)));
					tudoadd(nao(pos(rr, DR)));
				}
			}
		}
	}

	for(int a=1;a<deg;a++){
		for(int b=sim(pos(a,1)); b<=nao(pos(a,4)); b++){
			if(!mrk[b])
				dfs(b);
		}
	}
	int cor = 1;
	while(!s.empty()){
		int v = s.top();
		s.pop();
		if(c[v]) continue;
		c[v] = cor++;
		go(v);
	}
	for(int a=0;a<)
}