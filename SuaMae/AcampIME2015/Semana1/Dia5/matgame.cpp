#include <cstdio>
int M[55][55];
int main() {
	 int t, i, j;
	 scanf("%d", &t);
	 while(t--) {
	 	int n, m;
	 	scanf("%d %d", &n, &m);
	 	for(i = 0; i < n; i++)
	 		for(j = 0; j < m; j++) {
	 			scanf("%d", &M[i][j]);
	 			if(j != m - 1)
	 				M[i][j]--;
	 		}
	 	for(i = 0; i < n; i++)
	 		for(j = m - 2; j >= 0; j--)
	 			if(M[i][j] >= M[i][j + 1])
	 				M[i][j]++;
	 	for(i = 1; i < n; i++)
	 		M[0][0] ^= M[i][0];
	 	if(M[0][0]) puts("FIRST");
	 	else puts("SECOND");
	 }
	 return 0;
}