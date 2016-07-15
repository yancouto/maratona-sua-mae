#include <bits/stdc++.h>
#define mp make_pair
#define debug(args...) //fprintf(stderr, args)
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 10, INF = 1e7;

pii d1, d2, o1, o2;

int dp[MAXN][MAXN][MAXN][MAXN];
int dx[] = {-1, 1, 2, -2, 2, -2, -1, 1};
int dy[] = {2, 2, 1, 1, -1, -1, -2, -2};

int f(int x1, int y1, int x2, int y2) {
	if(x1 == x2 && y1 == y2) return INF;
	if(x1 == d1.ff && x2 == d2.ff && y1 == d1.ss && y2 == d2.ss) return 0;
	int &ret = dp[x1][y1][x2][y2];
	if(ret == -1) {
		ret = INF;
		for(int i = 0; i < 8; i++) {
			int nx = x1 + dx[i];
			int ny = y1 + dy[i];
			if(nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8)
				ret = min(ret, 1 + f(nx, ny, x2, y2));
		}
		for(int i = 0; i < 8; i++) {
			int nx = x2 + dx[i];
			int ny = y2 + dy[i];
			if(nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8)
				ret = min(ret, 1 + f(x1, y1, nx, ny));
		}
	}
	return ret;
}

pii read() {
	int y;
	char ch;
	scanf(" %c%d", &ch, &y);
	return {ch - 'a' + 1, y};
}

int main() {
	memset(dp, -1, sizeof dp);
	o1 = read();
	o2 = read();
	d1 = read();
	d2 = read();
	int ans = f(o1.ff, o1.ss, o2.ff, o2.ss);
	if(ans >= INF) {
		printf("-1\n");
		return 0; 
	}	
	printf("%d\n", ans);
	int x1 = o1.ff, y1 = o1.ss, x2 = o2.ff, y2 = o2.ss;
	while(x1 != d1.ff || x2 != d2.ff || y1 != d1.ss || y2 != d2.ss) {
		for(int i = 0; i < 8; i++) {
			int nx = x1 + dx[i];
			int ny = y1 + dy[i];
			if(nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8)
				if(f(x1, y1, x2, y2) == 1 + f(nx, ny, x2, y2)) {
					printf("W %c%d\n", nx - 1 + 'a', ny);
					x1 = nx;
					y1 = ny;
					goto next;
				}
		}
		for(int i = 0; i < 8; i++) {
			int nx = x2 + dx[i];
			int ny = y2 + dy[i];
			if(nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8) {
				if(f(x1, y1, x2, y2) == 1 + f(x1, y1, nx, ny)) {
					printf("B %c%d\n", nx - 1 + 'a', ny);
					x2 = nx;
					y2 = ny;
					goto next;
				}
			}
		}
		next:;
		
	}	
	return 0;
}
