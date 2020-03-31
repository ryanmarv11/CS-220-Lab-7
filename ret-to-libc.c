#include <stdio.h>
#include <stdlib.h>

extern unsigned long *get_ebp();

void ret2libc(int dummy){
	/* TASK 1 : Get the value of ebp. Make use of the getebp function you have previously written. */
	unsigned long *curr_ebp = (unsigned long*) malloc(sizeof(unsigned long)* 4);
	curr_ebp[0] = *get_ebp();
	/* TASK2 : Overwrite written address with address of system. */
	curr_ebp[1] = (unsigned long) &system;
	curr_ebp[2] = curr_ebp[1];

	/* TASK3 : Set up the argument to system as a pointer to string "/bin/bash" */
	char* str = "/bin/bash";
	curr_ebp[3] = *str;

}

int main(){
	ret2libc(0);
	printf("Done!\n");
	return 0;
}