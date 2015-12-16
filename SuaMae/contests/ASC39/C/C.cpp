
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

#define mp make_pair

#define double long double

const double  PI = acos(-1);

const int MAXN = 100010;

int n, degl, mrk[MAXN];


double res;

struct cir{
	int x, y;
	ll r;
} c[MAXN];


struct sweep{
	int i, x, tip;
} ls[MAXN*2];

bool cmp(sweep a, sweep b){
	return (a.x<b.x || (a.x==b.x && a.tip < b.tip) || (a.x==b.x && a.tip==b.tip && c[a.i].r > c[b.i].r));
}

inline void botals(int i,int x,int tip){
	ls[degl].i = i;
	ls[degl].x = x;
	ls[degl++].tip = tip;
}

set <pair<pair<int,int>, int> > circ;

ll dist(int x,int y,int xx, int yy){
	return ll(xx-x)*ll(xx-x) + ll(yy-y)*ll(yy-y);
}

int main (){
	freopen("circles.in", "r", stdin);
	freopen("circles.out","w",stdout);
	scanf("%d", &n);
	degl=0;
	res = 0;
	for(int a=0;a<n;a++){
		scanf("%d%d%I64d", &c[a].x, &c[a].y, &c[a].r);
		botals(a,c[a].x-c[a].r, 0);
		botals(a, c[a].x+c[a].r, 1);
	}
	sort(ls,ls+degl,cmp);
	for(int a=0;a<degl;a++){
		int ii = ls[a].i;
		if(ls[a].tip == 1){
			if(mrk[ii] == 0)
				circ.erase(mp(mp(c[ii].y, c[ii].x),ii));
		}
		else{
			if(!circ.empty()){
				pair<pair<int,int>, int> c1 = *circ.lower_bound(mp(mp(c[ii].y,c[ii].x),ii));
				if(dist(c1.fst.snd,c1.fst.fst, c[ii].x, c[ii].y) < c[c1.snd].r * c[c1.snd].r){
					mrk[ii] = 1;
					continue;
				}
				pair<pair<int,int>, int> c2;
				if(c1 != *circ.begin()){
					c2 = *(--circ.lower_bound(mp(mp(c[ii].y,c[ii].x),ii)));
					if(dist(c2.fst.snd,c2.fst.fst, c[ii].x, c[ii].y) < c[c2.snd].r*c[c2.snd].r){
						mrk[ii] = 1;
						continue;
					}
				}
			}
			res += PI * c[ii].r * c[ii].r;
			circ.insert(mp(mp(c[ii].y,c[ii].x),ii));
		}
	}
	cout << setprecision(100) << res << "\n";
}
