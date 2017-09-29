#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Sorter.h"

int main(int argc, char ** argv){

	int file_count = 0;
	char c = 0;
	int i = 0;
	char * str_file = malloc(10);
	

	if(stdin == NULL){
		fprintf(stderr, "ERROR: <File not found>\n");
		return 0;
	}
	
	c = getc(stdin);
	while (c != EOF) {
		//printf("%c\n",c);
		str_file = (char*)realloc(str_file, (i+1) * sizeof(char));	
		str_file[i] = c;
		if(c == '\n'){
			file_count++;
		}
		i++;
		c = getc(stdin);
    }
        
	str_file[i] = '\0';
	//fprintf(stdout, "%s\n", str_file);
	//int avg_str_length = 2 * i / file_count;
	//char * token = malloc(sizeof(char) * avg_str_length);
	
	CSVRow *movies = malloc(file_count * sizeof(CSVRow));
	//token = strtok(str_file, "\n");
	for(int j = 0; j < file_count; j++){
		movies[j].data = malloc(100);
		movies[j].point = j;
		movies[j].string_row = malloc(1000);
	}
	int temp = 0;
	int count = 0;

	for(int j = 0; j < i; j++){
		if(str_file[j] == '\n'){
			//printf("a\n");
			movies[count].string_row = strndup(str_file+temp,j-temp+1);
			temp = j+1;
			count++;
		}
		
	}

	for(int j = 0; j < file_count; j++){
		fprintf(stdout, "%s", movies[j].string_row);
	}

	return 0;
}
