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

const int MAXN = 100010;

int n; 
ll s[MAXN], p;

int main (){
	for_tests(t,tt){
		scanf("%d %lld", &n, &p);
		for(int a=0;a<n;a++){
			scanf("%lld", &s[a]);
		}
		int i=-1, j=0;
		ll sum = 0, res = 0;
		while(j<n){
			sum += s[j];
			while(i < j && sum > p){
				i++;
				sum -= s[i];
			}
			res += j-i;
			j++;
		}
		printf("Case #%d: %lld\n", tt, res);
	}
}