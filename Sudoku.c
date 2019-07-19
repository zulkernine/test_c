#include<stdio.h>
#include<stdlib.h>
char m[4][4];

char check();
void init_m();
void p_move();
void dis_m();
void main()
{
    int k=0;
    printf("Let start it.");
    init_m();
    for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++) 
      {
          if(m[i][j]=='\0')
          {
              k++;
          }
      } 
    do
    {
        dis_m();
        p_move();
        check();
        if(k==0) break;

    } while (k!=0);
    check();
    if(!check())
    {
        printf("Game Finished");
    }

}
void init_m()
{   
    extern char m[4][4];
    for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++) 
      {
          m[i][j]=='\0';
      } 
    }
}
void p_move()
{   
    extern char m[4][4];
    int i,j;
    printf("Enter the coordinate:");
    scanf("%d%d",&i,&j);
    printf("\n Enter the value of m[%d][%d]=",i,j);
    while(getchar()!='\n');
    i--,j--;
    scanf("%c",&m[i][j]);
}
void dis_m()
{   
    extern char m[4][4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("\t %c \t",m[i][j]);
        }
        printf("\n");
    }
}

char check()
{
    int k=0,c=0;
    for(int i=0;i<4;i++)
    {
        if(m[i][0]==m[i][1]||m[i][1]==m[i][2]||m[i][1]==m[i][3]||m[i][0]==m[i][2]||m[i][0]==m[i][3]||m[i][2]==m[i][3])
        {
            c++;
        }
    }
    for(int i=0;i<4;i++)
    {
        if(m[0][i]==m[1][i]||m[1][i]==m[2][i]||m[1][i]==m[3][i]||m[0][i]==m[2][i]||m[0][i]==m[3][i]||m[2][i]==m[3][i])
        {
            c++;
        }
    }
    for(int i=0;i<3;i+=2)
    {
        for(int j=0;j<3;j+=2)
        {
            if(m[i][j]==m[i][j+1]||m[i][j]==m[i+1][j]||m[i][j]==m[i+1][j+1]||m[i][j=1]==m[i+1][j+1]||m[i][j+1]==m[i+1][j]||m[i+1][j]==m[i+1][j+1])
            {
                c++;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++) 
      {
          if(m[i][j]=='\0')
          {
              k++;
          }
      } 
    } 
    if(k==0&&c!=0)
    {
        printf("\n Same digit cann't be kept in same row or same column or same 2*2 block");
    }   
    if(k==0&&c==0)
    {
        printf("YOU WIN");
    }
    return k&c;  
}



