#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


long precision = 10000000;
int flipsPerTime = 100;

int *flips = new int[100];
int *results = new int[precision];

int doFlipSequence();

int main(){

	srand (time(NULL));


	//Do precision no. of flip sequences of length "flipsPerTime"
	for(int b=0; b < precision; b++){
		results[b] = doFlipSequence();
	}

	//Calc the average
	double average = 0;
	for(int b = 0; b < precision; b++){
		average += results[b];
	}
	average = (double) average/precision;

	printf("Expected amounts appearing: %f\n", average);
}

int doFlipSequence(){
	//Generate "flipsPerTime" no. of random flips
	for(long i=0; i < flipsPerTime; i++){
		int coinFlip = rand() % 2;  
	
		if(coinFlip == 1){
			flips[i] = 1;
		}else{
			flips[i] = 0;
		}
	}

	int sequences = 0;
	for(long i = 0; i < flipsPerTime-3; i++){
		//Enter sequence to test here
		if(flips[i] == 1 && flips[i+1] == 0 && flips[i+2] == 1 && flips[i+3] == 0){
			sequences++;
		}
	}
	return sequences;
}