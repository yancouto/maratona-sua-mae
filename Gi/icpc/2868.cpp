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
		if (i+k-1 > n) break;
		for (int j=1; j <= m; j++) {
			//if (k==3&&i==2) printf("i=%d-j=%d\n",i,j);
			if (j+k-1 > m) break;
			int i2, j2;
			i2=i+k-1;
			j2=j+k-1;
			//if (k==3&&i==2) printf("%d %d\n", i2, j2);
			int uns=acc[i2][j2]-acc[i2][j-1]-(acc[i-1][j2]-acc[i-1][j-1]);
			if(uns==k*k) return true;
		}
	}
	return false;
}

int s(int i, int j) {
	if (i>=j) return check(i)?(ans=max(ans, i)):ans;
	int mid=(i+j)/2;
	if(check(mid)) {
		ans=max(ans, mid);
		return s(mid+1, j);
	}
	return s(i, mid);
}

int main() {
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &mat[i][j]);
		for(int i=0; i<=n; i++)
			mat[i][0]=0;
		for(int j=0; j<=m; j++)
			mat[0][j]=0;
		acc[0][0] = (mat[0][0]==1);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++) 
				acc[i][j]=acc[i][j-1]+(acc[i-1][j]-acc[i-1][j-1])+(mat[i][j]==1);
		/*for (int i=0; i<=n; i++) {
			for (int j=0; j<=m; j++) 
				printf("%d ", acc[i][j]);
			printf("\n");
		}*/
		ans=0;		
		int a = s(0, min(n, m));
		printf("%d\n", ans);
	}
	return 0;
}
