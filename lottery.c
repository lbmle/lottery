#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h" // 1
#include "show.h" // 2

#define numbersRange 80     /* possibilities */
#define drawRange 5       /* draw possibilities*/
#define maxBetRange 8          /* max bet possibilities*/

//void sort( int [], int );
//void show( int [], int );

main(){
        int drawnBallsArray[drawRange];
        int ballsArray[numbersRange];
        int n,drawnBall,  howManyBet, chosenBet;

     
       initscr();
   //raw();  
//cbreak();
       keypad(stdscr, TRUE);

       printw("L O T T E R Y\n\nPress [Esc] to exit or any other key to continue\n");
       
       srand((unsigned)time(NULL));
       while (getch()!=27)     {
reset:
               for(n=0;n<numbersRange;n++)     ballsArray[n]=0;

               clear();                
               
 while(howManyBet<drawRange || howManyBet>maxBetRange){
clear();
printw("\rHow many numbers to bet? (Min:%d, Max:%d): ",drawRange,maxBetRange);
                       scanw("%d",&howManyBet); }
               
              //clear(); 
               
               for(n=0;n<howManyBet;n++){
			printw("   %d:",n+1);
			scanw(" %d",&chosenBet);
               		--chosenBet;
			if(chosenBet<0 || chosenBet>(numbersRange-1) || ballsArray[chosenBet]){
				--n;
				continue;
			}
			ballsArray[chosenBet]=2;
		}
		printw("Press [Backspace] to cancel or any other key to continue\n");
		howManyBet=0;               //resets variable
		if((char)getch()==7)goto reset;

               
                /* draw */
               for(n=0;n<drawRange;n++)              {
                        do{ /*random 0 to 79*/
                               drawnBall=rand()%numbersRange;
                       }while(ballsArray[drawnBall]%2);
                      /* while not drawn there's a zero at position (0/2=0): break */
                      /*  drawn number: (1%2=1) continue loop do.. while*/
                      /*  match (3%2=1), continue loop do... while*/
                       if (ballsArray[drawnBall]==2)ballsArray[drawnBall]=3;
                       /*if there's a 2, is a bet (2/2=0): break */
                       /*The position is marked with 3: match*/
                       
                     
                      else ballsArray[drawnBall]=1;
                      drawnBallsArray[n]=drawnBall+1;
               }
                       
               sort (drawnBallsArray,drawRange);
                       
               show (ballsArray ,numbersRange);
               printw("Press [Esc] to exit or any other key to continue\n");
                printw("\n\tDrawn numbers:\n\n");
                       attron(COLOR_PAIR(1));          //changes to green
                       for(n = 0; n < drawRange; n++)
                       printw("\t%2d", drawnBallsArray[n]);
                               attroff(COLOR_PAIR(1));//default color
       }
       refresh();
        endwin();
}
