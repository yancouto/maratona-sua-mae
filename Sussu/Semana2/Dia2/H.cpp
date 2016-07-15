#include <bits/stdc++.h>
#define mp make_pair
#define debug(args...) fprintf(stderr, args)
#define pb push_back
#define ff first
#define ss second
using namespace std;

const int MAXN = 212;

char mat[MAXN][MAXN];
int h[MAXN], hr[MAXN], vis[MAXN][MAXN];
int n, m, t = 0;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void dfs(int i, int j) {
	vis[i][j] = t;
	for(int k = 0; k < 4; k++) {
		int ni = i + dx[k], nj = j + dy[k];
		if(ni >= 0 && ni < n && nj >= 0 && nj < m && mat[ni][nj] == '#' && !vis[ni][nj]) dfs(ni, nj);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			scanf(" %c", &mat[i][j]);
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(mat[i][j] == '#' &&!vis[i][j]) {
				t++;
				dfs(i, j);
			}
	if(t == 2) {
		printf("YES\n");
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(vis[i][j] == 0)
					printf(".");
				else if(vis[i][j] == 1)
					printf("a");
				else
					printf("b");
			}
			printf("\n");
		}
		return 0;
	}
	if(t > 2) {
		printf("NO\n");
		return 0;
	}
	
	int lastI = 0;
	for(int i = 0; i < n; i++) {
		bool onlyDot = true;
		for(int j = 0; j < m; j++) {
			if(mat[i][j] != '.') onlyDot = false;  
		}
		h[i] = 0;
		lastI = i;
		if(!onlyDot) break;
	}
	
	h[lastI] = 1;
	for(int i = lastI + 1; i < n; i++) {
		bool fail = false;
		for(int j = 0; j < m; j++)
			if(mat[i][j] != mat[i - 1][j]) fail = true;
		if(fail) break;
		h[i] = 1;
	}
	
	lastI =  n - 1;
	for(int i = n - 1; i >= 0; i--) {
		bool onlyDot = true;
		for(int j = 0; j < m; j++) {
			if(mat[i][j] != '.') onlyDot = false;  
		}
		hr[i] = 0;
		lastI = i;
		if(!onlyDot) break;
	}
	
	hr[lastI] = 1;
	for(int i = lastI - 1; i >= 0; i--) {
		bool fail = false;
		for(int j = 0; j < m; j++)
			if(mat[i][j] != mat[i + 1][j]) fail = true;
		if(fail) break;
		hr[i] = 1;
	}
	
	for(int i = 0; i < lastI; i++) {
		if(h[i] && hr[i + 1]) {
			printf("YES\n");
			for(int ii = 0; ii <= i; ii++) {
				for(int j = 0; j < m; j++) {
					if(mat[ii][j] == '.') printf(".");
					else printf("a");
				}
				puts("");
			}
			for(int ii = i + 1; ii < n; ii++) {
				for(int j = 0; j < m; j++) {
					if(mat[ii][j] == '.') printf(".");
					else printf("b");
				}
				puts("");
			}
			return 0;
		}
	}
	
	char aux[MAXN][MAXN];
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			aux[j][i] = mat[i][j];
			
	swap(n, m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			mat[i][j] = aux[i][j];

	//COPIA 
	
	for(int i = 0; i < n; i++) h[i] = hr[i] = 0;
	
	lastI = 0;
	for(int i = 0; i < n; i++) {
		bool onlyDot = true;
		for(int j = 0; j < m; j++) {
			if(mat[i][j] != '.') onlyDot = false;  
		}
		h[i] = 0;
		lastI = i;
		if(!onlyDot) break;
	}
	
	h[lastI] = 1;
	for(int i = lastI + 1; i < n; i++) {
		bool fail = false;
		for(int j = 0; j < m; j++)
			if(mat[i][j] != mat[i - 1][j]) fail = true;
		if(fail) break;
		h[i] = 1;
	}
	
	lastI =  n - 1;
	for(int i = n - 1; i >= 0; i--) {
		bool onlyDot = true;
		for(int j = 0; j < m; j++) {
			if(mat[i][j] != '.') onlyDot = false;  
		}
		hr[i] = 0;
		lastI = i;
		if(!onlyDot) break;
	}
	
	hr[lastI] = 1;
	for(int i = lastI - 1; i >= 0; i--) {
		bool fail = false;
		for(int j = 0; j < m; j++)
			if(mat[i][j] != mat[i + 1][j]) fail = true;
		if(fail) break;
		hr[i] = 1;
	}
	
	for(int i = 0; i < lastI; i++) {
		if(h[i] && hr[i + 1]) {
			printf("YES\n");
			for(int ii = 0; ii <= i; ii++) {
				for(int j = 0; j < m; j++) {
					if(mat[ii][j] != '.') mat[ii][j] = 'a';
				}
			}
			for(int ii = i + 1; ii < n; ii++) {
				for(int j = 0; j < m; j++) {
					if(mat[ii][j] != '.') mat[ii][j] = 'b'; 
				}
			}
			for(int j = 0; j < m; j++) {
				for(int i = 0; i < n; i++) {
					printf("%c", mat[i][j]);
				}
				printf("\n");
			}
			return 0;
		}
	}
	
	// FIM COPIA
	
	printf("NO\n");
	return 0;
}
