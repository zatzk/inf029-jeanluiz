#include <stdio.h>

int mult(int a, int b) {
	if(a == 0 || b == 0) {
		return 0;
	}
	if(b == 1) {
		return a;
	}
	return a + mult(a, b - 1);
}
int main(){
    int a, b;
    printf("Digite os valores: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d", mult(a, b));
}