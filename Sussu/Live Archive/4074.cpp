#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = (1<<13) + 10;

int dp[MAXN][MAXN], mrk[MAXN][MAXN];
char s[30];

vector <pii> fil;

inline int pula(int v){
	//printf("pula %d = ");
	v = (v << 1);
	if(v >= (1<<13)){
		v -= (1<<13);
		v += 1;
	}
	//printf("%d\n", v);
	return v;
}

inline int desce(int v){
	//printf("desce %d = ", v);
	int ans = MAXN;
	ans = min(ans,v);
	for(int a=0;a<13;a++){
		v = pula(v);
		ans = min(ans,v);
	}
	//printf("%d (desce)\n", ans);
	return ans;
}

inline void troca(int *u, int *v){
	int a, b;
	a = ((*u)&1);
	(*u) -= a;
	b = ((*v)&1);
	(*v) -= b;
	swap(a,b);
	(*u) += a;
	(*v) += b;

	a = ((*u)&2);
	(*u) -= a;
	b = ((*v)&2);
	(*v) -= b;
	swap(a,b);
	(*u) += a;
	(*v) += b;

	a = ((*u)&4);
	(*u) -= a;
	b = ((*v)&4);
	(*v) -= b;
	swap(a,b);
	(*u) += a;
	(*v) += b;
}

inline int num(char a){
	if(a == 'g')
		return 1;
	return 0;
}

int main(){
	memset(dp,-1,sizeof(dp));
	dp[(1<<13)-1][0] = 0;
	fil.pb(mp((1<<13)-1,0));
	int i = 0;
	while(i < fil.size()){
		int u = fil[i].fst, v = fil[i].snd;
		int k = dp[u][v];
		for(int a = 0;a < 13;a++){
			u = pula(u);
			for(int b = 0;b < 13;b++){
				v = pula(v);
				int uu = u, vv = v;
				//printf("%d %d -- ", uu, vv);
				troca(&uu, &vv);
				//printf("troca - > %d %d\n", uu, vv);
				uu = desce(uu);
				vv = desce(vv);
				if(dp[uu][vv] == -1){
					dp[uu][vv] = k + 1;
					//printf("dp[%d][%d] = %d\n", uu, vv, k+1);
					fil.pb(mp(uu,vv));
				}
			}
		}
		i++;
	}
	while(scanf(" %s", s) != EOF){
		int u=0, v=0;
		for(int a = 0;a<13;a++){
			u = (u << 1);
			u += num(s[a]);
		}
		for(int a = 13;a<26;a++){
			v = (v << 1);
			v += num(s[a]);
		}
		printf("%d\n", dp[desce(u)][desce(v)]);
	}
}