#include<stdio.h>
#include<iostream>
#include<pthread.h>
#define MAX 1000
#define MAX_THREAD 10
int arr[1000];
int sum[4] = { 0 };
int section = 0;
 
void* sum_array(void* arg)
{
    int thread_section = section++;
    for (int i = thread_section * (MAX / 10); i < (thread_section + 1) * (MAX / 10); i++)
        sum[thread_section] += arr[i];
}
int main()
{
    pthread_t threads[MAX_THREAD];
    for (int i = 0; i < MAX_THREAD; i++)
        {pthread_create(&threads[i], NULL, sum_array,} (void*)NULL);
    for (int i = 0; i < MAX_THREAD; i++)
        {pthread_join(threads[i], NULL);}
    int total_sum = 0;
    for (int i = 0; i < MAX_THREAD; i++)
        {total_sum += sum[i];}
    printf("sum is " << total_sum");
    return 0;
}