#include <stdio.h>
#include <math.h>

/**
* Program Name: Basic Formulas
* Assignment Name: Programming Assignment 1
* Student Name: Jessica Foley
* Description: Asks user for radius R, height a (top area), height b (bottom area), and uses various formulas
* to calculate the surface area and volume of select amount of segments.

Citation for the following function:
Date: 10/07/2025
Based on:
# Source URL: https://canvas.oregonstate.edu/courses/2017605/assignments/10180223?module_item_id=25843602
**/

/* constants */
const float PI = 3.14159265359;

int main(void)
{
/* Declare variables and their types*/
  int segCount;
  int *segCountptr = &segCount;
  float radius;
  float *radiusptr = &radius;
  float ha;
  float *haptr = &ha;
  float hb;
  float *hbptr = &hb;
  float topSurfaceArea;
  float bottomSurfaceArea;
  float lateralSurfaceArea;
  float a;
  float b;
  float height;
  float segmentSurfaceArea;
  float segmentVolume;
  float totalSurfaceArea;
  float totalVolume;
  float averageSurfaceArea;
  float averageVolume;

  do {
    printf("How many spherical segments you want to evaluate [2-10]?\n");
    scanf("%i", &segCount);
  } while (segCount < 2 || segCount > 10);

  /* loop for each segment */
  int i = 1;
  while (i <= segCount) {
    printf("Obtaining data for spherical segment number %d\n", i);
    printf("What is the radius of the sphere (R)?\n");
    scanf("%f", &radius);

    printf("What is the height of the top area of the spherical segment (ha)?\n");
    scanf("%f", &ha);

    printf("What is the height of the bottom area of the spherical segment (hb)?\n");
    scanf("%f", &hb);

    /* print out the data */
    printf("Entered data: R = %.2f ha = %.2f hb = %.2f.\n", *radiusptr, *haptr, *hbptr);

    /* get the height */
    height = *haptr - *hbptr;

    /* validate data */
    if (*radiusptr <= 0 || *haptr <= 0 || *hbptr <= 0 || *haptr > *radiusptr || *hbptr > *radiusptr || height < 0) {
      printf("Invalid Input.\n");
    } else {
      /* all data is valid, increase counter */
      i += 1;

    /* get a (sqrt(R^2 - (ha^2))) */
    a = sqrt((*radiusptr**radiusptr)-(*haptr**haptr));

    /* get b (sqrt(R^2 - (hb^2))) */
    b = sqrt((*radiusptr**radiusptr)-(*hbptr**hbptr));

    /* get Top Surface Area (pi * a^2) */
    topSurfaceArea = PI * (a*a);

    /* get Bottom Surface Area (pi * b^2) */
    bottomSurfaceArea = PI * (b*b);

    /* get Lateral Surface Area (2piRh) */
    lateralSurfaceArea = 2*PI*radius*height;

    /* get total surface area (Top Surface Area + Bottom Surface Area + Lateral Surface Area) */
    segmentSurfaceArea = topSurfaceArea + bottomSurfaceArea + lateralSurfaceArea;

    /* get total volume (1/6 pi h (3a^2 + 3b^2 + h^2)) */
    segmentVolume = (1.0/6.0)*PI*(height*((3*(a*a))+(3*(b*b))+(height*height)));

    printf("Total Surface Area = %.2f Volume = %.2f\n", segmentSurfaceArea, segmentVolume);

    /* add results to totals */
    totalSurfaceArea += segmentSurfaceArea;
    totalVolume += segmentVolume;

    }

  }

    printf("Average Surface Area = %.2f Average Volume = %.2f.\n", totalSurfaceArea/segCount, totalVolume/segCount);

  return 0;
}