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

const int MAXC = 100010;

int n;

ll zer, ja, nbt, ver;

char num[MAXC], nb[MAXC];

int main (){
	scanf("%d", &n);
	ja = 0;
	for(int a=0;a<n;a++){
		scanf(" %s", num);
		if(num[0] == '0' || ver==1){
			ver = 1;
			continue;
		}
		int tam = strlen(num);
		int cnt = 0, eh = 0;
		if(ja){
			zer += tam-1;
			continue;
		}
		nbt = tam;
		for(int b=0;b<tam;b++){
			nb[b] = num[b];
			if (num[b] == '1'){
				cnt++;
			}
			else if(num[b] != '0'){
				eh = 1;
			}
		}
		ja = ((eh == 1) || (cnt > 1));
		if(ja == 0)
			zer += tam-1;
	}
	if(ver==1){
		printf("0");
		return 0;
	}
	if(ja){
		for(int a=0;a<nbt;a++){
			printf("%c", nb[a]);
		}
	}
	else{
		printf("1");
	}
	while(zer){
		printf("0");
		zer--;
	}
}