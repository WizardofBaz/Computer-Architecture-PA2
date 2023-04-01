#include <stdlib.h>
#include <stdio.h>

unsigned short get (unsigned short x, int n){
	unsigned short p = (x >> n) & 1;
	return p;
}

int main (int argc, char* argv[]){

unsigned short w = atoi(argv[1]);

int p = 0;
while(p <=15){

	if(get(w,p) != get (w,15-p)){
		printf("Not-Palindrome\n");
		return 0;
} else {
}
	p++;
}
	printf("Is-Palindrome\n");


return 0;
}
