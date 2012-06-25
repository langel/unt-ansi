#include <stdio.h>

int main( int argc, char *argv[] ) {

	if (argc != 2) {
		printf("usage: %s ansifile\n",argv[0]);
	}
	else {
		FILE *file = fopen(argv[1],"r");
		if (file==0) {
			printf("Error reading ansifile.\n");
		}
		else {
			unsigned int x;
			while ((x=fgetc(file))!=EOF) {
				if (x>127) {
				/*
					Currently only a proof of concept.
					All high (or extended) ascii characters
					are turned into solid blocks.
					The terminal already handles ansi
					escape codes for colors.
				*/
					x = 0xe2;
					printf("%c",x);
					x = 0x96;
					printf("%c",x);
					x = 0x88;
					printf("%c",x);
				}
				else {
					printf("%c",x);
				}
			}
		}
		fclose(file);
		printf("\n");
	}
}
