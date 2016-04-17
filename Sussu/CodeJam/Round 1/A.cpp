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

int s[15], cnt, n;

inline void mrk(int n){
	while(n!=0){
		if(!s[n%10]){
			s[n%10] = 1;
			cnt++;
		}
		n/=10;
	}
}

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		memset(s, 0, sizeof(s));
		cnt = 0;
		printf("Case #%d: ", tt);
		if(n == 0){
			puts("INSOMNIA");
			continue;
		}
		for(int a=1;;a++){
			mrk(a*n);
			if(cnt == 10){
				printf("%d\n", a*n);
				break;
			}
		}
	}
}