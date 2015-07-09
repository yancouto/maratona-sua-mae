#include <cstdio>
#include <cstring>
const int MAX = 23;
int n;
int a[MAX][MAX];
int pos[MAX];
int memo[1060009], tempo;
void solve(int bm) {
	if(memo[bm] == tempo) return;
	memo[bm] = tempo;
	int i, j;
	if(__builtin_popcount(bm) == n - 1) {
		for(i = 0; i < n; i++)
			if(!(bm & (1 << i)))
				pos[i] = 1;
		return;
	}
	int b[20] , b_n = 0;
	for(i = 0; i < n; i++)
		if(!(bm & (1 << i))) {
			b[b_n++] = i;
		}
	for(i = 0; i < b_n; i++) {
		int d = 0;
		for(j = 0; j < b_n; j++)
			d += a[b[i]][b[j]];
		if(d > 0)
			solve(bm | (1 << b[i]));
	}
}


int main() {
	int t, i, j;
	scanf("%d", &t);
	tempo = 0;
	while(t--) {
		scanf("%d", &n);
		tempo++;
		memset(pos, 0, sizeof pos);
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%d", &a[i][j]);
		solve(0);
		for(i = 0; i < n; i++)
			if(pos[i])
				break;
		if(i == n) { puts("0"); continue; }
		for(i = 0; i < n; i++)
			if(pos[i]) {
				printf("%d", i + 1);
				break;
			}
		for(i++; i < n; i++)
			if(pos[i])
				printf(" %d", i + 1);
		printf("\n");
	}
}