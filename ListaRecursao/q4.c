#include <stdio.h>

int somar(int v[], int t){
    
    if(t==0){
        return 0;
    }
    else{
        return v[t-1] + somar(v,t-1);
    }
}
int main(){
    int v[5] = { 1, 2, 3, 4, 5};
    printf("%d", somar(v, 5));
}