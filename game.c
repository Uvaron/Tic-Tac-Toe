#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int win_com[3];
int wins [8][3] = {{1,2,3}, {1,4,7}, {1,5,9}, {2,5,8}, {3,5,7}, {3,6,9}, {4,5,6}, {7,8,9}};
int wins_c [8][3] = {{1,2,3}, {1,4,7}, {1,5,9}, {2,5,8}, {3,5,7}, {3,6,9}, {4,5,6}, {7,8,9}};
int wins_a [8][3] = {{1,2,3}, {1,4,7}, {1,5,9}, {2,5,8}, {3,5,7}, {3,6,9}, {4,5,6}, {7,8,9}};
int condition = 0;
int l = 0;
int end = 3;
int result = 0;
int n[9] = {1,2,3,4,5,6,7,8,9};
char p[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char tics[9];
char toes[9] = {0,0,0,0,0,0,0,0,0};
char ch; 
int i = 0;
int N = 10;
int aaa = 0;
int decision;
int where_to_put = 0;
int number = 0;
int stop = 0;

int table(){
	printf(" %c|%c|%c\n",p[0],p[1],p[2]);
	printf(" -----\n");
	printf(" %c|%c|%c\n",p[3],p[4],p[5]);
	printf(" -----\n");
	printf(" %c|%c|%c\n",p[6],p[7],p[8]);
	return 0;
}

int trand(int min, int max, int count) {
    //printf("Random numbers between %d and %d: ", min, max);

    // Taking current time as seed
    unsigned int seed = time(0);

    for (int i = 0; i < count; i++) {
      
        // Generate a random number in the range [min, max]
        int rd_num = rand_r(&seed) % (max - min + 1) + min;
        return(rd_num);
    }
}

int check_third(int first_arr, int length){
    for(int k1 = 0; k1 < length; k1++){
        for(int second_arr = 0; second_arr < 3; second_arr++){
            if(tics[k1] == wins_c[first_arr][second_arr]){
                wins_c[first_arr][second_arr] = 0;
                win_com[2] = tics[k1];
                return 1;
            }
        }
    }
    return 0;
}

int check_second(int first_arr, int length){
 	for(int i1 = 0; i1 < length; i1++) {
		for(int second_arr = 0; second_arr < 3; second_arr++) {
			if(tics[i1] == wins_c[first_arr][second_arr]) {
			    win_com[1] = tics[i1];
				wins_c[first_arr][second_arr] = 0;
				if(check_third(first_arr, length) == 1){
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
				if(tics[i-1] == wins_c[j1][j2]) {
					win_com[0] = tics[i-1];
					wins_c[j1][j2] = 0;
					if(check_second(j1,i) == 1){
					printf("We won!\n");
					    return 1;
					    i = 0;
					}
				}
			}
		}
    
	    return 0;
	
}

int check_condition(int line) {
	printf("Let's check\n");
	while(line>0){
	   	result = check_first(line);
	      if(result == 1) {
		    for(int x = 0; x<3; x++) {
			    printf(" Winning combination is %d\n", win_com[x]);
			}
		      return 1;
		  }
		 line--;
       }
    return 0;
}

int game_com(int arr_len, int number){
	for(int a1 = 0; a1 < 8; a1++){
		for(int a2 = 0; a2 < 3; a2++){
			int b1 = 3-2*a2-1;
			//printf("Let'check all the values %d\n", wins_c[a1][a2]);
			if(wins_c[a1][a2] == 0 && wins_c[a1][a2+1] == 0 && a2 < 2 && wins_c[a1][b1] != 0 && toes[wins[a1][b1]-1] == 0){
				printf("Here are %d and %d and %d\n", a1, b1, wins_c[a1][b1]);
				where_to_put = wins_c[a1][b1];
				toes[wins_c[a1][b1]-1] = where_to_put;
				wins_c[a1][b1] = 0;
				printf("The decision is made for an array with values %d, %d and %d\n", wins_c[a1][a2], wins_c[a1][a2+1], wins_c[a1][b1]);
				printf("Let's see what slots are occupied by the computer");
	for(int toesi = 0; toesi < 9; toesi++){
		printf(" %d\n", toes[toesi]);
	}
	printf("And by the player");
	for(int ticsi = 0; ticsi < 9; ticsi++){
		printf(" %d\n", tics[ticsi]);
	}
				return where_to_put;
			}
			
			else if(wins_c[a1][a2] == 0 && wins_c[a1][a2+2] == 0 && a2 == 0 && wins_c[a1][b1] != 0 && toes[wins[a1][b1]-1] == 0 ){
				where_to_put = wins[a1][a1+1];
				toes[wins_c[a1][b1]-1] = where_to_put;
				wins_c[a1][b1] = 0;
				printf("The decision is made for an array with values %d, %d and %d\n", wins_c[a1][a2], wins_c[a1][a2+1], wins_c[a1][b1]);
				printf("Let's see what slots are occupied by the computer");
	for(int toesi = 0; toesi < 9; toesi++){
		printf(" %d\n", toes[toesi]);
	}
	printf("And by the player");
	for(int ticsi = 0; ticsi < 9; ticsi++){
		printf(" %d\n", tics[ticsi]);
	}

				return where_to_put;
			}
			
		}
	}
	printf("Let's choose it randomly then\n");
	printf("The value right now is %d\n", aaa);
	while(n[aaa] == 0 || aaa == 0 || aaa == number || toes[aaa-1] != 0){
		aaa = trand(1, 9, 9);
		//printf("The value is %d\n", aaa);
	}
	printf("And now the value is %d\n", aaa);
	where_to_put = aaa;
	toes[where_to_put-1] = where_to_put;
	printf("Let's see what slots are occupied by the computer");
	for(int toesi = 0; toesi < 9; toesi++){
		printf(" %d\n", toes[toesi]);
	}
	printf("And by the player");
	n[aaa-1] = 0;
	p[where_to_put-1] = 'o';
    return where_to_put;
}






int main(){
	memcpy(wins_c, wins, sizeof(int)*24);
	memcpy(wins_a, wins, sizeof(int)*24);
	/*for(int a1 = 0; a1 < 8; a1++){
		for(int a2 = 0; a2 < 3; a2++){
			printf("%d\n", wins_c[a1][a2]);
		}
	}*/
	printf("Let's play tictactoe!\n");
	printf("\n");
	printf("1|2|3\n");
	printf("-----\n");
	printf("4|5|6\n");
	printf("-----\n");
	printf("7|8|9\n");
	printf("Enter the number where to place you symbol:\n"); 
	
while(condition == 0){
	  printf("Circle is started or made\n");
	  while(n[number-1] == 0 || number > 9 || number == 0){
       scanf(" %c", &ch);
       number = ch - '0';
       printf("You did a mistake, place again\n");
	  }
      printf("Check the n array before changing it ");
      for(int n1 = 0; n1 < 9; n1++){
          printf("%d\n", n[n1]);
      }
      printf("Checking the array's value %d\n", n[number-1]);
      if (number>0 && n[number-1]!=0){
          p[number-1] = 'x';
          tics[i] = number;
          n[number-1] = 0;

          i++;
          //table();
          printf("Hello and %d!\n", i);
          printf("You have put %c\n",p[number-1]);
          }

        if(i > 3){
       	condition = check_condition(i);
       	if(condition == 1){
       		printf("You won!\n"); 
       		table();
       		return 0;
 
       	}
       	}

        memcpy(wins_c, wins_a, sizeof(int)*24);
        check_condition(i);
       	decision = game_com(i, number)-1;
       	if(decision == 0){
       		return 0;
       	}
       	p[decision] = 'o'; 
       	
       	for(int a1 = 0; a1 < 8; a1++){
       	    printf("Let's check now!\n");
       	    printf("%c, %c, %c\n", p[wins[a1][0]-1], p[wins[a1][1]-1], p[wins[a1][2]-1]);
       	    if(p[wins[a1][0]-1] == 'o' && p[wins[a1][1]-1] == 'o' && p[wins[a1][2]-1] == 'o'){
       	        printf("I have won, haha\n");
       	        table();
       	        return 0;
       	    }
       	}    
       
       	table();
       	memcpy(wins_a, wins_c, sizeof(int)*24);
       	memcpy(wins_c, wins, sizeof(int)*24);
       	
       	
       	/*for(int init = 0; init < 9; init++){
       		printf("%c ", p[init]);
       	}
       	printf("\n");*/
       	stop = 0;
       	printf("Stop is equal to ");
       	for(int x = 0; x < 9; x++){
       	   if(p[x] == 'x' || p[x] == 'o'){
       	       stop++;
       	   }
       	}
       	printf("%d\n", stop);
       	if(stop == 9){
       	    printf("It's a tie!\n");
       	    return 0;
       	}
      }
   return 0; 
}
