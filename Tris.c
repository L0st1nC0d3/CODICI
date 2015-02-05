#include <stdlib.h>
#include <stdio.h>

int vince(int player, int T[3][3]);

void main(int argc, char* argv[])
{
    int TOE[3][3];
    int i=0,j=0,t=1;
    for(;i<3;i++)
    {
	for(;j<3;j++)
	{TOE[i][j]=0;}
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            TOE[i][j]=(*argv[t]-'0');
            t++;
        }
    }
    for(i=0;i<3;i++)
    {
	for(j=0;j<3;j++)
	{
            if(TOE[i][j]==1)
		printf("X");
	    else if(TOE[i][j]==2)
		printf("O");
	    else
		printf(" ");
	}
	printf("\n");
    }
    int R=vince(1,TOE);
    int S=vince(2,TOE);
    if((R+S)>1)
    {
        printf("Pareggio.\n");
    }
}

int vince(int player, int T[3][3])
{
    int q=0,r=0,toe=0;
    for(;q<3;q++)                                           //controllo per righe
    {
        for(;r<3;r++)
        {
            if(T[q][r]==player)
            {
                toe++;
            }
        }
        if(toe==3)
        {
            printf("Il giocatore %d ha vinto!\n",player);
            return 0;
            break;
        }
        else
        {
            toe=0;
        }
    }
    for(q=0;q<3;q++)                                                //controllo per colonne
    {
        for(r=0;r<3;r++)
        {
            if(T[r][q]==player)
            {
                toe++;
            }
        }
        if(toe==3)
        {
            printf("Il giocatore %d ha vinto!\n",player);
            return 0;
            break;
        }
        else
        {
            toe=0;
        }
    }
    for(r=0;r<3;r++)                                //diagonale principale
    {
            if(T[r][r]==player)
            {
                toe++;
            }
    }
    if(toe==3)
        {
            printf("Il giocatore %d ha vinto!\n",player);
            return 0;
        }
    toe=0;
    for(r=2;r>=0;r--)                                       //diagonale secondaria
    {
           if(T[2-r][r]==player)
            {
                toe++;
            }
    }
    if(toe==3)
        {
            printf("Il giocatore %d ha vinto!\n",player);
            return 0;
        }
    if(toe<3)
        return 1;
}
