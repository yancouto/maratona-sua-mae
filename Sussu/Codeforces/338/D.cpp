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
const ll modn2 = 1000000006;
inline ll mod2(ll x) { return x % modn2; }

const int MAXN = 200010;

int n, m, mrk[MAXN];

ll res, e, num, q[MAXN], p[MAXN];

ll expo(ll base,ll ex){
	if(ex == 1)
		return base;
	if(ex == 0)
		return 1;
	ll ans = 1;
	if(ex%2)
		ans = mod(ans*base);
	ll aux = expo(base,ex/2);
	ans = mod( ans * mod(aux*aux));
	return ans;
}

int main (){
	scanf("%d", &n);
	num = 1;
	for(int a=0;a<n;a++){
		cin >> p[a];
		num *= p[a];
		q[p[a]]++;
	}
	ll nper = 0;
	for(int a=0;a<n;a++){
		nper = max(nper,(q[p[a]]%2));
	}
	e = 1;
	int f = 1;
	for(int a=0;a<n;a++){
		if(mrk[p[a]]==0){
			mrk[p[a]] = 1;
			ll aux = (q[p[a]]+1);
			if(f && !(aux%2)){
				aux /= 2;
				f--;
			}
			e = mod2(e*aux);
		}
	}
	if(f){
		e /= 2;
	}
	res = 1;
	for(int a=0;a<n;a++){
		res = mod(res * expo(p[a],e));
	}
	if(!nper){
		ll sqr = 1;
		for(int a=0;a<n;a++){
			if(mrk[p[a]] == 1){
				mrk[p[a]] = 0;
				sqr = mod(sqr * expo(p[a],q[p[a]]/2));
			}
		}
		res = mod(res * sqr);
	}

	cout << res;
}