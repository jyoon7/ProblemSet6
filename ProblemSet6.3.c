#include <stdio.h>
#include <stdlib.h>

const int WIDTH = 600;
const int HEIGHT = 600;
const int RGB = 3;

void flipHorizontal(unsigned char image[WIDTH][HEIGHT][RGB]);

int main(){
    unsigned char image[WIDTH][HEIGHT][RGB];
    unsigned char ctmp;
    int x,y,i;
  
    FILE *fp;
    if((fp=fopen("Gradient.ppm","r"))==NULL){
        printf("File does not exist or corrupted.\n");
        return 1;
    }

    fscanf(fp,"P3\n600 600\n255\n"); //Skip reading the header file

    //Get colors for each pixel
    unsigned int color;
    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            for(int rgb = 0; rgb < RGB; rgb++){
                fscanf(fp, "%u", &color);
                image[x][y][rgb] = color;
            }
        }
    }
    fclose(fp);
    flipHorizontal(image);
    return 0;
}

void flipHorizontal(unsigned char image[WIDTH][HEIGHT][RGB]){
    // Create text file in write mode
    FILE *cat = fopen("ReverseGradient.ppm", "w");
    // Print header info on to the file
    fprintf(cat, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    // Print each line of image array from top to bottom, left to right
    for(int y = 0 ; y < HEIGHT; y++){
		for(int x = WIDTH - 1; x != -1; x--){
			for(int rgb = 0; rgb < RGB; rgb++){
				fprintf(cat, "%i ", image[x][y][rgb]);
            }
        }
    }
    fclose(cat);
}