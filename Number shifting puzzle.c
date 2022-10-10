//PROjECT 1
#include<stdio.h>
#include<time.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

int a[4][4];
int moves=4;
void generatearr()//to generate an array of 4*4 matrix with random values
{
    time_t t1;
    int arr[15];
    for(int i=1;i<=15;++i)
    {
        arr[i]=i;
    }
    srand((unsigned) time (&t1));
    int da[15];
    for(int i=0;i<15;++i)
    {
        int ind=rand()%15+1;
        if(arr[ind]!=-1)
        {
            da[i]=arr[ind];
            arr[ind]=-1;
        }
        else
            i--;
    }
    int index=0;
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {

                a[i][j]=da[index++];
        }
    }
    a[3][3]=0;
}
void show()//to print the array matrix
{
     system("cls");
    int i, j;
     printf(ANSI_COLOR_RED"\n MOVES LEFT: %d\n"ANSI_COLOR_RESET,moves);
    printf("--------------------\n");
    for (i = 0; i < 4; i++)
    {
        printf("|");
        for (j = 0; j < 4; j++)
        {
            if (a[i][j] != 0)
                {
                    printf( ANSI_COLOR_YELLOW"%2d" ANSI_COLOR_RESET, a[i][j]);
                    printf(" | ");
                }
            else
                printf("   | ");
        }
        printf("\n");
    }

    printf("--------------------\n");
}
void swapleft(int x,int y)//to swap the number to left side
{
    int l;
    if(moves==0)
     {
        printf(ANSI_COLOR_RED"OPPS!! YOU ARE OUT OF MOVES\n"ANSI_COLOR_RESET);
         printf(ANSI_COLOR_BLUE"\nPRESS 1 TO RESTART THE GAME OR 0 TO EXIT"ANSI_COLOR_RESET);
        scanf("%d",&l);
        if(l==1)
            start();
        else
            exit(0);
     }
    moves--;
    if(y-1>=0)
    {
    int temp=a[x][y];
    a[x][y]=a[x][y-1];
    a[x][y-1]=temp;
    show();
    }
}
void swapright(int x,int y)//to swap the number to right side
{
     int l;
    if(moves==0)
     {
        printf(ANSI_COLOR_RED"OPPS!! YOU ARE OUT OF MOVES\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE"\nPRESS 1 TO RESTART THE GAME OR 0 TO EXIT"ANSI_COLOR_RESET);
        scanf("%d",&l);
        if(l==1)
            start();
        else
            exit(0);
     }
    moves--;
    if(y+1<4)
    {
    int temp=a[x][y];
    a[x][y]=a[x][y+1];
    a[x][y+1]=temp;
    }
    show();

}
void swapup(int x,int y)//to swap the number to upper side
{
     int l;
    if(moves==0)
     {
        printf(ANSI_COLOR_RED"OPPS!! YOU ARE OUT OF MOVES\n"ANSI_COLOR_RESET);
         printf(ANSI_COLOR_BLUE"\nPRESS 1 TO RESTART THE GAME OR 0 TO EXIT"ANSI_COLOR_RESET);
        scanf("%d",&l);
        if(l==1)
            start();
        else
            exit(0);
     }
    moves--;
    if(x-1>=0)
    {
    int temp=a[x][y];
    a[x][y]=a[x-1][y];
    a[x-1][y]=temp;
    }
    show();
}

void swapdown(int x,int y)//to swap the number to down side
{
     int l;
    if(check() && moves>=0)
        printf("HURRAYY!!! YOU WON...");
    if(moves==0)
     {
        printf(ANSI_COLOR_RED"OPPS!! YOU ARE OUT OF MOVES\n"ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE"\nPRESS 1 TO RESTART THE GAME OR 0 TO EXIT"ANSI_COLOR_RESET);
        scanf("%d",&l);
        if(l==1)
            start();
        else
            exit(0);
     }
    moves--;
    if(x+1<4)
    {
    int temp=a[x][y];
    a[x][y]=a[x+1][y];
    a[x+1][y]=temp;
    }
    show();
}
int readenteredkey()//to take input of arrow key
{
    char ch=_getch();
    if(ch==-32)
        return _getch();
}
int check()//to check for the winning condition
{
    int i=1,flag=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;++j)
        {
           if(a[i][j]!=i++)
                flag++;

        }
    }
    if(flag==0)
        return 1;
    else
        return 0;
}
void win()//winning condition
{
    int ind=1;
    printf(ANSI_COLOR_GREEN"\n\n  Winning situation\n"ANSI_COLOR_RESET);
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            if(ind<16)
                printf(ANSI_COLOR_GREEN" %3d "ANSI_COLOR_RESET,ind++);
        }
        printf("\n");
    }

}
int something()//to collecting index positions of 0 and also calling swap functions
{
    int index1,index2;
    do
    {
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            if(a[i][j]==0)
            {
                 index1=i;
                 index2=j;
                break;
            }
        }
    }
    printf("\n");
    char ch=readenteredkey();
    int k;
    switch(ch)
    {
        case 75:
            swapleft(index1,index2);
            break;
        case 77:
            swapright(index1,index2);
            break;
        case 72:
            swapup(index1,index2);
            break;
        case 80:
            swapdown(index1,index2);
            break;
        case 0:
            exit(0);
            break;
    }

    }while(1);
}

 void start()//starting slide
{

     system("cls");
    moves=4;
    char name[10];
    printf(ANSI_COLOR_GREEN"\t\tMATRIX PUZZLE"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW"\n  ENTER NAME:"ANSI_COLOR_RESET);
    scanf("%s",&name);
    printf(ANSI_COLOR_BLUE"\n\n  Hello  %s "ANSI_COLOR_RESET,name);
    printf(ANSI_COLOR_YELLOW"\n\n  Game Rules :\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW" 1. You can move only 1 step at a time with the arrow key.\
        \n\tMove Up   : by Up arrow key\
        \n\tMove Down : by Down arrow key\
        \n\tMove Left : by Left arrow key\
        \n\tMove Right: by Right arrow key\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW"\n 2. You can move numbers at an empty position only.\n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW"\n 3. For each valid move : your total number of moves will decrease by 1."ANSI_COLOR_RESET);
    win();
    printf(ANSI_COLOR_BLUE"\n\n  Press 1 to play"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_BLUE"\n\n  TO EXIT ANYTIME FROM THE GAME PRESS 0\n HAPPY GAMING..."ANSI_COLOR_RESET);
    int p;
    scanf("%d",&p);
    if(p==1)
    {
    generatearr();
    show();
    something();
    }
    else
    {
        printf("invalid input");
        return ;
    }
}

int main()
{
    start();
    return 0;
}
