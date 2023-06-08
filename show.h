void show( int balls_array[], int numbers_range){
       int n;
       clear();
       start_color();
    
    init_pair(1,COLOR_GREEN,COLOR_BLACK);
    init_pair(2,COLOR_RED,COLOR_BLACK);
    init_pair(3,COLOR_WHITE,COLOR_BLUE);
    init_pair(4,COLOR_WHITE,COLOR_BLACK); 
    bkgd(COLOR_PAIR(4));  
       
       for(n=0;n<numbers_range;n++)      {
                if(!(n%10))printw("\n\t");  //organize in line of 10          
                if(balls_array[n]==1){   //case drawn
                        attron(COLOR_PAIR(1));   //show in green
                        printw(" %02d",n+1);        
                        attroff(COLOR_PAIR(1));  //default color  
                }
                else if(balls_array[n]==2){  //case  bet
                        attron(COLOR_PAIR(2));    //show in red 
                        printw(" %02d",n+1);
                        attroff(COLOR_PAIR(2)); //default color     
                }
                else if(balls_array[n]==3){ //case match
                        attron(COLOR_PAIR(3));  //show in white with
                        printw(" %02d",n+1);   //blue background
                        attroff(COLOR_PAIR(3));   //default color 
                }
                else  //all the rest     
                printw(" %02d",n+1);       //default color 
       }
       printw("\n");
}
