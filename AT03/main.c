#include <stdio.h>
#include <stdlib.h>
#include "CalculaArea.h"
#include "CalculaVolume.h"

int main(){

    float x,y,z,vol;

    printf("Digite X: ");
    scanf("%f",&x);
    printf("Digite Y: ");
    scanf("%f",&y);
    printf("Digite Z: ");
    scanf("%f",&z);

    vol = volumeParalelepipedo(x,y,z);
    printf("Volume: %f", vol);

    return 0;
}
