#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010, MAXF = 10000010, INF = 0x3f3f3f3f;

int t,dp[MAXN], v[10], degi, degf;

struct fila{
	int i, d;
} fil[MAXF];

void go(int i,int d){
	while(degi!=degf){
		i = fil[degi].i;
		d = fil[degi].d;
		if(d==100)
			return;
		degi++;
		for(int a=0;a<6;a++){
			if(dp[i+v[a]]==INF){
				fil[degf].i=i+v[a];
				fil[degf++].d=d+1;
			}
			dp[i+v[a]]=min(dp[i+v[a]],dp[i]+1);
			if(i>=v[a]){
				if(dp[i-v[a]]==INF){
					fil[degf].i = i-v[a];
					fil[degf++].d = d+1;
				}
				dp[i-v[a]]=min(dp[i-v[a]],dp[i]+1);
			}
		}
	}
	return;
}

int main(){
	scanf("%d", &t);
	for(int z=0;z<t;z++){
		memset(dp,INF,sizeof(dp));
		dp[0]=0;
		for(int a=0;a<6;a++)
			scanf("%d", &v[a]);
		degf=degi=0;
		fil[degf].i=0;
		fil[degf++].d=0;
		go(0,0);
		int som=0, mai=0;
		for(int a=1;a<101;a++){
			mai = max(mai,dp[a]);
			som += dp[a];
		}
		printf("%d.",som/100);
		if(som%100<10)
			printf("0");
		printf("%d %d\n", som%100, mai);
	}
	return 0;
}
