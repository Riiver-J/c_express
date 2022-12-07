#include <stdio.h>
#include <string.h>

void sort_strings(char*s[],int size);

int main(void)
{
    int i;
    char* s[3] = {"mycopy","src","dst"};

    sort_strings(s,3);

    for(i=0;i<3;i++)
        printf("%s\n",s[i]);

    return 0;
}

void sort_strings(char* list[],int size)
{
    int i,j,least;
    char* temp;

    for(i=0;i<size-1;i++)
    {
        least=i;
        for(j=i+1;j<size;j++)
            if(strcmp(list[j],list[least])<0)
                least = j;
        temp = list[i];
        list[i] = list[least];
        list[least] = temp;
    }
}