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

int n, s[110];

int main(){
	scanf("%d", &n);
	int ant = 0, res = 0;
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
	}
	int aula = 0;
	for(int a=1;a<=n;a++){
		if(s[a] == 1){
			aula = 1;
			res++;
		}
		else{
			if(!aula){
				continue;
			}
			else{
				if(s[a+1] == 1){
					res++;
				}
				else{
					aula=0;
				}
			}
		}
	}
	printf("%d\n", res);
}