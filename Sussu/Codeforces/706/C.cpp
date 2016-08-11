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

const int MAXN = 112345;

const ll INF = LLONG_MAX - modn;

int n;

ll dp[MAXN][3], c[MAXN];

char s[MAXN], ult[MAXN], inv[MAXN], invu[MAXN];


int main (){
	int i, j;
	scanf("%d", &n);
	int tam, tamu; 
	for(int a=0;a<n;a++)
		cin >> c[a];
	for(int a=0;a<n;a++){
		for(int b=0;b<2;b++){
			dp[a][b] = INF;
		}
	}
	dp[0][0] = 0;
	dp[0][1] = c[0];
	for(int a=0;a<n;a++){
		if(a!=0){
			for(int b=0;b<tam;b++){
				ult[b] = s[b];
				invu[b] = inv[b];
			}
			ult[tam] = '\0';
			invu[tam] = '\0';
		}
		scanf(" %s", s);
		tam = strlen(s);
		s[tam] = '\0';
		for(int b=0;b<tam;b++){
			inv[tam-b-1] = s[b];
		}
		inv[tam] = '\0';
		if(a != 0){
			if(strcmp(s, ult) >= 0){
				//	printf("1 %d\n", a);
				dp[a][0] = min(dp[a][0], dp[a-1][0]);
			}
			if(strcmp(s, invu) >= 0){
				//printf("2 %d\n", a);
				dp[a][0] = min(dp[a][0], dp[a-1][1]);
			}
			if(strcmp(inv, ult) >= 0){
				//printf("3 %d\n", a);
				dp[a][1] = min(dp[a][1], dp[a-1][0] + c[a]);
			}
			if(strcmp(inv, invu) >= 0){
				//printf("4 %d\n", a);
				dp[a][1] = min(dp[a][1], dp[a-1][1] + c[a]);
			}
		}
	}
	ll res = min(dp[n-1][0], dp[n-1][1]);
	if(res == INF)
		puts("-1");
	else
		cout << res << endl;

}
