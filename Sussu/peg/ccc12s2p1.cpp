#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXV = 5000010;

int w, d, dig[150], v, dp[MAXV][10], q[100];

bool ehint(double v){
	if(floor(v)==v) return true;
	return false;
}

int go(int v,int o){
	if(dp[v][o]==-1){
		if(o==0) return dp[v][o]=0;
		dp[v][o]=0;
		for(int a=0;a<d;a++){
		    if(dig[a]!=0)
                if(ehint((double)v/dig[a]))
                    dp[v][o]=max(dp[v][o],go(v/dig[a],o-1));
			if(v-dig[a]>=0)
				dp[v][o]=max(dp[v][o],go(v-dig[a],o-1));
		}
	}
	return dp[v][o];
}

int main (){
	scanf("%d%d", &w, &d);
	for(int a=0;a<MAXV-5;a++){
		for(int b=0;b<=6;b++){
			dp[a][b]=-1;
		}
	}
	for(int a=0;a<d;a++){
		scanf("%d", &dig[a]);
		dp[dig[a]][0]=1;
		//fil[deg[0]++][0]=dig[a];
	}
	scanf("%d", &v);
	for(int a=0;a<v;a++){
		scanf("%d", &q[a]);
		if(go(q[a],w)==1)
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}

/*
6
3
6
7
8
1
35336

3
2
4
9
2
97
88

*/
