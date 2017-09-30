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
	char * token = malloc(10);
	int row_position = 0;

	if(stdin == NULL){
		fprintf(stderr, "ERROR: <No Input In STDIN>\n");
		return 0;
	}
	
	if(argv[1] == NULL){
		fprintf(stderr, "ERROR: <Expected -c \"item\">\n");	
		return 0;
	}

	if(argv[1][0] != '-' && argv[1][1] != 'c' && argv[2] == NULL){
		fprintf(stderr, "ERROR: <Expected -c \"item\">\n");
		return 0;
	}
	
	token = strdup(argv[2]);

	//fprintf(stdout, "%s\n", token);	
				
	c = getc(stdin);
	while (c != EOF) {
		//printf("%c\n",c);
		str_file = realloc(str_file, (i+1) * sizeof(char));	
		str_file[i] = c;
		if(c == '\n'){
			file_count++;
		}
		i++;
		c = getc(stdin);
    }
        
	str_file[i] = '\0';
	
	CSVRow *movies = malloc(file_count * sizeof(CSVRow));
	//token = strtok(str_file, "\n");
	
	for(int j = 0; j < file_count; j++){
		movies[j].data = malloc(1000);
		movies[j].point = j;
		movies[j].string_row = malloc(1000);
	}
	int temp = 0;
	int count = 0;
	int index = 0;
	int comma_position_max = 0;
	int p1 = 0;
	int p2 = 0;
	int char_found = 0;
	char * check_token = malloc(1000);
	c = 0;

	for(int j = 0; j < i; j++){
		if(str_file[j] == '\n'){
			//printf("a\n");
			movies[count].string_row = strndup(str_file+temp,j-temp+1);
			if (count == 0){
				c = movies[count].string_row[index];
				for(index = 0; c != '\0' ; index++){
					//fprintf(stdout, "%c\n", c);
					c = movies[count].string_row[index];
					if(c == ','){
						comma_position_max++;
						if(index == p1 || index == p1+1){
							check_token = "NULL";
						}
						else{
							strncpy(check_token, movies[count].string_row+p1,index-p1);
						}
						if(strcmp(check_token,token) == 0){
							char_found = 1;
							//fprintf(stdout, "[%s] , [%s]\n", check_token, token);
							break;
						}
						p1 = index+1;
					}
				}
				if(char_found == 0){
					fprintf(stderr, "ERROR: <Selected item was not found in parameters>\n");
					return 0;
				}
				//fprintf(stdout,"%d : %d\n",char_found , comma_position_max);
				//fprintf(stdout, "[%s] : [%s] \n",token, check_token);
			}

			temp = j+1;
			count++;
		}
	}

	for(int j = 0; j < file_count; j++){
		//fprintf(stdout, "%s", movies[j].string_row);
	}

	return 0;
}
