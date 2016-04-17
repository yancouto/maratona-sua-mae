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

const int MAXN = 31234;

int n, m, deg[MAXN];

struct ares{
	int j, l, c;
	ares(int ii, int jj, int ll, int cc){
		i = ii;	j = jj;	l = ll;	c = cc;
	}
	ares(){}

};

vector<ares> v[MAXN];

void go(int v){
	for(ares nxt:)
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n-1;a++){
		int i, j, l, c;
		scanf("%d", &i, &j, &l, &c);
		v[i].pb(ares(j, l, c));
		v[j].pb(ares(i, l, c));
	}
	go(1);

}