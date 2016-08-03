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

const int MAXN = 112345, MAXT = 1123456;

int n, p[MAXN], sz[MAXN];

struct pti{
	int x, y;
	pti(int xx, int yy){
		x = xx;
		y = yy;
	}
	pti(){}
} s[MAXN];

struct arv{
	int mn, mx;
} tree[4*MAXT], es[MAXN];

int raiz(int i){
	if(p[i] == i) return i;
	return p[i] = raiz(p[i]);
}

arv junta(arv a, arv b){
	arv ans;
	ans.mn = min(a.mn, b.mn);
	ans.mx = max(a.mx, b.mx);
	return ans;
}

void join(int i, int j){
	i = raiz(i);
	j = raiz(j);
	if(i == j)
		return ;
	if(sz[i] > sz[j])
		swap(i, j);
	p[i] = j;
	upd(1, 0, DEZ, s[i].mn, s[i].mx, -1, -sz[i]);
	upd(1, 0, DEZ, s[j].mn, s[j].mx, -1, -sz[j]);
	sz[j] += sz[i];
	s[j] = junta(s[i], s[j]);
}

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			int x;
			scanf("%d %d", &x, &es[a].mn);
			es[a].mx = es[a].mn;
			p[a] = a;
		}
		scanf("%d", &m);
		for(int a=0;a<m;a++){
			char com[10];
			scanf(" %s", com);
			if(com[0] == 'r'){
				int i, j;
				scanf("%d %d", &i, &j);
				join(i, j);
			}
		}
	}
}
