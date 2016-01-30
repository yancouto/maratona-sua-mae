#include <stdio.h>
typedef unsigned long long ull;
#define N 200000
#define M 3125
#define SQ 500
#define Q 400

ull pre[3][SQ][M];
int a[3][N], p[3][N];
ull o[3][M];

int c = 0;
char f[3900009];

int main() {
	int i, j, sq, n = 0, k;
	fread(f, 1, sizeof f, stdin);
	while(f[c] < '0' || f[c] > '9') c++;
	while(f[c] >= '0' && f[c] <= '9') n = ((n << 3) + (n << 1)) + f[c++] - '0';
	for(j = 0; j < 3; j++)
		for(i = 0; i < n; i++) {
			while(f[c] < '0' || f[c] > '9') c++;
			while(f[c] >= '0' && f[c] <= '9') a[j][i] = ((a[j][i] << 3) + (a[j][i] << 1)) + f[c++] - '0';
			p[j][--a[j][i]] = i;
		}
	for(j = 0; j < 3; j++)
		for(sq = 0; sq < SQ; sq++)
			for(i = 0; i < (sq + 1) * Q; i++)
				pre[j][sq][a[j][i] >> 6] |= (1ull << (a[j][i] & 63));
	ull tot = 0;
	for(i = 0; i < n; i++) {
		for(j = 0; j < 3; j++) {
			const int pos = p[j][i];
			if(pos / Q) for(k = 0; k < M; k++) o[j][k] = pre[j][(pos / Q) - 1][k];
			else for(k = 0; k < M; k++) o[j][k] = 0ull;
			for(k = Q * (pos / Q); k < pos; k++)
				o[j][a[j][k] >> 6] |= (1ull << (a[j][k] & 63));
		}
		for(k = 0; k < M; k++)
			tot += __builtin_popcountll(o[0][k] & o[1][k] & o[2][k]);
	}
	printf("%llu\n", tot);
}
