#include <cstdio>
#include <cstring>
#include <algorithm>

int n;
int x[10];
int memo[10][3][10][3][12];

int solve(int i, int prefix, int sum, int lz, int dig) {
	if(i==-1) return sum;
	int &m=memo[i][prefix][sum][lz][dig];
	if(m!=-1) return m;
	
	int ans=0;
	for(int k = 0; k <= 9; k++) {
		if(prefix && k > x[i]) break;
		if(dig != 0)
			ans+=solve(i-1, prefix&&(k==x[i]), sum+(k==dig), lz, dig);
		else
			ans+=solve(i-1, prefix&&(k==x[i]), sum+((k==dig)&&lz), (lz)?1:(k!=0), dig); 
	}
	return m=ans;
}

int main () {
	int A, B;
	while (true) {
		int totA[10], totB[10], num;
		
		scanf("%d %d", &A, &B);
		if (A == 0 && B == 0) break;

		memset(memo, -1, sizeof memo);
		n=0; num=A-1;
		while(num>0) {
			x[n++]=num%10;
			num/=10;
		}
		for(int i=0; i<=9; i++)
			totA[i]=solve(n-1,1,0,0,i);
		
		memset(memo, -1, sizeof memo);			
		n=0; num=B;
		while(num>0) {
			x[n++]=num%10;
			num/=10;
		}
		for(int i=0; i<=9; i++)
			totB[i]=solve(n-1,1,0,0,i);
		
		for(int i=0; i<9; i++)
			printf("%d ", totB[i]-totA[i]);
		printf("%d\n", totB[9]-totA[9]);	
	}
	return 0;
}
