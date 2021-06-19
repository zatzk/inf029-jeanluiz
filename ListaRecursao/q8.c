#include <stdio.h>

int mdc(int x, int y){
    if(y == 0){
        return x;
    }
    else{
        return mdc(y, x %y);
    }
}
int main(){
    int x,y;
    printf("Digite os valores de x e y\n");
    scanf("%d", &x);
    scanf("%d", &y);

    printf("%d", mdc(x, y));
}