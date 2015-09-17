#include <cstdio>
#include <algorithm>

using namespace std;

int n, l[1005], aux[1005], resp[1005];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		char c;
		scanf(" %c", &c);
		l[i] = c - '0';
		resp[i] = 11;
	}
	for(int i = 0; i < n; i++){
		int t = 10 - l[i];
		for(int j = 0; j < n; j++)
			aux[j] = (l[j] + t) % 10;
		for(int k = 0; k < n; k++){
			int a = (k + i) % n;
			if(aux[a] > resp[k]) break;
			if(aux[a] < resp[k]){
				for(int g = 0; g < n; g++)
					resp[g] = aux[(g+i)%n];
				break;
			}
		}
	}
	for(int i = 0; i < n; i++)
		printf("%d", resp[i]);
	printf("\n");
	return 0;
}
