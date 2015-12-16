
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ull;
typedef double ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }

const int MAXN = 1010;

const ll INF = 1/0.;

int n;
ull w;

ll dp[MAXN][2];

struct vert{
	long long x, y;
} s[MAXN];

ull distl(int i, int j) {
	if(i < j) swap(i, j);
	if(j == 0)
		return (s[i].x)*(s[i].x);
	if(i == n+1)
		return (w - s[j].x)*(w - s[j].x);
	return ((s[i].x - s[j].x)*(s[i].x - s[j].x) + (s[i].y - s[j].y)*(s[i].y - s[j].y));
}

ll dist(int i,int j){
	return distl(i, j);
}

ll solve(int i,int p){
	ll &r = dp[i][p];
	if(r != INF) return r;
	if(i==0) return 0;
	for(int a=i-1;a>=0;a--){
		r = min(r,max(solve(a,p),dist(i,a)));
		if(p)
			r = min(r ,max(solve(a, 0),dist(i,a)/4.));
	}
	return r;
}

void build(int i, int p){
	for(int a=i-1;a>=0;a--){
		if(p==1 && fabs(solve(i, p) - max(solve(a, 0),dist(i,a)/4.)) < 1e-6){
		}
		if(fabs(solve(i,p) - max(solve(a,p),dist(i,a))) < 1e-6){
			build(a,p);
		}
	}
}

int seen[MAXN][2];
pii pos[MAXN][2];
void dij() {
	ll dist[MAXN][2];
	for(int i = 0; i < MAXN; i++) dist[i][0] = dist[i][1] = INF;
	dist[0][1] = 0;
	while(true) {
		int i, bi = -1, bj, j;
		for(i = 0; i <= n+1; i++)
			for(j = 0; j < 2; j++)
				if(!seen[i][j] && (bi == -1 || dist[i][j] < dist[bi][bj]))
					bi = i, bj = j;
		seen[bi][bj] = 1;
		if(bi == n + 1) {
			if(bj == 1) {
				puts("0.5 0.5");
				exit(0);
			}
			int a = pos[bi][bj].fst; i = pos[bi][bj].snd;
			if(a > i) swap(a, i);
			if(a == 0)
				printf("%.5f %.5f\n", s[i].x/2., double(s[i].y));
			else if(i==n+1)
				printf("%.5f %.5f\n", (s[a].x + w)/2., double(s[a].y));
			else
				printf("%.5f %.5f\n", (s[i].x + s[a].x)/2., (s[i].y + s[a].y)/2.); 
			exit(0);
		}
		for(i = 0; i <= n+1; i++)
			for(j = 0; j <= bj; j++)
				if(!seen[i][j]) {
					if(j < bj) {
						if(max(dist[bi][bj], ::dist(i, bi) / 4.) < dist[i][j])
							pos[i][j] = pii(bi, i);
						dist[i][j] = min(dist[i][j], max(dist[bi][bj], ::dist(i, bi) / 4.));
					}
					else {
						if(max(dist[bi][bj], ::dist(i, bi)) < dist[i][j])
							pos[i][j] = pos[bi][bj];
						dist[i][j] = min(dist[i][j], max(dist[bi][bj], ::dist(i, bi)));
					}
				}
	}
}

int main (){
	freopen("froggy.in", "r", stdin);
	freopen("froggy.out", "w", stdout);
	scanf("%I64d%d", &w, &n);
	for(int a=1;a<=n;a++){
		scanf("%I64d%I64d", &s[a].x, &s[a].y);
	}
	s[0].x = 0;
	s[0].y = 0;
	s[n+1].x = w;
	s[n+1].y = 0;
	dij();
}
