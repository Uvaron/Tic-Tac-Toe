#include <stdio.h>
#include <stdlib.h>

int win_com[3];
int wins [8][3] = {{1,2,3}, {1,4,7}, {1,5,9}, {2,5,8}, {3,5,7}, {3,6,9}, {4,5,6}, {7,8,9}};
char tics[9] = {1,7,4};
int i = 4;
int condition = 0;
int l = 0;
int end = 3;
int result = 0;







int check_third(int first_arr, int length){
	printf("Hello again!");
    for(int k1 = 0; k1 < length; k1++){
        for(int second_arr = 0; second_arr < 3; second_arr++){
            if(tics[k1] == wins[first_arr][second_arr]){
                printf("We checked %d and %d and\n", tics[k1], wins[first_arr][second_arr]);
                wins[first_arr][second_arr] = 0;
                printf("It's a win!\n");
                win_com[2] = tics[k1];
                return 1;
            }
        }
    }
    printf("Found nothing\n");
    return 0;
}

int check_second(int first_arr, int length){
	printf("Hello\n");
	for(int i1 = 0; i1 < length; i1++) {
		for(int second_arr = 0; second_arr < 3; second_arr++) {
			if(tics[i1] == wins[first_arr][second_arr]) {
				wins[first_arr][second_arr] = 0;
				printf("Found");
				printf(" %d\n", tics[i1]);
				printf("Let's check the third\n");
				if(check_third(first_arr, length-1) == 1){
				    printf("We won!\n");
				    return 1;
				}
				else{
				    return 0;
				}
			}
		}
	}
  return 0;
 }


int check_first(int i) {
		for(int j1 = 0; j1 < 8; j1++) {
			for(int j2 = 0; j2 < 3; j2++) {
				if(tics[i-1] == wins[j1][j2]) {
				    printf("Found the array to search\n");
					win_com[0] = tics[i-1];
					wins[j1][j2] = 0;
					if(check_second(j1,i-1) == 1){
					printf("We won!\n");
					    return 1;
					    i = 0;
					}
				}
			}
		}
    
	    return 0;
	
}

int main() {
	if(i >= 3){
	   for(int times = 0; times < i; times++){
	   	check_first(i);
	      if(result == 1) {
		    for(int x = 0; x<3; x++) {
			    printf(" Winning combination is %d\n", win_com[x]);
			}
		  }
		 }
       }
     else{
    printf("Not yet");
	return 0;}
}

