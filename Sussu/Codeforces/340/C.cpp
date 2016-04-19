
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

const int MAXN = 2010;

int n;

#define y1 asjhdkajshd

ll x1, y1, x2, y2;

struct pti{
	ll x, y, d, dd;
	pti(){}
	pti(ll xis,ll yps){
		x = xis;
		y = yps;
		d = (x1 - xis)*(x1 - xis) + (y1 - yps)*(y1 - yps);
		dd = (x2 - xis)*(x2 - xis) + (y2 - yps)*(y2 - yps);
	}
} s[MAXN];

bool cmp(pti a, pti b){
	return ((a.d != b.d && a.d<b.d) || (a.d == b.d && a.dd > b.dd)); 
}

ll mai[MAXN];

int main (){
	scanf("%d", &n);
	cin >> x1 >> y1 >> x2 >> y2;
	for(int a=0;a<n;a++){
		cin >> s[a].x >> s[a].y;
		s[a] = pti(s[a].x, s[a].y);
	}
	sort(s, s+n, cmp);
	for(int a = n-1;a>=0;a--){
		mai[a] = max(mai[a+1], s[a].dd);
	}
	ll res = mai[0];
	for(int a=0;a<n;a++){
		res = min(res, mai[a+1] + s[a].d);
	}
	cout << res;
}
