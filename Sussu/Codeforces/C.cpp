
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

const int MAXN = 50010;

int n, m, mrk[MAXN], men[MAXN];

char s[MAXN][60], res[MAXN];

int main (){
	scanf("%d", &n);
	int tot = 0;
	for(int a=0;a<n;a++){
		scanf(" %s", s[a]);
		tot += strlen(s[a]);
	}
	for(int a = 0;a<n;a++){
		char men = 'z' + 1;
		int cnt = 0;
		int l = 0;
		while(cnt  != 1){
			for(int p=0;p<n;p++){
				if(mrk[p]) continue;
				if(men > s[p][l])	x
			}
		}
			
	}
}

