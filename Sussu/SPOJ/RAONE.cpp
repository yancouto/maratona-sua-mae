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

const int MAXC = 100, MAXN = 100000;

char v1[MAXC], v2[MAXC];
int tam;
long long dp[3][15][100][3]; 

inline int ehum(int val){
	return (val==1);
}

long long go(int tip,int i,int sum,int lo){
	if(dp[tip][i][sum][lo]==-1){
		long long ans=0;
		if(i==tam)
			return ehum(sum);
		int add;
		if((tam-i)%2==0)
			add=1;
		else
			add=-1;
		if(lo){
			for(int d = 0;d <= 9;d++)
				ans+=go(tip,i+1,sum+add*d,lo);
		}
		else{
			for(int d = 0;d < v1[i]-'0';d++)
				ans+=go(tip,i+1,sum+add*d,1);
			ans+=go(tip,i+1,sum+add*(v1[i]-'0'),0);
		}
		//printf("go %d %d %d dando %d\n", i, sum, lo, ans);
		dp[tip][i][sum][lo]=ans;
	}
	return dp[tip][i][sum][lo];
}

inline int v1eh(){
	int add=0;
	int sum=0;
	for(int i=0;i<tam;i++){
		if((tam-i)%2==0)
			add=1;
		else
			add=-1;
		sum += add*(v1[i]-'0');
	}
	return ehum(sum);
}

int main (){
	for_tests(t,tt){
		memset(dp,-1,sizeof(dp));
		scanf(" %s %s", v2, v1);
		tam = strlen(v1);
		long long res = go(0,0,0,0);
		strcpy(v1,v2);
		tam = strlen(v1);
		res -= go(1,0,0,0);
		printf("%lld\n", res+v1eh());
	}
	return 0;
}