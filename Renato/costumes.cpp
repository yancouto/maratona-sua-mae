#include <cstdio>
#include <algorithm>
#include <cstring>

int mem[105][105];
int c[105];

int sol(int s, int e) {
	if (s==e) return 0;
	if (mem[s][e] != -1) return mem[s][e];
	int m = 1e7;
	for (int i=s+1;i<=e;++i) {
		if (c[i]==c[s]) {
			int right = sol(i, e);
			int left = 1+sol(s+1, i-1);
			m = std::min(m, left+right);
		}
	}
	m = std::min(m, 1+sol(s+1, e));
	mem[s][e] = m;
	return m;
}

int main() {
	int t;
	
	scanf("%d", &t);

	for (int k=0;k<t;++k) {
		int n, m;
		scanf("%d %d", &n, &m);
		scanf("%d", &c[0]);
		for (int i=1;i<n;++i) {
			int k;
			scanf("%d", &k);
			if (k != c[i-1])
				c[i] = k;
			else {
				--n;
				--i;
			}
		}

		memset(mem, -1, sizeof(mem));
	
		printf("Case %d: %d\n", k+1, sol(0, n-1)+1);
	}	
	
	return 0;
}
