#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eval(char* expr,char* is);
int transf(char* s);

void main()
{
    char* s="9 4 8 345 6 89 5 311 2 701 9 48 7 389";
    char* t="2+2 5 1+1 0 1 2+3 1+1 0+2 6+3 6+0";
    int v=eval(s,t);
    printf("Valore massimo: %d.\n",v);
}

int eval(char* expr, char* is)
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
    char* n;
    s=j;
    int N[s/2];
    for(q=0;q<s/2;q++)
    {
        N[q]=0;
    }
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
        N[i]=res;
    }
    j=1;
    for(i=0;i<strlen(is);i++)
    {
        if(is[i]==' ')
        {
            j++;
        }
    }
    char** indici=malloc(sizeof(char*)*j);
    q=0;
    k=0;
    i=0;
    while(i<j)
    {
        for(;(is[q]!='\0')&&(is[q]!=' ');q++)
        {
            k++;
        }
        indici[i]=malloc((sizeof(char)*k)+1);
        k=0;
        i++;
        q++;
    }
    indici[i++]=malloc((sizeof(char)*k)+1);
    q=0;
    k=0;
    for(i=0;i<j;i++)
    {
        for(;(is[q]!=' ')&&(is[q]!='\0');q++)
        {
            indici[i][k]=is[q];
            k++;
        }
        indici[i][k]='\0';
        k=0;
        q++;
    }
    indici[i][k]='\0';
    int indice=0;
    for(i=0;i<j;i++)
    {
        indice=transf(indici[i]);
        if(indice<s/2)
        {
            res=N[indice];
            printf("Indice: %d , Valore: %d.\n",indice,res);
            if(N[indice]>max)
            {
                max=N[indice];
            }
        }
    }
    return max;
}

int transf(char* s)
{
     int i=0,j=0,ret=0;
    while(s[j]!='\0')
    {
        if(s[j]!='+')
        {
            i=s[j]-'0';
        }
        if(s[j]=='+')
        {
            ret=ret+i;
        }
        j++;
    }
    ret+=i;
    return ret;
}
