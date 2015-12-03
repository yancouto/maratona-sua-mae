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

const int MAXN = 100010;

int n, k;

int s[MAXN];
int val[] = {0,1,0,1,2};	

int f(int v){
	if(k%2==1){
		if(v>=0 && v<=4)
			return val[v];
		if(v%2==1) return 0;
		int ans = f(v/2);
		if(ans==0) return 1;
		else return 3-ans;
	}
	else{
		if(v>=0 && v<=2) return v;
		return !(v%2);
	}
}

int main (){
	int res = 0;
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		int aux = f(s[a]);
		res ^= f(s[a]) + (s[a]%2==0 && aux==0 && s[a]>2 && k%2==1);

	}
	if(res != 0)
		printf("Kevin\n");
	else
		printf("Nicky\n");
	return 0;
}