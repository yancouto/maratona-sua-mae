#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int mat[1003][1003];
int acc[1003][1003];
int ans = 0;
bool check(int k) {
	for (int i = 0; i < n; i++) {
		if (i + k > n) break;
		for (int j = 0; j < m; j++) {
			if (j + k > m) break;
			int i2, j2;
			i2 = i + k - 1;
			j2 = j + k - 1;
			int z;
			if (i > 0 && j > 0)
				z = acc[i2][j2] - acc[i2][j-1] - (acc[i-1][j2]-acc[i-1][j]);
			else if (i > 0)
				z = acc[i2][j2] - acc[i-1][j2];
			else if (j > 0)
				z = acc[i2][j2] - acc[i2][j-1];
			else
				z = acc[i2][j2];
			if (!z)
				return true;
		}
	}
	return false;
}

int s(int i, int j) {
	if (i >= j) {
		if (check(i))
			ans = max(ans,i);
		if (check(j))
			ans = max(ans, j);
		return ans;
	}
	//printf("State(%d,%d)\n", i, j);
	int mid = (i + j)/2;
	//printf("mid=%d check()=%d\n", mid, check(mid));
	if (check(mid)) {
	//	printf("ashuuhashusauhas\n");
		ans = max(ans, mid);
		if (mid == 0) mid = j;
		return s(mid+1, j);
	}
	
	if (mid == 0) mid = i;
	return s(i, mid);
	
}

int main () {
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &mat[i][j]);

		//memset(acc, 0, sizeof(acc));
		acc[0][0] = (mat[0][0]==0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (i == 0 && j == 0) continue;
				if (i > 0 && j > 0)
					acc[i][j] = acc[i][j-1] + (acc[i-1][j] - acc[i-1][j-1]) + (mat[i][j] == 0);
				else if (i > 0)
					acc[i][j] = acc[i-1][j] + (mat[i][j] == 0);
				else if (j > 0)
					acc[i][j] = acc[i][j-1] + (mat[i][j] == 0);
			}
		//printf("ch %d %d %d\n", check(0), check(1), check(2));
		ans = 0;
		int a = s(1, min(n, m));
		printf("%d\n", ans);
	}
	return 0;
}