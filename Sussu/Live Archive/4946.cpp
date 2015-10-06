#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXC = 1010, INF = 0x3f3f3f3f;

int t, dp[MAXC][MAXC][3], tam, na[MAXC], res;

char s[MAXC];

int numa(int i){
	//if(i<0) printf("fodeu\n");
	if(i<0) return 0;
	else return na[i];
}

inline int cust(int i){
	return min(i-'A','Z'-i+1);
}

int go(int i,int j,int d){
	if(dp[i][j][d]==INF){
		if(na[j]-na[i-1]==j-i+1) return dp[i][j][d]=0;
		if(d==0){
			dp[i][j][d]=min(dp[i][j][d],go(i+1,j,d)+1);
			dp[i][j][d]=min(dp[i][j][d],go(i,j-1,1-d)+i+(tam-1)-j);
		}
		else{
			dp[i][j][d]=min(dp[i][j][d],go(i,j-1,d)+1);
			dp[i][j][d]=min(dp[i][j][d],go(i+1,j,1-d)+i+(tam-1)-j);
		}
	}
	//printf("%d %d %d %d\n", i, j, d, dp[i][j][d]);
	return dp[i][j][d];
}

int main (){
	scanf("%d", &t);
	for(int z=0;z<t;z++){
		scanf(" %s", s);
		na[0]=0;
		res=0;
		tam=strlen(s);
		memset(dp,INF,sizeof(dp));
		for(int a=0;a<tam;a++){
			res+=cust(s[a]);
			if(a!=0) na[a]=na[a-1];
			if(s[a]=='A'){
				na[a]++;
			}
		}
		printf("%d\n", res+go(1,tam-1,0));
	}
	return 0;
}