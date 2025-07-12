#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int win_com[3];
int wins [8][3] = {{1,2,3}, {1,4,7}, {1,5,9}, {2,5,8}, {3,5,7}, {3,6,9}, {4,5,6}, {7,8,9}};
int wins_c [8][3];
int condition = 0;
int l = 0;
int end = 3;
int result = 0;
char n[9] = {'1','2','3','4','5','6','7','8','9'};
char p[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char tics[9];
char toes[9];
int ch; 
int i = 0;

int table(){
	printf("%c|%c|%c\n",p[0],p[1],p[2]);
	printf("-----\n");
	printf("%c|%c|%c\n",p[3],p[4],p[5]);
	printf("-----\n");
	printf("%c|%c|%c\n",p[6],p[7],p[8]);
	return 0;
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
			if(tics[i1] == wins[first_arr][second_arr]) {
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
				    for(int x1 = 0; x1 < 3; x1++){
				    }
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







int main(){
	printf("Let's play tictactoe!\n");
	printf("\n");
	printf("1|2|3\n");
	printf("-----\n");
	printf("4|5|6\n");
	printf("-----\n");
	printf("7|8|9\n");
	printf("Enter the number where to place you symbol:\n"); 
	
while(condition == 0){
      ch = getc(stdin);
      int number = ch - '0';
      if (number>0 && n[number-1]!=0){
          p[number-1] = 'x';
          tics[i] = number;
          n[number-1] = 0;
          i++;
          table();
          }
       if(i>=3){
        memcpy(wins_c, wins, sizeof(int)*24);
       	condition = check_condition(i);
       	}
      }
   return 0; 
}
