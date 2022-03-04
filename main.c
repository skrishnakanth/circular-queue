/*
 *  Program showing the usage of the implemented Queue Library
 */

#include <stdio.h>
#include "queue.h"

void main()
{
    MyCircularQueue *q = myCircularQueueCreate(5);
    
    myCircularQueueEnQueue(q, 11);
    myCircularQueueEnQueue(q, 12);
    myCircularQueueEnQueue(q, 31);
    myCircularQueueEnQueue(q, 22);
    myCircularQueueEnQueue(q, 42);

    myCircularQueueDeQueue(q);
    myCircularQueueDeQueue(q);

    printf("Front : %d\n", myCircularQueueFront(q));
    printf("Rear :%d\n", myCircularQueueRear(q));

    myCircularQueueEnQueue(q, 55);
    myCircularQueueEnQueue(q, 99);

    printf("Front : %d\n", myCircularQueueFront(q));
    printf("Rear :%d\n", myCircularQueueRear(q));

    myCircularQueueFree(q);
}
