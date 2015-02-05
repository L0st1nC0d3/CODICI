#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int eval(char * val, char * pos);

void main()
{
    char* val="674 408 -1 1360 352";
    char* pos="0 3 7 1 1";
    int valmin=eval(val,pos);
    printf("Valore minimo: %d\n",valmin);
}

int eval(char * val, char * pos)
{
    int res_min=65535;
    int i,j,k=0,words=1,w2=1,val5=0;
    for(i=0;val[i]!='\0';i++)
    {
        if(val[i]==' ')
            words++;
    }
    char** elenco=malloc(sizeof(char*)*words);
    j=0;
    for(i=0;i<words;i++)
    {
        for(;(val[j]!=' ')&&(val[j]!='\0');j++)
        {
            k++;
        }
        elenco[i]=malloc((sizeof(char)*k)+1);
        j++;
        k=0;
    }
     k=0;
    j=0;
    for(i=0;i<words;i++)
    {
        for(;(val[j]!=' ')&&(val[j]!='\0');j++)
        {
            elenco[i][k]=val[j];
            k++;
        }
        elenco[i][k]='\0';
        j++;
        k=0;
    }
    //////////////////////////////////////
    k=0;
    for(i=0;pos[i]!='\0';i++)
    {
        if(pos[i]==' ')
            w2++;
    }
    char** el2=malloc(sizeof(char*)*w2);
    j=0;
    for(i=0;i<w2;i++)
    {
        for(;(pos[j]!=' ')&&(pos[j]!='\0');j++)
        {
            k++;
        }
        el2[i]=malloc((sizeof(char)*k)+1);
        j++;
        k=0;
    }
     k=0;
    j=0;
    for(i=0;i<w2;i++)
    {
        for(;(pos[j]!=' ')&&(pos[j]!='\0');j++)
        {
            el2[i][k]=pos[j];
            k++;
        }
        el2[i][k]='\0';
        j++;
        k=0;
    }
       for(j=0;j<w2;j++)
       {
               if(w2==1)
               {
                   for(i=0;i<words;i++)
                   {
                       k=atoi(el2[i]);
                       if((k<words)&&(k>=0))
                        {
                            val5=atoi(elenco[k]);
                            if(val5<res_min)
                            {
                                res_min=val5;
                                return res_min;
                            }
                        }
                   }
               }
               k=atoi(el2[j]);
               if((k<words)&&(k>=0))
               {
                    val5=atoi(elenco[k]);
                    printf("%d , %d\n",k,val5);
                     if(val5<res_min)
                    {
                        res_min=val5;
                    }
               }
       }
   return res_min;
}
