#include <bits/stdc++.h>
#define debug(args...) //fprintf(stderr, args)
#define gc getchar_unlocked
using namespace std;

#define double float

const int MAXN = 600;

const double eps = 1e-9;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

inline int cmp(double x, double y = 0, double tol = eps) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
struct point {
	double x, y;
	point(double x = 0, double y = 0): x(x), y(y) {}
	point operator +(point q) { return point(x + q.x, y + q.y); }
	point operator -(point q) { return point(x - q.x, y - q.y); }
	point operator *(double t) { return point(x * t, y * t); }
	point operator /(double t) { return point(x / t, y / t); }
	double operator *(point q) {return x * q.x + y * q.y;}//a*b = |a||b|cos(ang)
	double operator %(point q) {return x * q.y - y * q.x;}//a%b = |a||b|sin(ang)
	double mod() { return sqrt(x * x + y * y); }
	double mod2() { return (x * x + y * y); }
	point rotate(double t) {return point(x*cos(t)-y*sin(t), x*sin(t)+y*cos(t));}
	int cmp(point q) const {
		if (int t = ::cmp(x, q.x)) return t;
			return ::cmp(y, q.y);
	}
	bool operator ==(point q) const { return cmp(q) == 0; }
	bool operator !=(point q) const { return cmp(q) != 0; }
	bool operator < (point q) const { return cmp(q) < 0; }
	static point pivot;
};

inline double seg_distance(point p, point q, point r) {
	point A = r - q, B = r - p, C = q - p;
	double a = A * A, b = B * B, c = C * C;
	if (cmp(b, a + c) >= 0) return sqrt(a);
	else if (cmp(a, b + c) >= 0) return sqrt(b);
	else return fabs(A % B) / sqrt(c);
}

double rad[MAXN][MAXN];

int t[MAXN][MAXN], tt;

inline void check(int x, int y){
	if(t[x][y] != tt){
		t[x][y] = tt;
		rad[x][y] = -1;
	}
}

int main() {
	int n;
	tt = 1;
	while(scanf("%d", &n) != EOF) {
		tt++;
		for(int i = 0; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			x += 50; y += 50;
			scanf("%f", &rad[x][y]);
			t[x][y] = tt;
		}
		int q;
		scanf("%d", &q);
		for(int i = 0; i < q; i++) {
			int ans = 0;
			int x1, y1, x2, y2;
			scanint(x1); scanint(y1); scanint(x2); scanint(y2);
			x1 += 50; y1 += 50; x2 += 50; y2 += 50;
			if(abs(x2 - x1) > abs(y2 - y1)) {
				if(x1 > x2) { swap(x1, x2); swap(y1, y2); }
				for(int x = x1; x <= x2; x++) {
					double y = double((y2 - y1)*(x - x1))/(x2 - x1) + y1;
					int yl = int(floor(y));
					int yh = int(ceil(y));
					if(yl == yh) yl--, yh++;
					int idx = 0;
					do {
						check(x, yl);
						if(rad[x][yl] != -1) {
							if(cmp(seg_distance(point(x1, y1), point(x2, y2), point(x, yl)), rad[x][yl]) <= 0) {
								debug("BATEU CIRCULO %d %d\n", x, yl);
								ans++;
							}
						}
						check(x, yh);
						if(rad[x][yh] != -1) {
							if(cmp(seg_distance(point(x1, y1), point(x2, y2), point(x, yh)), rad[x][yh]) <= 0) {
								debug("BATEU CIRCULO %d %d\n", x, yh);
								ans++;
							}
						}
						yl--; yh++;
					} while(idx--);
					check(x, int(y));
					if(int(ceil(y)) == int(floor(y)) && rad[x][int(y)] != -1) {
						debug("BATEU CIRCULO %d %d\n", x, int(y));
						ans++;
					}
				}
			} else {
				if(y1 > y2) { swap(x1, x2); swap(y1, y2); }
				debug("%d -> %d", y1, y2);
				for(int y = y1; y <= y2; y++) {
					//debug("%d\n", y);
					double x = double((x2 - x1)*(y - y1))/(y2 - y1) + x1;
					int xl = int(floor(x));
					int xh = int(ceil(x));
					if(xl == xh) xl--, xh++;
					int idx = 0;
					do {
						check(xl, y);
						if(rad[xl][y] != -1) {
							if(cmp(seg_distance(point(x1, y1), point(x2, y2), point(xl, y)), rad[xl][y]) <= 0) {
								debug("BATEU CIRCULO %d %d\n", xl, y);
								ans++;
							}
						}
						check(xh, y);
						if(rad[xh][y] != -1) {
							if(cmp(seg_distance(point(x1, y1), point(x2, y2), point(xh, y)), rad[xh][y]) <= 0) {
								debug("BATEU CIRCULO %d %d\n", xh, y);
								ans++;
							}
						}
						xl--; xh++;
					} while(idx--);
					check(int(x), y);
					if(int(ceil(x)) == int(floor(x)) && rad[int(x)][y] != -1){
						debug("BATEU CIRCULO %d %d\n", int(x), y);
						ans++;
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
