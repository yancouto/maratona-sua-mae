#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXC = 1000010;

char seq[MAXC];

long long dp[5], res, som;

int main (){
	scanf(" %s", seq);
	int tam = strlen(seq);
	dp[0]=1;
	som=0;
	for(int a=0;a<tam;a++){
		if(seq[a]<'0' || seq[a]>'9'){
			som=0;
			dp[0]=1;
			dp[1]=dp[2]=0;
			continue;
		}
		som=(som+seq[a]-'0')%3;
		res+=dp[som];
		dp[som]++;
	}
	printf("%lld\n", res);
	return 0;
}
