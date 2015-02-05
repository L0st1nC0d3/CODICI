#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eval(char* expr);

void main()
{
    char* s="       3   120  5  41130     7 -611     3   56   ";
    int v=eval(s);
    printf("Valore massimo: %d.\n",v);
}

int eval(char* expr)
{
    int i=0,j=1,k=0,q=0,max=0,l=strlen(expr),min=0;
    int c=-65534,res=0,mol=1,base=0,r=0,s=0;
    if(expr[0]==' ')
    {
        for(min=0;expr[min]==' ';min++)
        {
            //niente
        }
    }
    if(expr[strlen(expr)-1]==' ')
    {
        for(max=(l-1);expr[max]==' ';max--)
        {
            //niente
        }
    }
    for(i=min;i<=max;i++)
    {
        if(expr[i]==' ')
        {
            j++;                                                        //conto il numero di "parole"
            while(expr[i]==' ')
            {
                i++;
            }
        }
    }
    char** el=malloc(sizeof(char*)*j);              //alloco l'array di stringhe
    for(i=0;i<j;i++)
    {
        for(k=min;k<=max;k++)
        {
            if(expr[k]!=' ')
            {q++;}
            if((expr[k]==' ')&&(expr[k-1]!=' '))
            {
                el[i]=malloc(sizeof(char)*(q+1));                               //alloco le singole stringhe
                q=0;
            }
        }
    }
    k=min;
    q=0;
    i=0;
        for(;k<=max;k++)
        {
            if(expr[k]!=' ')
            {
                el[i][q]=expr[k];
                q++;
            }
            if((expr[k]==' ')&&(expr[k-1]!=' '))                            //associo ad ogni puntatore la stringa
            {
                el[i][q]='\0';                                                                  //termino stringa
                q=0;
                i++;                                                                                //passo al prossimo puntatore
            }
        }
    for(i=0;i<j;i++)
    {
        printf("%s\n",el[i]);                                                                           //visualizzo le stringhe
    }

    //////////////////////////////

    char* n;
    s=j;
    for(i=0;i<(s/2);i++)
    {
       base=el[2*i][0]-'0';
       n=el[(2*i)+1];
       q=strlen(n)-1;
       r=strlen(n);
        if(n[0]!='-')
        {
        res=n[q]-'0';
        for(k=(q-1);k>=0;k--)
        {
            for(j=1;j<=(q-k);j++)
            {
                mol=mol*base;
            }
            res=res+((n[k]-'0')*mol);
            mol=1;
        }
        }
        else if(n[0]=='-')
        {
        res=-(n[r-1]-'0');
        for(k=(r-2);k>0;k--)
        {
            for(j=1;j<(r-k);j++)
            {
                mol=mol*base;
            }
            res=res-((n[k]-'0')*mol);
            mol=1;
        }
        }
        if(res>c)
        {
            c=res;
        }
    }
    return c;
}
