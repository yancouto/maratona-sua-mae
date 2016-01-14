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


const int MAXN = 4010;
int n, mrk[MAXN];

struct child
{
	ll v, d, c;
} s[MAXN];

vector<int> res;

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		cin >> s[a].v >> s[a].d >> s[a].c;
	}
	int i = 0;
	while(i < n){
		if(mrk[i]==1){
			i++;
			continue;
		}
		res.pb(i);
		ll off = s[i].v, car = 0;
		for(int a=i+1;a<n;a++){
			if(mrk[a] == 0){
				s[a].c -= (max(0ll,off) + car);
				if(s[a].c < 0){ 
					mrk[a] = 1;
					car += s[a].d;
				}
				off--;
			}
		}
		i++;
	}
	printf("%d\n", res.size());
	for(int a=0;a<res.size();a++){
		printf("%d ", res[a]+1);
	}
}