const int MAXS = 6543210;

int L, R, Z[MAXS];

char seq[MAXS];

inline void ZAlgorithm(char s[]){
	int tam = strlen(s);
	L = R = 0;
	for(int i=1;i<tam;i++){
		if(i > R){
			L = R = i;
			while(R < tam && s[R] == s[R-L])
				R++;
			Z[i] = R-L; 
			R--;
		}
		else{
			if(Z[i-L] >= R-i+1){
				L = i;
				while(R < tam && s[R] == s[R-L])
					R++;
				Z[i] = R-L;
				R--;
			}
			else
				Z[i] = Z[i-L];
		}
	}
}

int main (){
	scanf("%s", seq);
	ZAlgorithm(seq);
	return 0;
}	
