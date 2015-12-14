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

char s[110], sim[110];
int n;

int main (){
	strcpy(sim,"Simon says ");
	fgets(s, 100, stdin);
	sscanf(s, "%d", &n);
	for(int t=0;t<n;t++){
		fgets(s, 110, stdin);
		int tam = strlen(s);

		for(int a=0;a<tam;a++){	
			if(a<11){

				if(s[a]!=sim[a]){
					break;
				}
			}
			else
				printf("%c", s[a]);
		}
	}
	return 0;
}
