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

const int MAXN = 500010;

int k, n, s[MAXN], ult[1000010], res, ri, rj;

int main(){
	scanf("%d%d", &n, &k);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	int i=0, dif=0;
	ri = 0;
	rj = 0;
	memset(ult,-1,sizeof(ult));
	for(int a=0;a<n;a++){
		if(ult[s[a]] < i){
			dif++;
			while(dif > k){
				if(ult[s[i]] == i)
					dif--;
				i++;
			}
		}
		ult[s[a]] = a;
		if(a-i >= rj-ri){
			rj = a;
			ri = i;
		}
	}
	printf("%d %d\n", ri+1, rj+1);
}