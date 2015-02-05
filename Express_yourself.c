#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int eval(char* str);

void main()
{
    int val=0;
    char* s="1-1+10+20-62";
    val=eval(s);
    printf("%d\n",val);
}

int eval(char* str)
{
    int res=0;                                                                         //variabile che conterrà il valore finale
    int i,j,words=1,k=0,l=strlen(str);
    for(i=0;i<=l;i++)
    {
        if((str[i]=='+')||(str[i]=='-'))                                            //conto quanti numeri ci sono
        words++;
    }
    char** expr=malloc(sizeof(char*)*words);                                    //alloco l'array di stringhe, con ogni stringa n° singolo
    j=0;
    for(i=0;i<words;i++)
    {
        for(;((str[j]!='+')&&(str[j]!='-')&&(str[j]!='\0'));j++)
        {
            k++;
        }
        expr[i]=malloc((sizeof(char)*k)+1);                                         //alloco dinamicamente lo spazio per ogni numero
        j++;
        k=0;
    }
    k=0;
    j=0;
    for(i=0;i<words;i++)
    {
        for(;(str[j]!='+')&&(str[j]!='-')&&(str[j]!='\0');j++)
        {
            expr[i][k]=str[j];                                                                              //metto nell'array i singoli numeri
            k++;
        }
        expr[i][k]='\0';
        j++;
        k=0;
    }
    j=1;
    i=0;
    res=res+atoi(expr[0]);                                                                          //converto le stringhe in interi
    while(j<words)                                                                                      //sommo
    {
        if(str[i]=='+')
        {
            res=res+atoi(expr[j]);
            j++;
        }
        else if(str[i]=='-')
        {
            res=res-atoi(expr[j]);
            j++;
        }
        i++;
    }
    return res;                                                                                                   //ritorno il valore desiderato
}
