#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* eval(char * val, char * pos);

void main()
{
    char* val="c t g d v u p q s w x c g t a";
    char* pos="1 6 3 7 2 -7 1 0 14";
    char* valmin=eval(val,pos);
    printf("Parola minore: %s\n",valmin);
}

char* eval(char * val, char * pos)
{
    int len=0,len_min=50;
    char* ret;
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
                            len=strlen(elenco[k]);
                            if(len<len_min)
                            {
                                len_min=len;
                                ret=elenco[k];
                                return ret;
                            }
                            else if(len==len_min)
                            {
                                if(strcmp(elenco[k],ret)<0)
                                {
                                    ret=elenco[k];
                                }
                            }
                        }
                   }
               }
               k=atoi(el2[j]);
               if((k<words)&&(k>=0))
               {
                    len=strlen(elenco[k]);
                     if(len<len_min)
                    {
                        len_min=len;
                        ret=elenco[k];
                    }
                    else if(len==len_min)
                            {
                                if(strcmp(elenco[k],ret)<0)
                                {
                                    ret=elenco[k];
                                }
                            }
               }
       }
   return ret;
}
