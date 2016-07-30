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

const int MAXN = 20;
const double INF = DBL_MAX;
const double PI = acos(-1);
const double DEL = 1e-9;

int n, c;

double dp[(1<<17)][20], d[(1<<17)][20];


struct cat{
	double x, y;
	double vx, vy;
	cat(){}
	cat(double xx, double yy, double vvx, double vvy){
		x = xx;
		y = yy;
		vx = vvx;
		vy = vvy;
	}
} s[MAXN];

double sq(double x){
	return x*x;
}

double solve(double xo, double yo, double xp, double yp, double vx, double vy){
//	printf(" %.2f %.2f %.2f %.2f %.2f %.2f\n", xo, yo, xp, yp, vx, vy);
	double a = xp - xo;
	double b = yp - yo;
//	printf("a %.2f b %.2f\n", a, b);

	double A = (sq(vx) + sq(vy) - sq(c));
	double B = (2*vx*a + 2*vy*b);
	double C = sq(a) + sq(b);
//	printf("A %.2f B %.2f C %.2f\n", A, B, C);
	if(A  < DEL && A > -DEL)
		return -C/B;

	double del = sq(B) - 4*A*C;
	double r1 = (-B - sqrt(del))/(2*A);
	double r2 = (-B + sqrt(del))/(2*A);
//	printf("r1 %.2f r2 %.2f \n", r1, r2);


	if(r1 >= 0.)
		return r1;
	return r2;
}

struct pd{
	int bm, u;
	pd(int ii, int uu){
		bm = ii;
		u = uu;
	}
	pd(){}
};

int main (){

	while(scanf("%d%d", &n, &c) != EOF && n+c){
		for(int a=0;a<=(1<<(n+1));a++){
			for(int b=0;b<=n;b++){
				dp[a][b] = INF;
			}
		}
		for(int a=1;a<=n;a++){
			double x, y, d, m;
			scanf("%lf%lf%lf%lf", &x, &y, &d, &m);
			d = d*2.*PI/360.;
			s[a] = cat(x, y, cos(d)*m, sin(d)*m);
		}
		s[0] = cat(0, 0, 0, 0);
		queue<pd> q;
		q.push(pd(1, 0));
		dp[1][0] = 0;
		double ans = INF;
		while(!q.empty()){
			pd at = q.front();
			q.pop();
			double t = dp[at.bm][at.u];
			//printf("dp[%d][%d] %.2f\n", at.bm, at.u, t); 
			if(at.bm == (1<<(n+1)) - 1)
				ans = min(ans, t);
			for(int a=1;a<=n;a++){
				if((1<<a)&at.bm)
					continue;
				int nbm = (at.bm|(1<<a));
				int u = at.u;
				//printf("prox dp[%d][%d] %.2f\n", nbm, a, dp[nbm][a]); 
				if(INF - dp[nbm][a] < DEL && INF - dp[nbm][a] > -DEL)
					q.push(pd(nbm, a));
				dp[nbm][a] = min(dp[nbm][a], t + solve(s[u].x + s[u].vx*t, s[u].y + s[u].vy*t, s[a].x + s[a].vx*t, s[a].y + s[a].vy*t, s[a].vx, s[a].vy));
			}
		}
		printf("%.2f\n", ans);
	}
}
