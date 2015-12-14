#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int mat[1003][1003];
int acc[1003][1003];
int ans;

bool check(int k) {
	for (int i=1; i <= n; i++) {
		if (i+k-1 >= n) break;
		for (int j=1; j <= m; j++) {
			if (j+k-1 >= m) break;
			int i2, j2;
			i2=i+k-1;
			j2=j+k-1;
			int z=acc[i2][j2]-acc[i2][j-1]-(acc[i-1][j2]-acc[i-1][j]);
			if(!z) return true;
		}
	}
	return false;
}

int s(int i, int j) {
	if (i>=j) return check(i)?(ans=max(ans, i)):ans;
	int mid=(i+j)/2;
	if(check(mid)) {
		ans=max(ans, mid);
		return solve(mid+1, j);
	}
	return solve(i, mid);
}

int main () {
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &mat[i][j]);
		
		acc[0][0] = (mat[0][0]==0);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++) 
				acc[i][j]=acc[i][j-1]+(acc[i-1][j]-acc[i-1][j-1])+(mat[i][j]==0);
		ans=0;		
		int a = s(0, min(n, m));
		printf("%d\n", ans);
	}
	return 0;
}
