#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, res, p;

int main(){
	scanf("%d%d", &n, &m);
	p=0;
	res=1;
	for(int a=0;a<n;a++){
		int v;
		scanf("%d", &v);
		if(p+v<=m){
			p+=v;
		}
		else{
			res++;
			p=v;
		}
	}
	printf("%d\n", res);
	return 0;
}

/*
4 3
2 3 2 1

3 4
1 2 1

6 4
1 2 1 0 4 1

*/
