
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

#define temp template<typename num>
#define ptn point<num>
temp struct point {
	num x, y;
	ptn(){}
	ptn(num a, num b) : x(a), y(b){}
	num operator * (ptn o) const { return x*o.x + y*o.y; }
	ptn operator * (num i) const { return ptn(x*i,y*i); }
	ptn operator - (ptn o) const { return ptn(x - o.x, y- o.y);}
	num operator ^ (ptn o) const { return x*o.y - y*o.x; }
	bool operator < (ptn o) const { return x < o.x || (x==o.x && y < o.y);}
};
temp inline num cross(ptn a,ptn b,ptn c){ return (b-a) ^ (c-a); }

temp double distSegSqr(ptn a,ptn b,ptn c){
	double d = (b-a) ^ (c-a);
	return d * d / ((b-a) * (b-a));
}


typedef point <int> pti;

const int MAXN = 100010, INF  = 1000000;

int n;
pti p[MAXN], np[MAXN];

int up[MAXN], lo[MAXN], degu, degl;

int t;

int main (){
	while(scanf("%d", &n) && n!=0){

		for(int a=0;a<n;a++){
			scanf("%d%d", &p[a].x, &p[a].y);
		}
		sort(p,p+n);
		degu = 0;
		for(int a=0;a<n;a++){
			while(degu>=2 && cross(p[up[degu-1]], p[up[degu-2]], p[a]) < 0)
				degu--;
			up[degu++] = a;

		}
		degl = 0;
		for(int a=n-1;a>=0;a--){
			while(degl>=2 && cross(p[lo[degl-1]], p[lo[degl-2]], p[a]) < 0)
				degl--;
			lo[degl++] = a;
		}
		pti np[MAXN];
		int mrk[MAXN], deg=0;
		memset(mrk,0,sizeof(mrk));
		for(int a=0;a<degu;a++){
			if(mrk[up[a]]==0)
				np[deg++] = p[up[a]];
			mrk[up[a]]=1;
		}
		for(int a=0;a<degl;a++){
			if(mrk[lo[a]]==0)
				np[deg++] = p[lo[a]];
			mrk[lo[a]] = 1;
		}
		double res = INF;
		for(int a=0;a<deg;a++){
			double ans = 0;
			pti v1, v2;
			if(a==0)
				v1 = np[deg-1];
			else
				v1 = np[a-1];
			v2 = np[a];
			for(int b=0;b<deg;b++){
				ans = max(ans,sqrt(distSegSqr(v1, v2, np[b])));
			}
			res = min(res,ans);
		}
		res += 1/200.;
		t++;
		printf("Case %d: %.2f\n", t, res);
	}
	return 0;
}
