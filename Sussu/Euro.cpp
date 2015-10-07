
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

const int INF = 0x3f3f3f3f;

int n, dp[1000005], v[10];

int main (){
	for_tests(t,tt){
	for(int a=0;a<6;a++){
		scanf("%d", &v[a]);
	}
	for(int a=0;a<=1000005;a++)
		dp[a]=INF;
	dp[0]=0;
	for(int a=0;a<6;a++){
		for(int b=0;b<=1000005-v[a];b++){
			if(dp[b]!=INF){
				dp[b+v[a]]=min(dp[b+v[a]],dp[b]+1);
			}
		}
	}//sem dar troco
	for(int a=0;a<6;a++){
		for(int b=1000005;b>=0+v[a];b--){
			if(dp[b]!=INF){
				dp[b-v[a]]=min(dp[b-v[a]],dp[b]+1);
			}
		}
	}//dando troco
	int som=0, mai=-1;
	for(int a=1;a<=100;a++){
//		printf("%d %d\n", a, dp[a]);
		mai=max(mai,dp[a]);
		som+=dp[a];
	}
	int dec = som%100;
	int num = som/100;
	printf("%d.", num);
	if(dec<10)
		printf("0");
	printf("%d %d", dec, mai);
	if(tt<t)printf("\n");
	}
	return 0;

}
