#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 1000;
const int oo = 10000000;

pii joe;
int best[N][N], fire[N][N];
int R, C, D = 4;
char tb[N][N];

int dx[4] = {0, 0, 1,-1};  
int dy[4] = {1,-1, 0, 0};

bool isIn(int x, int y) { return x >= 0 && x < R && y >= 0 && y < C; }

void prec() {
	deque<pii> dq;
	int i, j;
	for(i = 0; i < R; i++)
		for(j = 0; j < C; j++)
			if(tb[i][j] == 'F')
				dq.pb(pii(i, j)), fire[i][j] = 0;
	while(!dq.empty()) {
		pii v = dq.front();
		dq.pop_front();
		for(i = 0; i < D; i++) {
			int nx = v.x + dx[i], ny = v.y + dy[i];
			if(isIn(nx, ny) && fire[v.x][v.y] + 1 < fire[nx][ny] && tb[nx][ny] != '#')
				fire[nx][ny] = fire[v.x][v.y] + 1, dq.pb(pii(nx, ny));
		}
	}
}

int solve() {
	int i, j;
	deque<pii> dq;
	dq.pb(joe); best[joe.x][joe.y] = 0;
	int ans = oo;
	int cc = 0;
	while(!dq.empty()) {
		cc++;
		pii v = dq.front();
		dq.pop_front();
		if(v.x == 0 || v.x == R - 1 || v.y == 0 || v.y == C - 1) 
			ans = min(ans, best[v.x][v.y] + 1);
		for(i = 0; i < D; i++) {
			int nx = v.x + dx[i], ny = v.y + dy[i];
			if(isIn(nx, ny) && tb[nx][ny] != '#' && best[v.x][v.y] + 1 < fire[nx][ny] && best[v.x][v.y] + 1 < best[nx][ny]) 
				best[nx][ny] = best[v.x][v.y] + 1, dq.pb(pii(nx, ny));
		}
	}
	return ans;
}

int main() {
	int i, j;
	memset(best, -1, sizeof best);
	memset(fire, -1, sizeof fire);
	scanf("%d %d", &R, &C);
	for(i = 0; i < R; i++)
		for(j = 0; j < C; j++) {
			scanf(" %c", &tb[i][j]);
			if(tb[i][j] == 'J') joe = pii(i, j);
			fire[i][j] = best[i][j] = oo;
		}
	prec();
	int ans = solve();
	if(ans == oo) puts("IMPOSSIBLE");
	else printf("%d\n", ans);	
	return 0;	
}
