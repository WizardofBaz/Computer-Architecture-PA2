#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned short get (unsigned short x, int n);
unsigned short set (unsigned short x, int n, int v);
unsigned short comp (unsigned short x, int n);

int main(int argc, char *argv[]){

FILE *file1;
file1 = fopen(argv[1], "r");

if(file1 == NULL){
	printf("no data \n");
	return 0;
}
unsigned short x;
fscanf(file1, "%hu\n",&x);
//printf("%hu\n",x);
char * command = malloc(5*sizeof(char));
int arg1; //n
int arg2; //v


while(fscanf(file1,"%s\t%d\t%d",command, &arg1, &arg2)!= EOF){
//	printf("%s %d %d\n", command, arg1, arg2);
//	printf("%d\n",strcmp(command, "get"));
//	printf("%d\n",strcmp(command, "set"));
//	printf("%d\n",strcmp(command, "comp"));


	if(strcmp(command,"get")==0){
		unsigned short p = get(x,arg1);
		printf("%hu\n", p);
//do other 2
}
	if(strcmp(command, "set")==0){
		x =  set(x,arg1,arg2);
		printf("%hu\n", x);
	}

	if(strcmp(command, "comp") == 0){
		x =  comp(x,arg1);	
		printf("%hu\n", x);
	} 
}
free (command);
fclose(file1);
return 0;
	
}


unsigned short get (unsigned short x, int n){
	unsigned short p = (x >> n) & 1;
	return p;
}
//FIX!
unsigned short set (unsigned short x,int n,int v){
	unsigned short z = get(x,n);
	//printf("z is %u\n",z);
	if (z == 0){
		if(v == 0){
			return x;
		}
		if (v == 1){
			//unsigned short y = 1;
			//printf("y is %u\n", y);
			//y = y << n;
			//printf("y is now %u\n", y);
			//x |= y;
			//printf("x is now %u\n", x);
			//return x;
			return comp(x, n);
		}	
	}else {
		if (v == 0){
		//	unsigned short y = -(0);
		//	unsigned short a = -(1 << n);
			//x = x&a;
			//return x;	
			return comp(x,n);	
		}
		if(v == 1){
			return x;
		}	
	}
	//printf("%d",x);
	return 0;
}

unsigned short comp(unsigned short x, int n){
	unsigned short y;
	y = x;
	y ^= (1 << n);
//	y = x;
//	unsigned short p = -(1 << n);
//	y = x & p;
	return y;

}




