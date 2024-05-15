#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    int GxRed, GxGreen, GxBlue, GyRed, GyGreen, GyBlue, GRed, GGreen, GBlue;
    GxRed =GxGreen =GxBlue =GyRed =GyGreen =GyBlue =GRed =GGreen =GBlue =0;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            copy[i][j] = image[i][j];
        }
    }
for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
       for(int x = 0; x < 3; x++){
          for(int y = 0; y < 3; y++){
            int currentX = i + x - 1;
            int currentY = j + y - 1;
            if(currentX < 0 || currentX > height-1 || currentY < 0 || currentY > width-1){
                          continue;
            }

            int midx[] = {-2, 0, 2};
            for(int a = -1; a <= 1; a++){
                GxRed += copy[i-1][currentY].rgbtRed*a;
                GxGreen += copy[i-1][currentY].rgbtGreen*a;
                GxBlue += copy[i-1][currentY].rgbtBlue*a;
            }
            for(int b = midx[0]; b <= midx[2]; b++){
                GxRed += copy[i][currentY].rgbtRed*b;
                GxGreen += copy[i][currentY].rgbtGreen*b;
                GxBlue += copy[i][currentY].rgbtBlue*b;
            }
            for(int c = -1; c <= 1; c++){
                GxRed += copy[i+1][currentY].rgbtRed*c;
                GxGreen += copy[i+1][currentY].rgbtGreen*c;
                GxBlue += copy[i+1][currentY].rgbtBlue*c;
            }

            int midy1[] = {-1, -2, -1};
            int midy2[] = {0, 0, 0};
            int midy3[] = {1, 2, 1};
            for(int a = midy1[0]; a <= midy1[2]; a++){
                GyRed += copy[i-1][currentY].rgbtRed*a;
                GyGreen += copy[i-1][currentY].rgbtGreen*a;
                GyBlue += copy[i-1][currentY].rgbtBlue*a;
            }
            for(int b = midy2[0]; b <= midy2[2]; b++){
                GyRed += copy[i][currentY].rgbtRed*b;
                GyGreen += copy[i][currentY].rgbtGreen*b;
                GyBlue += copy[i][currentY].rgbtBlue*b;
            }
            for(int c = midy3[0]; c <= midy3[2]; c++){
                GyRed += copy[i+1][currentY].rgbtRed*c;
                GyGreen += copy[i+1][currentY].rgbtGreen*c;
                GyBlue += copy[i+1][currentY].rgbtBlue*c;
            }
          }
       }

            GRed = round(sqrt(GxRed*GxRed + GyRed*GyRed));
            GGreen = round(sqrt(GxGreen*GxGreen + GyGreen*GyGreen));
            GBlue = round(sqrt(GxBlue*GxBlue + GyBlue*GyBlue));

                        if(GRed > 255){
                            GRed = 255;
                        }
                        if(GGreen > 255){
                            GGreen = 255;
                        }
                        if(GBlue > 255){
                            GBlue = 255;
                        }
                        copy[i][j].rgbtRed = GRed;
                        copy[i][j].rgbtGreen = GGreen;
                        copy[i][j].rgbtBlue = GBlue;
    }
  }
  for (int i = 0; i< height; i++){
    for(int j = 0; j < width; j++){
         image[i][j].rgbtRed =  copy[i][j].rgbtRed;
         image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
         image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
    }
  }
    return;
}