#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            BYTE avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            float originalRed = image[i][j].rgbtRed;
            float originalBlue = image[i][j].rgbtBlue;
            float originalGreen = image[i][j].rgbtGreen;

            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
            if(sepiaRed > 255){
                sepiaRed = 255;
            }
            if(sepiaGreen > 255){
                sepiaGreen = 255;
            }
            if(sepiaBlue > 255){
                sepiaBlue = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width / 2; j++){
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = tmp;
        }
    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
  RGBTRIPLE copy[height][width];
   for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            copy[i][j] = image[i][j];
            int blurRed = round((copy[i][j].rgbtRed + copy[i][j-1].rgbtRed + copy[i][j+1].rgbtRed + copy[i-1][j].rgbtRed
            +copy[i-1][j-1].rgbtRed+ copy[i-1][j+1].rgbtRed+ copy[i+1][j].rgbtRed +copy[i+1][j-1].rgbtRed +copy[i+1][j+1].rgbtRed)/ 9.0);
            int blurGreen = round((copy[i][j].rgbtGreen + copy[i][j-1].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i-1][j].rgbtGreen
            +copy[i-1][j-1].rgbtGreen+ copy[i-1][j+1].rgbtGreen+ copy[i+1][j].rgbtGreen +copy[i+1][j-1].rgbtGreen +copy[i+1][j+1].rgbtGreen)/ 9.0);
            int blurBlue = round((copy[i][j].rgbtBlue + copy[i][j-1].rgbtBlue + copy[i][j+1].rgbtBlue + copy[i-1][j].rgbtBlue
             +copy[i-1][j-1].rgbtBlue+ copy[i-1][j+1].rgbtBlue+ copy[i+1][j].rgbtBlue +copy[i+1][j-1].rgbtBlue +copy[i+1][j+1].rgbtBlue)/ 9.0);

            copy[i][j].rgbtBlue = blurRed;
            copy[i][j].rgbtGreen = blurGreen;
            copy[i][j].rgbtRed = blurBlue;
        }
   }
   image[height][width].rgbtRed = copy [height][width].rgbtRed;
   image[height][width].rgbtGreen = copy [height][width].rgbtGreen;
   image[height][width].rgbtBlue = copy [height][width].rgbtBlue;
    return;
}
