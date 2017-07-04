#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0
struct pole{
    bool done;
    bool x;
};
typedef struct pole obszar;
bool sciezka(int x,int y,obszar roz[5][5],int lab[5][5]){
    if((x>4)||(y>4)||(x<0)||(y<0)){
        return false;
    }else if((lab[x][y]==1)||(roz[x][y].done==true)){
        return false;
    }else if(lab[x][y]==2){
        return true;
    }else{
        roz[x][y].done=true;
    }
    if(sciezka(x+1,y,roz,lab)==true){
        roz[x][y].x=true;
        return true;
    }else if(sciezka(x-1,y,roz,lab)==true){
        roz[x][y].x=true;
        return true;
    }else if(sciezka(x,y+1,roz,lab)==true){
       roz[x][y].x=true;
        return true;
    }else if(sciezka(x,y-1,roz,lab)==true){
        roz[x][y].x=true;
        return true;
    }else{
        return false;
    }
}
int main()
{
    int lab[5][5] =   { { 2, 0, 1, 1, 1},
                        { 1, 0, 1, 1, 1},
                        { 1, 0, 0, 0, 1},
                        { 1, 1, 1, 0, 1},
                        { 1, 1, 1, 0, 1},};
    obszar roz[5][5];
    int i,j;
    printf("_______\n");
    for(i=0;i<5;i++){
        printf("|");
        for(j=0;j<5;j++){
            if(lab[i][j]==0){
                printf(" ");
            }
            if(lab[i][j]==1){
                printf("x");
            }
            if(lab[i][j]==2){
                printf("W");
            }
        }
        printf("|\n");
    }
    printf("_______\n");
    sciezka(4,3,roz,lab);
    for(i=0;i<5;i++){
        printf("|");
        for(j=0;j<5;j++){
            if(roz[i][j].x==true){
                printf("x");
            }else printf(".");
        }
        printf("| \n");
    }
    printf("________");
    return 0;
}
