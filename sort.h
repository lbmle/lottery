#define SWITCH(a,b)   { int t; t=a; a=b; b=t; }
/*"buble sort"*/
       /* sort(drawnBallsArray,drawRange) */
void sort( int drawnBalls_array[], int draw_range ){
    int i, x;
    /* sweep array*/
    for(i = 0; i < draw_range; i++) {
               /* switch if bigger than next */                 
        for(x = 1; x < (draw_range-i); x++) {
           if(drawnBalls_array[x-1] > drawnBalls_array[x])
              SWITCH(drawnBalls_array[x-1],drawnBalls_array[x]);
        }
    }
}
