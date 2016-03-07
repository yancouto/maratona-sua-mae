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

const int MAXN = 1010;

int s[MAXN], n, mrk[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	sort(s, s+n);
	int res = 0;
	for(int a=0;a<n;a++){
		if(mrk[a]) continue;
		mrk[a] = 1;
		int ult = a;
		for(int b = a+1;b<n;b++){
			if(mrk[b])continue;
			if(s[b] > s[ult]){
				mrk[b] = 1;
				ult = b;
				res++;
			}
		}
	}
	printf("%d\n", res);
}