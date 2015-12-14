
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

const int INF = 0x3f3f3f3f, MAXN = 1010, MAXC = 1010;



int n, tam, dp[MAXN][MAXN][3], soa[MAXN];

char s[MAXC];

int cust(int p){
	return min(s[p]-'A','Z'-s[p]+1);
}

int go(int i,int j, int dir){
	if(dp[i][j][dir]==INF){
		//printf("(%d, %d) = %d\n", i, j, soa[j] - (i?soa[i-1]:0));
		if(soa[j]-(i?soa[i-1]:0)== j - i + 1) return dp[i][j][dir]=0;
		if(dir==0){
			dp[i][j][dir]=min(go(i+1,j,dir)+1,dp[i][j][dir]);
			dp[i][j][dir]=min(go(i,j-1,1-dir)+i+(tam-j)-1,dp[i][j][dir]);
		}
		else{
			dp[i][j][dir]=min(go(i+1,j,1-dir)+i+(tam-j)-1,dp[i][j][dir]);
			dp[i][j][dir]=min(go(i,j-1,dir)+1,dp[i][j][dir]);
		}
	}	
	return dp[i][j][dir];
}

int main (){
	for_tests(t,tt){
		scanf(" %s", s);
		tam = strlen(s);
		for(int a=0;a<tam;a++){
			for(int b=0;b<tam;b++){
				for(int c=0;c<=1;c++){
					dp[a][b][c]=INF;
				}
			}
		}
		soa[0]=0;
		int res =0;
		for(int a=0;a<tam;a++){
			res+=cust(a);
			if(a!=0)soa[a]=soa[a-1];
			if(s[a]=='A')
				soa[a]++;
		}
		printf("%d\n", go(1,tam-1,0) + res);
	}
	return 0;
}

