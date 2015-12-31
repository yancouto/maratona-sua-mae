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

const int MAXN = 5010;

int n, s[MAXN];

ll dp[MAXN][MAXN], h[MAXN], pot[MAXN];

inline int cmp(int i,int j){
	if( i < j )
		return 1;
	else if(i == j)
		return 2;
	else
		return 3;
}

void pre(){
	pot[0] = 1;
	h[0]=0;
	for(int i = 1;i <= n;i++){
		h[i] = mod(h[i-1] + s[i]*pot[i-1]);
		//printf("%d hash %lld\n", i, h[i]);
		pot[i] = mod(pot[i-1]*10);
	}
	pot[n+1] = mod(pot[n]*10);
}

inline ll hashval(int i,int j){
	ll ans = h[j] - h[i];
	while(ans < 0) ans += modn;
	//printf("hash val %d - %d: %lld\n", i, j, ans);
	return ans;
}

inline int bb(int i,int j, int k){
	int ini = 0, fim = j-i;
	while(ini < fim){
		int m = (ini+fim+1)/2;
		//printf("na bb de %d %d %d - %d m %d %d - %lld == %lld\n", i, j, k, ini, m, fim, mod(hashval(i,i+m)*pot[j-i]), hashval(j,j+m));
		if(mod(hashval(i,i+m)*pot[j-i]) == hashval(j,j+m))
			ini = m;
		else
			fim = m-1;
		//printf("loop end %d %d\n", ini, fim);
	}
	return ini;
}

bool ehmaior(int i,int j,int k){
	int tam = bb(i,j,k);
	//printf("%d %d %d iguais ate %d\n", i, j, k, tam);
	if(tam == j-i) return 0;
	if(s[i+1+tam] > s[j+1+tam]) return 0;
	else return 1;
}

ll go(int ant,int ult){
	if(dp[ant][ult] == -1){
		dp[ant][ult] = 0;
		
		if(ult == n) return dp[ant][ult] = 1;

		dp[ant][ult] = mod(dp[ant][ult] + go(ant,ult+1));
		
		if(ult+ ult-ant > n || s[ult+1] == 0) return dp[ant][ult];
		int nxt = ult + ult-ant + !ehmaior(ant,ult,ult + ult-ant);
		if(nxt > n) return dp[ant][ult];
		dp[ant][ult] = mod(dp[ant][ult] + go(ult,nxt));
	}
	return dp[ant][ult];
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		char c;
		scanf(" %c", &c);
		s[a] = c-'0';
	}
	pre();
	cout << mod(go(0,1));

}