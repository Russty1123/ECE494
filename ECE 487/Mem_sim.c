#include <stdio.h> 
#include <string.h>
#include <math.h>
#include <stdlib.h>

void setup_info();
void query_file_name();
int query_done();
void run_sim();


int mem_info[5];
char file_name[50];

int main(int argc, char *argv[]){
	int done = 0;
	
	printf("Welcome to my memory simulator.");
	
	while(done == 0){
		printf("\nPlease provide the following information to begin simulation.\n\n");
		setup_info();
		query_file_name();
	
		printf("\nInformation received, simulation beginning...\n\n");
		run_sim(mem_info, file_name);
		
		done = query_done();
	}
	printf("Exiting simulator\n");

return 0;	
}

void setup_info(){
	char input = 'x';
	
	printf("Main Memory Size (bytes): ");
	scanf("%d", &mem_info[0]);
	
	printf("Cache Memory Size (bytes): ");
	scanf("%d", &mem_info[1]);
	
	printf("Cache Block/Line Size: ");
	scanf("%d", &mem_info[2]);
	
	scanf("%c", &input);
	input = 'x';
	printf("Degree of set-associativity ('n' for n-way mapping): ");
	scanf("%c", &input);
	if(input == 'n' || input == 'N'){
		mem_info[3] = -1;
	}else{
		mem_info[3] = input - '0';
	}
	
	scanf("%c", &input);
	input = 'x';
	printf("Replacement policy (L = LRU, F = FIFO): ");
	scanf("%c", &input);
	if(input == 'l' || input == 'L'){
		mem_info[4] = 1;
	}else{
		if(input == 'f' || input == 'F'){
			mem_info[4] = 2;
		}
	}

	return;
}

void query_file_name(){
	printf("Input File Name w/ list of memory references: ");
	scanf("%s", &file_name);
	return;
}

int query_done(){	
	char input='x';
	char buffer[50];
	int finished = 0;
	
	printf("\nPlease enter Y to continue or N to quit\n");
	
	while( !(input == 'Y' || input == 'y' || input == 'n' || input == 'N') ){
		input = getchar();
		if( !(input == 'Y' || input == 'y' || input == 'n' || input == 'N' || input == '\n') ){
			printf("\nPlease enter Y to continue or N to quit\n");
		}
	}
	if(input == 'n' || input == 'N') finished = 1;
	gets(buffer);
	
	return finished;
}

void run_sim(){
	
	int num_cm_blk = mem_info[1] / mem_info[2];
	int num_cm_set = num_cm_blk;
	if (mem_info[3] != -1){
		num_cm_blk / mem_info[3];
	}
	int num_mm_blk = mem_info[0] / mem_info[2];
	
	int num_address_lines = log10(mem_info[0]) / log10(2);
	int num_offset = log10(mem_info[2]) / log10(2);
	int num_index = 0;
	if(mem_info[3] != -1){
		num_index = log10(num_cm_set) / log10(2);
	}
	int num_tag = num_address_lines - num_offset - num_index;
	
	printf("Total address lines required = %d\n", num_address_lines);
	printf("Number of bits for offset = %d\n", num_offset);
	printf("Number of bits for index = %d\n", num_index);
	printf("Number of bits for tag = %d\n", num_tag);
	
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
	
	
	
	return;
}





