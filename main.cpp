#include <iostream>
#include <pthread.h>
using namespace std;

#define NUM_THREADS 5

struct thread_data{
    int thread_id;
    char* msg;
};

void *PrintHello(void *threadId){
    long tid;
    tid = (long)threadId;
    cout << "Hello, ThreadId, " << tid << endl;
    pthread_exit(NULL);
}

void *PrintHello2(void *threadarg){
    struct thread_data *my_data;
    my_data = (struct thread_data *) threadarg;
    cout << "Thread Id : " << my_data->thread_id
         << "\tmsg : " << my_data->msg << endl;
    pthread_exit(NULL);
}

int main()
{
    cout << "Hello World!" << endl;


    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];
    int rc;
    int i;

    for(i=0; i<NUM_THREADS; i++){
        cout << "Main: creating thread, " << i << endl;
        td[i].thread_id = i;
        td[i].msg = "this is a message ";

        rc = pthread_create(&threads[i], NULL, PrintHello2, (void*)&td[i]);
        if(rc){
            cout << "Error: unable to create thread, " << rc;
            return -1;
        }
    }
    pthread_exit(NULL);

    return 0;
}

