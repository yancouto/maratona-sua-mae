#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;

const long long MOD = 10000000LL;

long long f[MAXN], n;
int degr;

long long numz(long long val){
	while(val%10==0)
		val/=10;
	return val;
}

int main (){
	f[0]=1;
	for(long long a=1;a<MAXN-5;a++){
		f[a]=(numz(f[a-1]*a))%MOD;
	}
	while(scanf("%lld", &n)!=EOF) printf("Instancia %d\n%lld\n", ++degr, f[n]%10);
	return 0;
}