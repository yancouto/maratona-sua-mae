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

const int MAXN = 60, INF = 0x3f3f3f3f;

int n, c[MAXN][2], acu[MAXN][2], t[MAXN];

int main(){
	scanf("%d", &n);
	for(int b=0;b<2;b++){
		for(int a=0;a<n-1;a++){
			scanf("%d", &c[a][b]);

		}
	}
	for(int a=0;a<n;a++){
		scanf("%d", &t[a]);
	}
	for(int a=0;a<n;a++){
		if(a!=0) {
			acu[a][0] = acu[a-1][0];
			acu[a][0] += c[a-1][0];
		}
	}
	for(int a=n-1;a>=0;a--){
		acu[a][1] = acu[a+1][1] + c[a][1];

	}
	int men = INF, smen = INF;
	for(int a=0;a<n;a++){
		if(acu[a][1] + acu[a][0] + t[a] < men){
			smen = men;
			men = acu[a][1] + acu[a][0] + t[a];
		}
		else if(acu[a][1] + acu[a][0] + t[a] < smen){
			smen = acu[a][1] + acu[a][0] + t[a];
		}
	}
	printf("%d\n", smen+men);
}