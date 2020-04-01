#include <stdio.h>
#include <stdlib.h>

extern unsigned long *get_ebp();

void ret2libc(int dummy){
	
	char* str = "/bin/bash";
	unsigned long *curr_ebp = get_ebp();
	unsigned long temp = curr_ebp[1];
	curr_ebp[1] = (unsigned long) &system;
	curr_ebp[3] = (unsigned long)str;
	curr_ebp[2] = temp;
	
	/* TASK 1 : Get the value of ebp. Make use of the getebp function you have previously written. */
	/* TASK2 : Overwrite written address with address of system. */
	/* TASK3 : Set up the argument to system as a pointer to string "/bin/bash" */
}

int main(){
	ret2libc(0);
	printf("Done!\n");
	return 0;
}