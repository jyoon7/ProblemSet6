#include <stdio.h>

const int WIDTH = 100;
const int HEIGHT = 100;
const int RGB = 3;

	int main(){
	unsigned char image[WIDTH][HEIGHT][RGB];
	// Open a text file in write mode
	FILE *fp = fopen("MagentaPixels.ppm","w");
	// Write the header information
	fprintf(fp, "P3\n%d %d\n255\n", WIDTH, HEIGHT); 
	
	// Generate MAGENTA pixels by going through 
	// each pixels and colors within pixels
	for(int x = 0; x < WIDTH; x++){
		for(int y = 0; y < HEIGHT; y++){
			for(int rgb = 0; rgb < RGB; rgb++){ // Set each pixel to 255 0 255
				if(rgb == 1){
					image[x][y][rgb] = 0x00; 
				}
				else{
					image[x][y][rgb] = 0xff;
				}
			}
		}
	}
		// Write out individual pixels to the file
	for(int x = 0; x < WIDTH; x++){
		for(int y = 0; y < HEIGHT; y++){
			for(int rgb = 0; rgb < RGB; rgb++){
				fprintf(fp, "%i ", image[x][y][rgb]);
			}
		}
	}
	
	fclose(fp); // Close the file
	return 0;
	}