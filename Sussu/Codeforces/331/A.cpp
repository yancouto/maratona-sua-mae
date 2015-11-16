#include <cstdio>

int n, x[6], y[6];

inline int abs(int v){
	if(v<0) return -v;
	return v;
}

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d %d", &x[a], &y[a]);
	}
	if(n==1)
		printf("-1\n");
	else if(n==2){
		if(x[1] != x[0] && y[1] != y[0])
			printf("%d\n", abs((y[1]-y[0])*(x[1]-x[0])));
		else
			printf("-1\n");
	}
	else{
		int res =0;
		if(y[1]!=y[0])
			res = (y[1]-y[0]);
		else if(y[2]!=y[0])
			res = (y[2]-y[0]);
		else
			res = (y[1]-y[2]);
		if(x[1]!=x[0])
			res *= (x[1]-x[0]);
		else if(x[2]!=x[0])
			res*= (x[2]-x[0]);
		else
			res*= (x[2]-x[1]);
		if(res<0)
			res*=-1;
		printf("%d\n", res);
	}
	return 0;
}


