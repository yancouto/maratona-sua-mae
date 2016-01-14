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

int n, v[60], h[60];

int main(){
	scanf("%d", &n);
	for(int a=0;a<n*n;a++){
		int i, j;
		scanf("%d%d", &i, &j);
		if(!v[i] && !h[j]){
			v[i] = 1;
			h[j] = 1;
			printf("%d ", a+1);
		}

	}
}