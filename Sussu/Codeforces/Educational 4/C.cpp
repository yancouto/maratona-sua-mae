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

char s[1000010];

int deg, res, val[100000];
char fil[1000010];

int main (){
	scanf(" %s", s);
	val['('] = 0;
	val[')'] = 1;
	val['['] = 2;
	val[']'] = 3;
	val['{'] = 4;
	val['}'] = 5;
	val['<'] = 6;
	val['>'] = 7;
	int tam = strlen(s);
	res = deg = 0;
	for(int a = tam-1;a>=0;a--){
		if(s[a] == ']' || s[a] == ')' || s[a] == '}' || s[a] == '>'){
			fil[deg++] = s[a];
		}
		else{
			if(deg==0){
				printf("Impossible\n");
				return 0;
			}
			if(val[fil[deg-1]] != val[s[a]]+1)
				res++;
			deg--;
		}
	}
	if(deg != 0){
		printf("Impossible\n");
		return 0;

	}
	printf("%d\n", res);
}