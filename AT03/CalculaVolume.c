#include <stdio.h>
#include <stdlib.h>
#include "CalculaArea.h"
#include "CalculaVolume.h"


float volumeParalelepipedo(float x, float y, float z){
    return areaRetangulo(x,z)*z;
}