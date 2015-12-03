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

#include <cmath>
#define temp template<typename num>
#define ptn point<num>
temp struct point {
	num x, y;
	ptn() {}
	ptn(num a, num b) : x(a), y(b) {}
	ptn operator + (ptn o) const { return ptn(x + o.x, y + o.y); }
	ptn operator - (ptn o) const { return ptn(x - o.x, y - o.y); }
	num operator * (ptn o) const { return x * o.x + y * o.y; }
	num operator ^ (ptn o) const { return x * o.y - y * o.x; }
	ptn operator * (num i) const { return ptn(x * i, y * i); }
	ptn operator / (num i) const { return ptn(x / i, y / i); }
	point<double> rotate(double deg) {
		double cs = cos(deg), sn = sin(deg);
		return point<double>(x*cs - y*sn, x*sn + y*cs);
	}
	num distSqr(ptn o) const { return (*this - o) * (*this - o); }
	bool operator< (ptn o) const { return x < o.x || (x == o.x && y < o.y); }
};
temp inline num cross(ptn a, ptn b, ptn c) { return (c - a) ^ (b - a); }
temp inline bool betweenSeg(ptn a, ptn b, ptn c) { return cross(a, b, c) == 0 && ((b - c) * (a - c) <= 0); }
temp double distSegSqr(ptn a, ptn b, ptn c) {
	if((b - a) * (c - b) > 0) return b.distSqr(c);
	if((a - b) * (c - a) > 0) return a.distSqr(c);
	double d = (b - a) ^ (c - a);
	return d * d / ((b - a) * (b - a));
}
temp bool intersectSeg(ptn a, ptn b, ptn c, ptn d) {
	if(betweenSeg(a, b, c) || betweenSeg(a, b, d) || betweenSeg(c, d, a) || betweenSeg(c, d, b)) return true;
	if(((cross(a, b, c) > 0) ^ (cross(a, b, d) > 0)) && ((cross(c, d, a) > 0) ^ (cross(c, d, b) > 0))) return true;
	return false;
}

temp struct line {
	num a, b, c;
	line() {}
	line(num aa, num bb, num cc) : a(aa), b(bb), c(cc) {}
	line(ptn s, ptn e) : a(e.y - s.y), b(s.x - e.x), c(a*s.x + b*s.y) {}
	line pass(ptn p) { return line(a, b, a*p.x + b*p.y); }
	bool parallel(const line &o) const { return a * o.b - o.a * b == 0; }
	point<double> inter(line o) {
		double d = a * o.b - o.a * b;
		if(d == 0) return point<double>(0, 0); //fudeu
		return point<double>((o.b * c - b * o.c)/d, (a * o.c - o.a * c)/d);
	}
};
typedef point<int> pti;
typedef point<double> ptd;
typedef line<int> lni;
typedef line<double> lnd;

const int MAXN = 2010;

int n, res;
int mrk[MAXN], up[MAXN], degu, lo[MAXN], degl;
pti c[MAXN];

bool cmp(pti a,pti b){
	return (a.x<b.x || (a.x==b.x && a.y<b.y));
}

int prod(pti a,pti b){
	return (a^b);
}

int main (){
	while(scanf("%d", &n) && n!=0){
		res=0;
		memset(mrk,0,sizeof(mrk));
		for(int a=0;a<n;a++)
			scanf("%d %d", &c[a].x, &c[a].y);
		sort(c,c+n,cmp);
		while(1){
			degu=0;
			for(int a=0;a<n;a++){
				if(mrk[a]==1) continue;
				if(degu <= 1){
					up[degu]=a;
					degu++;
					//printf("up coloquei %d %d\n", c[up[degu-1]].x, c[up[degu-1]].y);
				}
				else{
					while(degu>=2 && prod((c[up[degu-2]] - c[up[degu-1]]), (c[a] - c[up[degu-1]])) < 0){
						//printf("up retirei %d %d\n", c[up[degu-1]].x, c[up[degu-1]].y);
						degu--;
					}
					up[degu++]=a;
					//printf("up coloquei %d %d\n", c[up[degu-1]].x, c[up[degu-1]].y);
				}
			}
			if(degu==0) break;
			degl=0;
			for(int a=n-1;a>=0;a--){
				if(mrk[a]==1) continue;
				if(degl <= 1){
					lo[degl++]=a;
					//printf("lo coloquei %d %d\n", c[lo[degl-1]].x, c[lo[degl-1]].y);
				}
				else{
					while(degl>=2 && prod((c[lo[degl-2]] - c[lo[degl-1]]), (c[a] - c[lo[degl-1]])) < 0){
						//printf("lo retirei %d %d, prod deu %d\n", c[lo[degl-1]].x, c[lo[degl-1]].y, prod((c[lo[degl-2]] - c[lo[degl-1]]), (c[a] - c[lo[degl-1]])));
						degl--;
					}
					lo[degl++]=a;
					//printf("lo coloquei %d %d\n", c[lo[degl-1]].x, c[lo[degl-1]].y);
				}
			}
			if(degl==0) break;
			if(degu == degl){
				int dif = 0;
				for(int a=0;a<degu;a++){
					if(up[a] != lo[degl-a-1]){
						dif = 1;
						break;
					}
				}
				if(dif == 0){
					break;
				}
			}
			for(int a=0;a<degu;a++){
				//printf("up %d - %d %d\n", up[a], c[up[a]].x, c[up[a]].y);
				if(mrk[up[a]]==0)
					mrk[up[a]] = 1;
			}

			for(int a=0;a<degl;a++){
				//printf("lo %d - %d %d\n", lo[a], c[lo[a]].x, c[lo[a]].y);
				if(mrk[lo[a]]==0)
					mrk[lo[a]] = 1;
			}
			res++;
		}
		//printf("%d\n", res);
		if(res%2)
			printf("Take this onion to the lab!\n");
		else
			printf("Do not take this onion to the lab!\n");
	}
	return 0;
}