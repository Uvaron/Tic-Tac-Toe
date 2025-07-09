#include <stdio.h>

char p[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

char tics[5];
char toes[5];

int ch; 


int i = 0;

int table(){
	printf("%c|%c|%c\n",p[0],p[1],p[2]);
	printf("-----\n");
	printf("%c|%c|%c\n",p[3],p[4],p[5]);
	printf("-----\n");
	printf("%c|%c|%c\n",p[6],p[7],p[8]);
}


int main(){
	printf("Let's play tictactoe!\n");
	printf("\n");
	printf("%c|%c|%c\n",p[0],p[1],p[2]);
	printf("-----\n");
	printf("%c|%c|%c\n",p[3],p[4],p[5]);
	printf("-----\n");
	printf("%c|%c|%c\n",p[6],p[7],p[8]);
	
	

printf("Enter the number where to place you symbol:\n"); 
ch = getc(stdin);
int number = ch - '0';
if (number>0 && number<10){
}
  char tics[i] = p[number-1];
  i++;
  p[number-1] = 'x';
}
}
