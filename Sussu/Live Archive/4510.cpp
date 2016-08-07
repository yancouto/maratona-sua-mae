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

const int MAXN = 1123;

const double INF = 500010., EPS = 1e-9;

int n;

double dp[MAXN][2];

struct pti{
	double x, y;
	pti(double xx, double yy){
		x = xx;
		y = yy;
	}
	pti(){
		x = 0.;
		y = 0.;
	}

	pti operator - (pti o){ return pti(x - o.x, y - o.y); }
	bool operator < (const pti o) const { return (x < o.x); }
	//bool operator > (pti o){ return (x > o.x); }
	//bool operator == (pti o){ return (x - o.x < EPS && x - o.x > -EPS); }
	//bool operator >= (pti o) { return (this > o || this == o); }
	//bool operator <= (pti o) { return (this < o || this == o); }

	double dist(pti o){
		return sqrt((x - o.x)*(x - o.x) + (y - o.y)*(y - o.y));
	}
} s[MAXN][2];

void printp(pti a){
	//printf("%f %f\n", a.x, a.y);
}

double cross(pti a, pti b, pti o){
	pti v1 = a - o;
	pti v2 = b - o;
	//printf("cross entre \n");
	printp(a);
	printp(b);
	printp(o);
	//printf("deu %f\n\n", (v1.x * v2.y - v1.y * v2.x)); 
	return (v1.x * v2.y - v1.y * v2.x);
}

pti its(pti a, pti b, double y){
	return pti(a.x + (a.y - y)*(b.x - a.x)/(a.y - b.y), y);
}

double distseg(pti o, pti l, pti r){
	if(o.x >= l.x && o.x <= r.x)
		return (o.y - l.y);
	else
		return min(o.dist(l), o.dist(r));
}

double go(){
	for(int a=0;a<=n;a++){
		for(int b=0;b<2;b++){
			dp[a][b] = INF;
		}
	}
	dp[0][0] = 0;
	for(int i = 0;i < n;i++){
		for(int p = 0;p < 2;p++){
			if(i == 0 && p == 1) continue;

			int pod = 1;
			pti l=s[i][p], r=s[i][p];
			double d = dp[i][p];

			for(int j = i + 1;j < n;j++){
				if(cross(l, s[j][0], s[i][p]) >= -EPS){
					l = s[j][0];
					if(cross(r, s[j][0], s[i][p]) <= EPS)
						dp[j][0] = min(dp[j][0], d + s[i][p].dist(s[j][0]));
					else{
						pod = 0;
						break;
					}
				}
				if(cross(r, s[j][1], s[i][p]) <= EPS){
					r = s[j][1];
					if(cross(l, s[j][1], s[i][p]) >= -EPS)
						dp[j][1] = min(dp[j][1], d + s[i][p].dist(s[j][1]));
					else{
						pod = 0;
						break;
					}
				}
			}
			if(!pod)
				continue;

			if(cross(l, s[n][0], s[i][p]) >= -EPS)
				l = s[n][0];
			if(cross(r, s[n][1], s[i][p]) <= EPS)
				r = s[n][1];
			pti L = max(s[n][0], its(s[i][p], l, s[n][0].y));	
			pti R = min(s[n][1], its(s[i][p], r, s[n][0].y));
			if( L.x > R.x ) continue;
			dp[n][0] = min(dp[n][0], d + distseg(s[i][p], L, R));
		}
	}
	return min(dp[n][0], dp[n][1]);
}

int main (){
	while(scanf("%d", &n)!=EOF && n){
		scanf("%lf %lf", &s[0][0].x, &s[0][0].y);
		double l = -INF, r = INF;
		for(int a=1;a<=n;a++){
			double y;
			scanf("%lf %lf %lf", &y, &s[a][0].x, &s[a][1].x);
			s[a][0].y = s[a][1].y = y;
			l = max(l, s[a][0].x);
			r = min(r, s[a][1].x);
		}
		if(s[0][0].x >= l && s[0][0].x <= r){
			printf("%.15f\n", -s[n][0].y + s[0][0].y);
			continue;
		}
		printf("%.15f\n", go());
	}
}
