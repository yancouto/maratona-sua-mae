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

const int MAXN = 30010;

int n, m, ini[MAXN], fim[MAXN], ans, pai[MAXN], sz[MAXN], cnt, add, ver, res, mrk[MAXN];

struct ares{
	int i, j, k, ind;
} ar[MAXN];

struct qry{
	int i, j;
	char t;
	qry(){};
	qry(char tt, int ii, int jj){
		t = tt;i = ii;j = jj;
	};
} q[MAXN*2];

vector<qry> s;

stack <int> roll;

bool cmp(ares a, ares b){
	return a.k < b.k;
}


void pre(int d){
	s.clear();
	int i = 0, f = 0;
	while( f != m ){
		if( ar[f].k - ar[i].k <= d ){
			ini[f] = s.size();
			s.pb(qry(1, f));
			f++;
		}
		else{
			s.pb(qry(0,0));
			while(ar[f].k - ar[i].k > d){
				fim[i] = s.size();
				s.pb(qry(2, i));
				i++;
			}
		}
	}
	s.pb(qry(0,0));
	while( i != m ){
		fim[i] = s.size();
		s.pb(qry(2, i));
		i++;
	}
}

int raiz(int u){
	while(u != pai[u]) u = pai[u];
	return u;
}

void join(ares a){
	int u = a.i, v = a.j;
	u = raiz(u);
	v = raiz(v);
	if( u == v )return ;
	if(sz[u] < sz[v]){
		pai[u] = v;
		sz[v] += sz[u];
		roll.push(u);
	}
	else{
		pai[v] = u;
		sz[u] += sz[v];
		roll.push(v);
	}
	cnt--;
	add++;
}

void rollback(int d){
	while(d){
		int v = roll.top();
		roll.pop();
		sz[pai[v]] -= sz[v];
		pai[v] = v;
		cnt++;
		d--;
	}
}

void conec(int i, int j){
	if(i == j){
		if(!s[i].t && cnt == 1) printf("%d", );
		return ;
	}
	int m = (i+j)/2;
	int changes = 0;
	add = 0;
	for(int a=i;a<=m;a++){
		if(s[a].t == 1 && fim[s[a].i] > j){
			join(ar[s[a].i]);	
		}
	}
	changes = add;
	conec(m+1, j);
	rollback(changes);
	
	changes = 0;
	add = 0;
	for(int a=m+1;a<=j;a++){
		if(s[a].t == 2 && ini[s[a].i] < i){
			join(ar[s[a].i]);
		}
	}
	changes = add;
	conec(i, m);
	rollback(changes);
}

map <pii, int> mrk;

int main (){
	scanf("%d %d", &n, &m);
	cnt = n;
	for(int a=0;a<=n;a++){
		pai[a] = a;
		sz[a] = 1;
	}
	for(int a=0;a<m;a++){
		scanf("%c %d%d", &q[a].t, &q[a].i, &q[a].j);		
	}
	int deg = m;
	for(int a=m-1;a>=0;a--){
		if(q[a].t == '+' && !mrk[pii(q[a].i, q[a].j)]) q[deg++] = qry('-', q[a].i, q[a].j);
		if(q[a].t == '-') mrk[pii(q[a].i, q[a].j)] = 1;
	}
	conec(0, deg-1);
}
