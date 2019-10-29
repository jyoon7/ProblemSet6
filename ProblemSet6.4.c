#include <stdio.h>
#include <stdlib.h>

const int WIDTH = 600;
const int HEIGHT = 600;
const int RGB = 3;

void flipHorizontal(unsigned char image[WIDTH * HEIGHT * RGB]);

int main(){
    unsigned char image[WIDTH * HEIGHT * RGB];
    FILE *fp;
    if((fp=fopen("Gradient.ppm","r"))==NULL){
        printf("File does not exist or corrupted.\n");
        return 1;
    }

    fscanf(fp,"P3\n600 600\n255\n"); //Skip reading the header file

    //Get colors for each pixel
    unsigned char color;
    for(int x = 0; x < (WIDTH * HEIGHT *RGB); x++){
        fscanf(fp, "%u", &color);
        image[x]= color;
        printf("%i ", image[x]);
    }

    fclose(fp);
    flipHorizontal(image);
    return 0;
    
}

void flipHorizontal(unsigned char image[WIDTH * HEIGHT * RGB]){
    // Create text file in write mode
    FILE *cat = fopen("ReverseGradientPOINTER.ppm", "w");
    // Print header info on to the file
    fprintf(cat, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    // Print each line of image array from top to bottom, left to right
    
    int row = HEIGHT;

    while(row > 0){
        row--;
        int index = row * WIDTH * RGB;
        for(int x = 0; x < (WIDTH * RGB); x++){
            index = index + x;
            fprintf(cat, "%i ", image[index]);
        }
    }
    fclose(cat);
}