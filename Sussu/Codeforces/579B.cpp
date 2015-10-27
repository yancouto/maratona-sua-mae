#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int n;
long long res,fat[100010];

long long expo(long long val,long long exp){
	if(exp==0) return 1;
	if(exp==1) return val;
	long long aux = expo(val,exp/2)%MOD;
	aux=(aux*aux)%MOD;
	if(exp%2!=0)
		aux=(aux*val)%MOD;
	return aux;
}

inline long long mod(long long val){
	return val%MOD;
}

int main (){
	scanf("%d", &n);
	fat[0]=1;
	for(int a=1;a<100001;a++){
		fat[a]=(a*fat[a-1])%MOD;
	}
	long long sete=1, vin=1;
	res=0;
	for(int a=1;a<=n;a++){
		sete=expo(7,n-a);
		vin = (vin*20)%MOD;
		long long aux = mod(mod(fat[n])*mod(mod(expo(fat[n-a],MOD-2)*mod(expo(fat[a],MOD-2)))));
		res=mod(res+mod(mod(sete*vin)*aux));
	}
	printf("%I64d\n", res);
	return 0;
}