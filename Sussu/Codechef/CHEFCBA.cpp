

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

vector<int> s;

int main (){
	for(int a=0;a<4;a++){
		int i;
		scanf("%d", &i);
		s.pb(i);
	}
	do{
		if(s[0]*s[3] == s[2]*s[1]){
			puts("Possible");
			return 0;
		}
	}while(next_permutation(s.begin(), s.end()));
	puts("Impossible");
}
