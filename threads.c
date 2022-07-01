#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

struct thread_info{
    pthread_t thread_id;
    int thread_num;
    char    *argv_string;
};

static void * thread_start(void *arg){
    struct thread_info *tinfo = arg;
    // char *uargv;
    // printf("Start: %d\n", getpid());
    // printf("Start Thread: %ld\n", tinfo->thread_id);
    return("Hello");
}





int main(int argc, char* argv[]){
// Thread practice    
pthread_t *thread;
pthread_attr_t attr;
void *res;
int s, num_thread;

num_thread = 2;
s = pthread_attr_init(&attr);
struct thread_info *tinfo = calloc(num_thread,sizeof(*tinfo));

for(int x=0;x<num_thread;x++){
    tinfo[x].thread_num = x + 1;
    tinfo[x].argv_string="Hello ";

    s = pthread_create(&tinfo[x].thread_id,&attr,&thread_start,&tinfo[x]);
}   if(s!=0){
    printf("Error\n");
}
s = pthread_attr_destroy(&attr);
    
  for (int tnum = 0; tnum < num_thread; tnum++) {
               s = pthread_join(tinfo[tnum].thread_id, &res);
               if (s != 0)
                   printf("Error\n");

               printf("Joined with thread %d; returned value was %s\n",
                       tinfo[tnum].thread_num, (char *) res);
            //    free(res);      /* Free memory allocated by thread */
           } 
           free(tinfo)  ;
    return 0;
}