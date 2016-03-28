
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

const int MAXN = 10000010;

int cr[MAXN];

int n, m;

vector <int> p;

void pre(){
	for(int a=2;a<10010;a++){
		if(cr[a] == 0){
			cr[a] = a;
			for(int b=a;b*a<MAXN-1;b++){
				cr[b*a] = a;
			}
		}
	}
}

inline int cnt (int v){
	int ans = 0;
	while( cr[v] != 0 ){
		v /= cr[v];
		ans++;
	}
	if(v == 1) ans--;
	return ans+1;
}

int main(){
	freopen("funny.in", "r", stdin);
	freopen("funny.out", "w", stdout);
	pre();
	while(scanf("%d%d", &n, &m)!= EOF && n + m != 0){
		printf("%d %d - ", n, m);
		if(cnt(n) > cnt(m)) puts("Vera");
		else puts("Harry");
	}
}
