
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

#define xx first
#define yy second.first
#define ori second.second
#define mp make_pair

int n, res;
const int N = 3009;
set < pair<int, pair<int,int> > > xord, yord;
char z[N]; int L[N], D[N], R[N], U[N], Lb[N], Rb[N], Ub[N], Db[N];

vector < pair<int, pair<int,int> > > s;

int dist;
void go(int i){
	dist++;
	res = max(res,dist);
	int l = L[i], r = R[i], u = U[i], d = D[i];
	if(l != -1) R[l] = r;
	if(r != -1) L[r] = l;
	if(u != -1) D[u] = d;
	if(d != -1) U[d] = u;
	if(z[i] == '^' || z[i] == 'v'){
		if(z[i] == '^'){
			if(u != -1) go(u);
		}
		else if(d != -1) go(d);
	}
	else{
		if(z[i] == '<'){
			if(l != -1) go(l);
		}
		else if(r != -1) go(r);
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int x, y;
		scanf("%d %d %c", &x, &y, &z[a]);
		xord.insert(mp(x,mp(y,a)));
		yord.insert(mp(y,mp(x,a)));
		s.pb(mp(x,mp(y,a)));
	}
	for(int i = 0; i < n; i++) {
		L[i] = R[i] = U[i] = D[i] = -1;
		auto it = xord.find(s[i]);
		if(it != xord.begin() && prev(it)->xx == s[i].xx) U[i] = prev(it)->ori;
		if(next(it) != xord.end() && next(it)->xx == s[i].xx) D[i] = next(it)->ori;
		it = yord.find(mp(s[i].yy, mp(s[i].xx, i)));
		if(it != yord.begin() && prev(it)->xx == s[i].yy) L[i] = prev(it)->ori;
		if(next(it) != yord.end() && next(it)->xx == s[i].yy) R[i] = next(it)->ori;
		Lb[i] = L[i];
		Rb[i] = R[i];
		Ub[i] = U[i];
		Db[i] = D[i];
	}
	xord.clear(); yord.clear();
	for(int a=0;a<n;a++){
		dist = 0;
		go(a);
		for(int b=0;b<n;b++){
			L[b] = Lb[b]; R[b] = Rb[b];
			U[b] = Ub[b]; D[b] = Db[b];
		}
	}
	printf("%d\n", res);
}
