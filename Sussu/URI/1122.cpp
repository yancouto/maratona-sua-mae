
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

int n, s[MAXN];

char res[MAXN];

vector <int> sum[61234];

void result(int i, char c){
	if(res[i] == '+')
}

int main (){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
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
		sum[som].pb(i);
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
		if(sum[sob].empty()) continue;

		for(int d=0;d<n-m;d++){
			if((1<<d)&i)
				result(d+m, '+');
			else
				result(d+m, '-');
		}
		for(int a=0;a<sum[sob].size();a++){
			for(int d=0;d<m;d++){
				if((1<<d)&sum[sob][a])
					result(d, '+');
				else
					result(d, '-');
			}
		}
	}
}
