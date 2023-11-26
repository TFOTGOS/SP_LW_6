#include <bits/stdc++.h>
using namespace std;

pthread_t tid[2];
int counter = 0;
int cnt = 0;
pthread_mutex_t lok;

void* trythis(void* arg)
{
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d has started\n", counter);

    for(i = 0; i < 250000; i++)
    {
        cnt++;
    }

    printf("\n Job %d has started\n", counter);
    return NULL;
}

int main(void)
{
    int i = 0;
    int er;
    while(i < 2)
    {
        er = pthread_create(&(tid[i]), NULL, &trythis, NULL);
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lok);
    printf("\nTotal sum = %d\n", cnt);
    return 0;
}