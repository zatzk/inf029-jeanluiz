#include <stdio.h>

int verifica(int n, int k, int i) {
	if(n % 10 == k) {
		i++;
	}
	if(n % 10 == n) {
		return i;
	}
	return verifica(n / 10, k, i);
}

int main(){
    int n, k;
	printf("NUMERO INTEIRO\n");
	scanf("%d",&n);
	printf("DIGITO\n");
	scanf("%d",&k);
	printf("\n%d APARECE %d VEZ(ES) EM: %d\n\n", k, verifica(n, k, 0), n);
}