#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n, m[55][210], tam[55];

int dp[55][210][10];

bool valid(int i, int j){
	return (i > 0 && j > 0 && i <= n && j <= tam[i]);
}

int tenta(int i, int j, int d){
	if(!valid(i, j)) return 1;
	return dp[i][j][d];
}

int mint (int i, int j, int d, int ii, int jj, int dd){
	return min(dp[i][j][d], tenta(ii, jj, dd));
}

int move(int i, int j, int d){
	if(d == 0){
		if(j&1)
			dp[i][j][d] = tenta(i, j-1, d);
		else
			dp[i][j][d] = tenta(i-1, j-1, d); 
	}
	
	else if(d == 1){
		if(j&1)
			dp[i][j][d] = tenta(i, j-1, d);
		else
			dp[i][j][d] = tenta(i-1, j, d);
	}
	else if(d == 2){
		if(j&1){
			if(!valid(i, j-1) && !valid(i-1, j-1) && !valid(i, j+1))
				dp[i][j][d] = 1;
			else{
				dp[i][j][d] = min(dp[i][j][d], tenta(i, j-1, d));
				dp[i][j][d] = min(dp[i][j][d], tenta(i-1, j-1, d));
				dp[i][j][d] = min(dp[i][j][d], tenta(i, j+1, d));
			}
		}
		else{
			dp[i][j][d] = tenta(i-1, j-1, d);
		}
	}
	else if(d == 3){
		if(j&1){
			dp[i][j][d] = tenta(i, j+1, d);
		}
		else{
			dp[i][j][d] = tenta(i-1, j, d);
		}
	}
	else if(d == 4){
		dp[i][j][d] = tenta(i, j+1, d);
	}
	else if(d == 5){
		if(j&1)
			dp[i][j][d] = tenta(i+1, j+1, d);
		else{
			dp[i][j][d] = tenta(i, j+1, d);
		}
	}
	else if(d == 6){
		if(j&1){
			dp[i][j][d] = mint(i, j, d, i+1, j, d);
			dp[i][j][d] = mint(i, j, d, i+1, j+1, d);
			dp[i][j][d] = mint(i, j, d, i+1, j+2, d);
		}
		else{
			dp[i][j][d] = mint(i, j, d, i, j-1, d);
			dp[i][j][d] = mint(i, j, d, i+1, j+1, d);
			dp[i][j][d] = mint(i, j, d, i, j+1, d);
		}
	}
	else if(d == 7){
		if(j&1){
			dp[i][j][d] = tenta(i+1, j+1, d);
		}
		else
			dp[i][j][d] = tenta(i, j-1, d);
	}
	return dp[i][j][d];
}

int main (){
	int t = 1;
	while(scanf("%d", &n)!=EOF && n!=0){
		memset(dp, -1, sizeof(dp));
		tam[1] = 1;
		for(int a=1;a<=n;a++){
			tam[a+1] = tam[a] + 2;
			for(int b=1;b<=tam[a];b++){
				char c;
				scanf(" %c", &c);
				m[a][b] = c-'0';
				if(m[a][b] == 1){
					for(int d=0;d<=7;d++){
						dp[a][b][d] = 0;
					}
				}
			}
		}
		int res = 0;

		for(int d=0;d<3;d++){
			int ans = 1;
			for(int a=1;a<=n;a++){
				for(int b=1;b<=tam[a];b++){
					if(m[a][b] == 1)
						ans = min(ans,move(a, b, d));
				}
			}
		//	printf("%d ans %d\n", d, ans);
			res = max(res, ans);
		}
		for(int d=3;d<4;d++){
			int ans = 1;
			for(int a=1;a<=n;a++){
				for(int b=tam[a];b>=1;b--){
					if(m[a][b] == 1)
						ans = min(ans, move(a, b, d));
				}
			}
		//	printf("%d ans %d\n", d, ans);
			res = max(res, ans);
		}
		for(int d=4;d<5;d++){
			int ans = 1;
			for(int a=n;a>=1;a--){
				for(int b=tam[a];b>=1;b--){
					if(m[a][b] == 1)
						ans = min(ans, move(a, b, d));
				
				}
			}
		//	printf("%d ans %d\n", d, ans);
			res = max(res, ans);
		}
		for(int d=5;d<7;d++){
			int ans = 1;
			for(int a=n;a>=1;a--){
				for(int b=tam[a];b>=1;b--){
					if(m[a][b] == 1)
						ans = min(ans, move(a, b, d));
				}
			}
		//	printf("%d ans %d\n", d, ans);
			res = max(res, ans);
		}
		for(int d=7;d<8;d++){
			int ans = 1;
			for(int a=n;a>=1;a--){
				for(int b=1;b<=tam[a];b++){
					if(m[a][b] == 1)
						ans = min(ans, move(a, b, d));
				}
			}
		//	printf("%d ans %d\n", d, ans);
			res = max(res, ans);
		}
		printf("Puzzle %d\n", t++);
		if(res == 1)
			puts("Parts can be separated");
		else
			puts("Parts cannot be separated");
		printf("\n");

	}
}
