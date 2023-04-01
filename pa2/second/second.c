#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned short get(unsigned short x,int n);

int main (int argc, char* argv[]){

int ones = 0;
int pairs = 0;


unsigned short w = atoi(argv[1]);

unsigned short ptr;
//int tracker = 0;
unsigned short prev = 1;

int truth = 0;

int length = 8*sizeof(unsigned short);
while (length > 0){

	ptr = get(w,0);
//	printf("prev: %u ptr: %u\n", prev, ptr);
	if(truth == 2){
		truth = 0;
	}
	
	if(ptr == 1){
		ones++;
		truth++;
	}

	if(ptr == 0){
		truth = 0;
	}

	w = (w >> 1);

	if(prev == 1 && ptr == 1 && truth == 2){
		pairs++;
//		printf("hit a pair\n");
	}
	prev = ptr;	 
	length--;
	}
	if(ones % 2 == 0){
		printf("Even-Parity\t%d\n", pairs);
	}else {
		printf("Odd-Parity\t%d\n", pairs);
	}
//	printf("%d",pairs);
	
	return 0;
}
unsigned short get (unsigned short x, int n){
	unsigned short p = (x>>n)&1;
	return p;

}
//if pair found x>>2
//if not found x>>1
