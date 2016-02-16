#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<int, piii> piiii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 100010;

int n, adj[MAXN], deg[MAXN];

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int c;
		scanf("%d", &c);
		deg[c]++;
	}
	for(int a=1;a<=n;a++){
		if(!deg[a])
			printf("%d ", a);
	}
}