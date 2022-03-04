#ifndef QUEUE_H
#define QUEUE_H

#include<stdbool.h>

#define QUEUE_SUCESS   0
#define QUEUE_ERROR   -1

typedef struct
{
    int *buffer;
    int fidx; // Use for front
    int ridx; // Use for rear
    int size;
    int current_size;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k);
bool myCircularQueueEnQueue(MyCircularQueue *obj, int value);
bool myCircularQueueDeQueue(MyCircularQueue *obj);
int myCircularQueueFront(MyCircularQueue *obj);
int myCircularQueueRear(MyCircularQueue *obj);
bool myCircularQueueIsEmpty(MyCircularQueue *obj);
bool myCircularQueueIsFull(MyCircularQueue *obj);
void myCircularQueueFree(MyCircularQueue *obj);

#endif
