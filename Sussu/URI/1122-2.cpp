
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

const int MAXN = 45, MSUM = 81234, CONS = 40500;

int s[MAXN];

int dp[MAXN][MSUM];
int sol[MAXN][MSUM];
int t[MAXN][MSUM];
int tsol[MAXN][MSUM];

char res[MAXN];

int n, k;

int main (){
	int tt =0;
	while(scanf("%d%d", &n, &k) != EOF && n+k !=0){
		tt++;
		for(int a=0;a<n;a++){
			res[a] = ' ';
			scanf("%d", &s[a]);
		}
		dp[0][CONS] = 1;
		t[0][CONS] = tt;
		for(int i=0;i<n;i++){
			for(int a=0;a<MSUM;a++){
				if(t[i][a] != tt){
					t[i][a] = tt;
					dp[i][a] = 0;
				}
				if(dp[i][a] != 0){
					t[i+1][a+s[i]] = tt;
					dp[i+1][a+s[i]] = 1;
					t[i+1][a-s[i]] = tt;
					dp[i+1][a-s[i]] = 1;
				}
			}
		}
		if(t[n][CONS+k] != tt){
			t[n][CONS+k] = tt;
			dp[n][CONS+k] = 0;
		}
		if(dp[n][CONS+k] != 1){
			puts("*");
			continue;
		}
		tsol[n][CONS+k] = tt;
		sol[n][CONS+k] = 1;
		for(int i=n;i>0;i--){
			for(int a=0;a<MSUM;a++){
				if(tsol[i][a] != tt){
					tsol[i][a] = tt;
					sol[i][a] = 0;
				}
				if(sol[i][a] != 0){
					tsol[i-1][a+s[i-1]] = tt;
					sol[i-1][a+s[i-1]] = 1;
					tsol[i-1][a-s[i-1]] = tt;
					sol[i-1][a-s[i-1]] = 1;
					if(t[i-1][a+s[i-1]]!=tt){
						t[i-1][a+s[i-1]] = tt;
						dp[i-1][a+s[i-1]] = 0;
					}
					if(t[i-1][a-s[i-1]]!=tt){
						t[i-1][a-s[i-1]] = tt;
						dp[i-1][a-s[i-1]] = 0;
					}
					if(res[i-1] == '?') continue;
					if(dp[i-1][a+s[i-1]]){
						if(res[i-1] == '+')
							res[i-1] = '?';
						else
							res[i-1] = '-';
					}
					if(res[i-1] == '?') continue;
					if(dp[i-1][a-s[i-1]]){
						if(res[i-1] == '-')
							res[i-1] = '?';
						else
							res[i-1] = '+';
					}
				}
			}
		}
		for(int a=0;a<n;a++){
			printf("%c", res[a]);
		}
		printf("\n");
	}
}
