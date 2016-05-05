
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

const int MAXN = 212345;

map <int, int> mrk;

int n, m, s[MAXN], c[3][MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		if(mrk.find(s[a]) == mrk.end()){
			mrk[s[a]] = 1;
		}
		else
			mrk[s[a]]++;
	}
	scanf("%d", &m);
	for(int b=0;b<2;b++){
		for(int a=0;a<m;a++){
			scanf("%d", &c[b][a]);
		}
	}
	int ires = 0;
	for(int a=1;a<m;a++){
		if(mrk[c[0][a]] > mrk[c[0][ires]] || (mrk[c[0][a]] == mrk[c[0][ires]] && mrk[c[1][a]] > mrk[c[1][ires]]))
			ires = a;
	}
	printf("%d\n", ires+1);
}
