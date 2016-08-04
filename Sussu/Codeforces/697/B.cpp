
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

const int MAXC = 110;

int n, e;

char s[MAXC];

vector<int> nn, mm;

int main (){
	int i, j;
	scanf("%d.", &n);
	scanf(" %s", s);
	int tam = strlen(s);
	int ce = 0;
	int ex = 0;
	for(i = 0;i < tam;i++){
		if(s[i] == 'e'){
			ce = i;
			break;
		}
	}
	for(i = ce+1;i<tam;i++){
		ex *= 10;
		ex += (s[i]-'0');
	}
	tam = ce;
	int ehz = (n == 0);
	nn.pb(n);
	i = 0;
	while(ex != 0 && i < tam){
		nn.pb(s[i]-'0');
		if(s[i]-'0' != 0)
			ehz = 0;
		ex--;
		i++;
	}
	while(ex != 0){
		nn.pb(0);
		ex--;
	}
	int ehz2 = 1;
	while(i < tam){
		mm.pb(s[i]-'0');
		if(s[i]-'0' != 0)
			ehz2 = 0;
		i++;
	}
	int naoz = 1;
	if(ehz && ehz2){
		puts("0");
		return 0;
	}
	else if(ehz){
		printf("0.");
		int ult = 0;
		for(i=0;i<mm.size();i++){
			if(mm[i] != 0)
				ult = i;
		}
		for(i=0;i<=ult;i++){
			printf("%d", mm[i]);
		}
	}
	else if(ehz2){
		int pri = 0;
		for(i = nn.size()-1;i>=0;i--){
			if(nn[i] != 0)
				pri = i;
		}
		for(i = pri;i < nn.size();i++){
			printf("%d", nn[i]);
		}
	}
	else{
		int pri = 0;
		for(i = nn.size()-1;i>=0;i--){
			if(nn[i] != 0)
				pri = i;
		}
		for(i = pri;i < nn.size();i++){
			printf("%d", nn[i]);
		}
		printf(".");
		int ult = 0;
		for(i=0;i<mm.size();i++){
			if(mm[i] != 0)
				ult = i;
		}
		for(i=0;i<=ult;i++){
			printf("%d", mm[i]);
		}
	}
}
