
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

const int MAXN = 50, CONST = 30000;

int n, s[MAXN], k;

char res[MAXN];

char sum[61234][30];

int tem[61234][30];

int bsum[(1<<22)][3];

int mrk[61234];

inline char result(char i, char c){
	if(i == ' ')
		return c;
	else if(i != c)
		return '?';
}

inline void valid(int s, int d, int t){
	if(tem[s][d] != t){
		sum[s][d] = ' ';
		tem[s][d] = t;
	}
}

int main (){
	int tt = 0;
	while(scanf("%d%d", &n, &k)!=EOF && n+k!=0){
		tt++;
		int t = clock();
		printf("comeca teste com %f\n", ((float)t)/CLOCKS_PER_SEC);
		if(n == 0 && k == 0) break;
		for(int a=0;a<n;a++){
			res[a] = ' ';
			scanf("%d", &s[a]);
		}
		int m = n/2;
		for(int i = 0;i<(1<<m);i++){
			int som  = 0;
			for(int d = 0;d<m;d++){
				if((1<<d)&i)
					som += s[d];
				else
					som -= s[d];
			}
			som += CONST;
			for(int d = 0;d<m;d++){
				if((1<<d)&i){
					valid(som, d, tt);
					sum[som][d] = result(sum[som][d], '+');
				}
				else{
					valid(som, d, tt);
					sum[som][d] = result(sum[som][d], '-');
				}

			}
		}
		for(int i = 0;i<(1<<(n-m));i++){
			int som = 0;
			for(int d=0;d<n-m;d++){
				if((1<<d)&i)
					som += s[d+m];
				else
					som -= s[d+m];
			}	
			int sob = k - som + CONST;
			valid(sob, 0, tt);
			if(sum[sob][0] == ' ') continue;

			for(int d=0;d<n-m;d++){
				if((1<<d)&i)
					res[d+m] = result(res[d+m], '+');
				else
					res[d+m] = result(res[d+m], '-');
			}
			if(mrk[sob] == tt) continue;
			mrk[sob] = tt;
			for(int d=0;d<m;d++){
				res[d] = result(res[d], sum[sob][d]);
			}
		}
		if(res[0] == ' '){
			puts("*");
			continue;
		}
		for(int a=0;a<n;a++){
			printf("%c", res[a]);
		}
		printf("\n");
		printf("termina teste com %f\n", ((float)clock())/CLOCKS_PER_SEC);
	}
}
