#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 210, MAXM = 2*MAXN*MAXN;

int f[MAXN][MAXM], mrk[MAXN][MAXM];

int main() {
	int n, m;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &f[i][1]);
	for(int i = 1; i <= n; i++)	
		for(int j = 2; j <= 2*n*n; j++)
				f[i][j] = f[f[i][j-1]][1];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n*n; j++) {
			if(f[i][j] == f[i][2*j]) {
				mrk[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n*n; i++) {
		bool valid = true;
		for(int j = 1; j <= n; j++) {
			if(!mrk[j][i]) valid = false;
		}
		if(valid) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}