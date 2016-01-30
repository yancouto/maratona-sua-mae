
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

int t;

#define double long double

#define temp template<typename num>
#define ptn point<num>

temp struct point {
	num x, y;
	ptn() {}
	ptn(num a, num b) : x(a), y(b) {}
	ptn operator + (ptn o) const { return ptn(x + o.x, y + o.y); }
	ptn operator - (ptn o) const { return ptn(x - o.x, y - o.y); }
	num operator * (ptn o) const { return x*o.x + y*o.y; }
	num operator ^ (ptn o) const { return x * o.y - y * o.x; }
	ptn operator * (num i) const { return ptn(x*i, y*i); }
	num distSqr(ptn o) const { return (*this - o) * (*this - o); }
};

temp inline num cross(ptn a, ptn b, ptn c) { return (c - a) ^(b - a); }
temp inline bool betweenSeg(ptn a, ptn b, ptn c){ return cross(a, b, c) == 0 && ((b - c) * (a - c) <= 0);}

temp bool intersectSeg(ptn a, ptn b, ptn c, ptn d){
	if(betweenSeg(a, b, c) || betweenSeg(a, b, d) || betweenSeg(c, d, a) || betweenSeg(c, d, b)) return true;
	if(((cross(a, b, c) > 0) ^(cross(a, b, d) > 0)) && ((cross(c, d, a) > 0) ^ (cross(c, d, b) > 0))) return true;
	return false;
}

temp struct line {
	num a, b, c;
	line () {}
	line (num aa, num bb, num cc) : a(aa), b(bb), c(cc) {}
	line (ptn s, ptn e) : a(e.y - s.y), b(s.x - e.x), c(a*s.x + b*s.y) {}
	line pass(ptn p){ return line(a, b, a*p.x + b*p.y); }
	
	point <double> inter(line o){
		double d = a*o.b - o.a*b;
		if( d==0) return point<double>(0, 0);
		return point<double>((o.b * c - b * o.c)/d, (a * o.c - o.a * c)/d);
	}
};

typedef point<int> pti;
typedef point<double> ptd;
typedef line<int> lni;
typedef line<double> lnd;

const int MAXN = 110;

int n, dege, apaga[MAXN];

struct ares{
	double x, y;
	double xx, yy;
} ar[MAXN*2];

struct even{
	int t;
	double x, y;
	int i, j;
} e[MAXN*MAXN + MAXN*3];

void add(int t, double x, double y, int i, int j){
	e[dege].t = t;
	e[dege].x = x;
	e[dege].y = y;
	e[dege].i = i;
	e[dege].j = j;
	dege++;
}

bool cmp(even a, even b){
	return a.x < b.x;
}

double coef(int i){
	return (ar[i].yy - ar[i].y)/(ar[i].xx - ar[i].x);
}

bool coefcmp(int i, int j){
	return coef(i) < coef(j);
}

bool coefigual(int i, int j){
	return abs((ar[i].yy - ar[i].y)*(ar[j].xx - ar[j].x) - (ar[j].yy - ar[j].y)*(ar[i].xx - ar[i].x)) < 1e-7;
}

ptd interSeg(ares i, ares j){
	ptd ans;
	ans.x = -999.;
	ans.y = -999.;
	if(intersectSeg(ptd(i.x, i.y), ptd(i.xx, i.yy), ptd(j.x, j.y), ptd(j.xx, j.yy))){
		lnd l1 = lnd(ptd(i.x, i.y), ptd(i.xx, i.yy));
		lnd l2 = lnd(ptd(j.x, j.y), ptd(j.xx, j.yy));
		ans = l1.inter(l2);
	}
	return ans;
}

double dist(double x, double y, double xx, double yy){
	//printf("soma distancia entre (%f %f) e (%f %f)\n", x, y, xx, yy);
	return sqrt((x - xx)*(x - xx) + (y - yy)*(y-yy));
}

int main (){
	while(scanf("%d", &n) != EOF && n != 0){
		memset(apaga, 0, sizeof(apaga));
		double res = 0;
		dege = 0;

		for(int a=0;a<n;a++){
			double x, h, b; 
			scanf("%Lf %Lf %Lf", &x, &h, &b);
			ar[a*2].x = x - (double)b/2.;
			ar[a*2].y = 0;
			ar[a*2].xx = x;
			ar[a*2].yy = h;
			ar[a*2+1].x = x;
			ar[a*2+1].y = h;
			ar[a*2+1].xx = x +  (double)b/2.;
			ar[a*2+1].yy = 0;

			add(0, x - (double)b/2., 0, a*2, -1);
			add(1, x, h, a*2, a*2+1);
			add(2, x + (double)b/2., 0, a*2+1, -1);
		}
		for(int a=0;a<n*2;a++){
			for(int b=a+1;b<2*n;b++){
				if((abs(ar[a].x - ar[b].x) < 1e-7 || abs(ar[a].xx - ar[b].xx) < 1e-7) && coefigual(a, b)){
					if(max(ar[a].yy,ar[a].y) < max(ar[b].y, ar[b].yy)) apaga[a/2]=1;
					else apaga[b/2]=1;
				}
				if(apaga[a/2] || apaga[b/2]) continue;
				ptd intr = interSeg(ar[a], ar[b]);
				if( intr.x == -999. && intr.y == -999.) continue;
				add(3, intr.x, intr.y, a, b);
			}
		}
		sort(e, e+dege, cmp);
		int topo = -1;
		ptd p;
		for(int a = 0 ;a < dege; a++){
			//printf("meu topo %d tipo %d pos %f %f entre arestas %d %d\n", topo, e[a].t, e[a].x, e[a].y, e[a].i, e[a].j); 
			if(apaga[e[a].i/2] || (e[a].t == 3 && apaga[e[a].j/2])){
				continue; // ignora o triangulo
			}
			if(topo == -1){
				if(e[a].t == 0){
					topo = e[a].i;
					p.x = e[a].x;
					p.y = e[a].y;
				}

			}
			else{
				if(e[a].t == 1){
					if(e[a].i == topo){
						res += dist(p.x, p.y, e[a].x, e[a].y);
						topo = e[a].j;
						p.x = e[a].x;
						p.y = e[a].y;
					}
				}
				else if(e[a].t == 2){
					if(e[a].i == topo){
						topo = -1;
						res += dist(p.x, p.y, e[a].x, e[a].y);
					}
				}
				else if(e[a].t == 3){
					if((e[a].i/2) == (e[a].j/2)) continue;
					if(e[a].j == topo)
						swap(e[a].i, e[a].j);
					if(e[a].i == topo && coefcmp(e[a].i, e[a].j)){
						res += dist(p.x, p.y, e[a].x, e[a].y);
						topo = e[a].j;
						p.x = e[a].x;
						p.y = e[a].y;
					}
				}
			}
		}
		printf("Case %d: %lld\n\n", ++t, (ll)(res+0.5));
	}
	return 0;
}
