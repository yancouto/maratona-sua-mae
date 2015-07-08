#include <cstdio>
#include <algorithm>
using namespace std;

int fun[1009];
int dizzy[1009];
int memo[2][300009];
int main() {
	int n, k, l, i, j;
	while(true) {
		scanf("%d %d %d", &n, &k, &l);
		if(!n) return 0;
		for(i = 0; i < n; i++)
			scanf("%d %d", &fun[i], &dizzy[i]);
		for(j = 0; j <= l; j++)
			memo[n%2][j] = 0;
		for(i = n - 1; i >= 0; i--)
			for(j = 0; j <= l; j++) {
				int &m = memo[i%2][j];
				m = memo[(i+1)%2][max(j - k, 0)];
				if(j + dizzy[i] <= l)
					m = max(m, fun[i] + memo[(i+1)%2][j+dizzy[i]]);
			}
		printf("%d\n", memo[0][0]);
	}

}