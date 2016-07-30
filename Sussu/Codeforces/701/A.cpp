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
int s[110], mrk[110];

int main (){
	scanf("%d ", &n);
	int sum  = 0;
	for(int a=0;a<n;a++){

		scanf("%d", &s[a]);
		sum += s[a];
	}
	int met = (sum*2)/n;
	for(int a=0;a<n;a++){
		if(mrk[a]) continue;
		for(int b=a+1;b<n;b++){
			if(mrk[b]) continue;
			if(s[a] + s[b] == met){
				printf("%d %d\n", a+1, b+1);
				mrk[b] = 1;
				break;
			}
		}
	}
}
