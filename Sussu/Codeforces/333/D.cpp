#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

#define val first
#define pos second

const int MAXN = 500010;

ll s[MAXN], n, m, prox[MAXN], ant[MAXN];

stack <pii> dir, esq;

int main (){
	cin >> n >> m;

	memset(ant,-1,sizeof(ant));
	for(int a=0;a<=n;a++)
		prox[a] = n-1;

	for(int a=0;a<n;a++)
		cin >> s[a];
	for(int a=0;a<n-1;a++){
		s[a] = abs(s[a+1]-s[a]);
	}
	dir.push(mp(s[0],0));
	pii topo;
	for(int a=1;a<n-1;a++){
		topo = dir.top();
		while(!dir.empty() && s[a] >= topo.val){
			prox[topo.pos] = a;
			dir.pop();
			if(!dir.empty()) topo = dir.top();
		}
		if(!dir.empty()){
			topo = dir.top();
			ant[a] = topo.pos;
		}
		dir.push(mp(s[a],a));
	}

	esq.push(mp(s[n-2],n-2));
	for(int a=n-3;a>=0;a--){
		topo = esq.top();
		while(!esq.empty() && s[a] >= topo.val){
			ant[topo.pos] = a;
			esq.pop();
			if(!esq.empty()) topo = esq.top();
		}
		if(!esq.empty()){
			topo = esq.top();
			prox[a] = topo.pos;
		}
		esq.push(mp(s[a],a));
	}
	for(int a = n-2;a>=0;a--){
		if(prox[a]!=n-1 && s[prox[a]]==s[a]){
			prox[a] = prox[prox[a]];
		}
	}
	for(int a=0;a<m;a++){
		ll l, r;
		cin >> l >> r;
		l--;
		r--;
		ll res = 0;
		for(int b=l;b<=r-1;b++){
			res += (b - max(ant[b],l-1))*(min(prox[b],r) - b)*s[b];
		}
		cout << res;
		printf("\n");

	}
	return 0;
}