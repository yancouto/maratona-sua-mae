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

int mes[35];
int week[35];

int n;
char s[1000];

int main (){
	scanf("%d", &n);
	scanf(" %[^\n]", s);
	for(int a=1;a<=29;a++)
		mes[a] = 12;
	mes[30] = 11;
	mes[31] = 7;

	week[1] = 52;
	week[2] = 52;
	week[3] = 52;
	week[4] = 52;
	week[5] = 53;
	week[6] = 53;
	week[7] = 52;
	
	if(strcmp(s,"of week") ==0){
		printf("%d", week[n]);
	}
	else
		printf("%d", mes[n]);

}