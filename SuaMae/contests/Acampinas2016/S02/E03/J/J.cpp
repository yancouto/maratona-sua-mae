#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<double, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 50;

int hpm, hpe, pp, tt, A, ng;
pii P[N][N];
int VP[N], vp[N*N];
double p[N*N], d[N*N], pot[4*N*N][7], fat[7];
double prob[N*N][7], memo[110][110][2], pen;

void Initialize() {
	int i, j;
	for(i = 0; i < N * N; i++) pot[i][0] = 1;
	for(i = 0; i < 4 * N * N; i++)
		for(j = 1; j <= 5; j++)
			pot[i][j] = pot[i][j-1] * ((i&1)? (1 - p[i/2]) : p[i/2]);
	fat[0] = 1;
	for(i = 1; i <= 5; i++)
		fat[i] = fat[i-1] * i;
	for(i = 0; i < 110; i++)
		for(j = 0; j < 110; j++)
			memo[i][j][0] = memo[i][j][1] = -1;
}

double bin(int n, int k) { return (double) fat[n] / ((double)fat[k] * fat[n-k]); }

double solve(int me, int him, int tu) {
	if(me <= 0) return 0.0;
	if(him <= 0) return 1.0;
	double &r = memo[me][him][tu];
	if(r >= -0.5) return r;
	r = 0.0;
	if(!tu) r = solve(me, him, !tu) * (1 - pen) + solve(me - A, him, !tu) * pen;
	else {
		double ans = 0;
		for(int i = 0; i < ng; i++) {
			ans = 0;
			for(int k = 1; k <= vp[i]; k++)
				ans += solve(me, him - k * d[i], !tu) * prob[i][k];
			ans += prob[i][0] * pen * solve(me - A, him, tu);
			ans /= (1 - prob[i][0] * (1 - pen));
			r = max(r, ans);
		}
	}
	return r;
}


int main() {
	freopen("whats.in", "r", stdin);
	freopen("whats.out", "w", stdout);
	int i, j, k;
	scanf("%d %d %d %d", &hpm, &hpe, &tt, &pp);
	for(i = 0; i < tt; i++) {
		scanf("%d",&VP[i]);
		for(j = 0; j < pp; j++) 
			scanf("%lf %d", &P[i][j].fst, &P[i][j].snd), P[i][j].fst /= 100.0;
	}
	scanf("%lf %d", &pen, &A); pen /= 100.;
	for(i = 0; i < tt; i++)
		for(j = 0; j < pp; j++) {
			p[ng] = P[i][j].fst;
			d[ng] = P[i][j].snd;
			vp[ng++] = VP[i];
		}
	Initialize();
	for(i = 0; i < ng; i++) {
		for(k = 0; k <= vp[i]; k++)
			prob[i][k] = (double)pot[2*i][k] * (double)pot[2*i+1][vp[i] - k] * bin(vp[i], k);
	}
	printf("%.20f\n", solve(hpm, hpe, 1));
	return 0;
}
