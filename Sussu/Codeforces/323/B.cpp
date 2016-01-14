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

const int MAXN = 1010;

int n, s[MAXN];

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	int res = -1;
	int cnt = 0;
	int dir = 0;
	while(cnt!=n){
		res++;
		if(!dir){
			for(int a=0;a<n;a++){
				if(s[a] <= cnt){
					cnt++;
					s[a] = MAXN;
				}
			}
			dir = 1-dir;
		}
		else{
			for(int a=n-1;a>=0;a--){
				if(s[a] <= cnt){
					cnt++;
					s[a] = MAXN;
				}
			}
			dir = 1-dir;
		}
	}
	printf("%d\n", res);
}