#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main(){

	int precision = 1000000000;
	int *flips = new int[precision];
	srand (time(NULL));

	//Generate 100 random flips
	for(long i=0; i<precision; i++){
		int coinFlip = rand() % 2;  
	
		if(coinFlip == 1){
			flips[i] = 1;
		}else{
			flips[i] = 0;
		}
	}

/*
	for(int i=0; i<100; i++){
		printf("%i",flips[i]);
	}*/


	//Count sequences
	int streakOfOnes = 0;
	int reqInRow = 4;
	int sequences = 0;
	for(long i=0; i< precision; i++){
		if(flips[i] == 1){
			streakOfOnes +=1;
		}else{
			if(streakOfOnes >= reqInRow){
				sequences += 1 + (streakOfOnes - reqInRow);
			}
			streakOfOnes = 0;
		}
	}

	printf("Number of sequences with 4 in row:\n %i \n", sequences);

	//Scale down to 100 flips


}