#include <stdio.h>
int invert(int n){
    if(n==0){
        return 0;
    }
    else{
        printf("%d", n % 10);
        n=n / 10;
        return invert(n);
    }

}
int main(){
    int num=1234;
    printf("%d", invert(num));
}