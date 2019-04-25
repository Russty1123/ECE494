#include <stdio.h> 
#include <string.h>
#include <math.h>
#include <stdlib.h>

char file_name[50] = "input_file1.txt";

int main(){
	FILE *fp;
	fp = fopen(file_name, "r");
	
	printf("we opened the file\n");
	
	int num_mem_ref = 0;
	fscanf(fp, "%d", &num_mem_ref);
	
	printf("num_mem_ref is %d\n", num_mem_ref);
	
	char cr[4];
	fscanf(fp, "%s", &cr);
	
	printf("char cr is %s\n", cr);
	
	char read_write[num_mem_ref];
	int mem_location[num_mem_ref];
	int count = 0;
	
	while( count < num_mem_ref ){
		fscanf(fp, "%c", &read_write[count]);
		fscanf(fp, "%d", &mem_location[count]);
		
		printf("\nread_write[%d] is %c\n", count, read_write[count]); 
		printf("\nread_write[%d] is %d\n", count, mem_location[count]); 
		
		count = count = 1;
	}
	
	fclose(fp);
	
	return 0;
}