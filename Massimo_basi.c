#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eval(char* expr);

void main()
{
    char* s="               9               4             8          345             ";
    int v=eval(s);
    printf("Valore massimo: %d.\n",v);
}

int eval(char* expr)
{
    int i=0,j=1,k=0,q=0,l=strlen(expr),min=0,max_1=(l-1);
    int max=-65534,res=0,mol=1,base=0,r=0,s=0;
    if(expr[0]==' ')
    {
        for(min=0;expr[min]==' ';min++)
        {
            //niente
        }
    }
    if(expr[strlen(expr)-1]==' ')
    {
        for(max_1=(l-1);expr[max_1]==' ';max_1--)
        {
            //niente
        }
    }
    for(i=min;i<=max_1;i++)
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
    k=min;
    i=0;
    for(;k<=max_1;k++)
    {
        if(expr[k]!=' ')
        {q++;}
        if((expr[k]==' ')&&(expr[k-1]!=' '))
        {
            el[i]=malloc((sizeof(char)*q)+1);                               //alloco le singole stringhe
            q=0;
            while(expr[k]==' ')
            {
                k++;
            }
            k--;
            if(i<j)
            {i++;}
        }
    }
    el[i]=malloc((sizeof(char)*q)+1);
    k=min;
    q=0;
    i=0;
    for(;k<=max_1;k++)
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
            while(expr[k]==' ')
            {
                k++;
            }
            k--;
            if(i<j)
            {i++;}
        }
    }
    el[i][q]='\0';
    for(i=0;i<j;i++)
    {
        printf("%s\n",el[i]);
    }
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
        if(res>max)
        {
            max=res;
        }
    }
    return max;
}
