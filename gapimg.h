#ifndef _GAPIMG_H_
#define _GAPIMG_H_

#include "mag.h"

#define IMG_SIZE 21

typedef unsigned short int DSType;

typedef DSType GraphImage[IMG_SIZE][IMG_SIZE];

extern void ShowMaGraphImage(MaGraph *mag);


#endif