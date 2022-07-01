#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

struct node
{
    int count;
    char* word;
    struct node *next;
};

int main(int argc,char* argrv[]){

    struct node* x = malloc(10 *sizeof(struct node*));
    struct node* y;

    // x[0].count = 200;
    x[0].word = "Hello";
    printf("%s\n",x[0].word);
    x = (struct node*)realloc(x,20 *sizeof(struct node*));
    x[19].word = "Bye";
    printf("%s\n",x[0].word);
    printf("%s\n",x[19].word);
    // printf("%d",x[0]);
   printf("%ld",sizeof(x));
    return 0;
}