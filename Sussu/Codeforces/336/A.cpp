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

int n, m;
ll tem[1010];

int main (){
	scanf("%d%d", &n, &m);
	ll res = 0;
	memset(tem,-1,sizeof(tem));
	for(int a=0;a<n;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		tem[i] = max(tem[i],ll(j));
	}
	for(int a = m;a>0;a--){
		if(tem[a]>res){
			res = tem[a];
		}
		res++;
	}
	cout << res;
}