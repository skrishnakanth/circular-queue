/*
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out)
 principle and the last position is connected back to the first position to make a circle.
It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full,
we cannot insert the next element even if there is a space in front of the queue.
But using the circular queue, we can use the space to store new values.

Implementation the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language.



Example 1:

Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]

Explanation
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4


Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.

*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

/* Enable  debug output */
//#define DEBUG

void print_queue_info(const char *str, const char *func_name, MyCircularQueue *obj)
{
#ifdef DEBUG
    printf("%s : %s\n", str, func_name);
    printf("fidx : %d\n", obj->fidx);
    printf("ridx : %d\n", obj->ridx);
    for (int i = 0; i < obj->size; i++)
        printf("[%d]: %d, ", i, obj->buffer[i]);
    printf("\ncurrent size : %d \n", obj->current_size);
    printf("--------------\n");
#endif
}



/* Creation & Initialization of Queue */

MyCircularQueue *myCircularQueueCreate(int k)
{
    MyCircularQueue *queue = malloc(sizeof(MyCircularQueue));
    queue->buffer = malloc(k * sizeof(int));
    queue->size = k;
    queue->fidx = 0;
    queue->ridx = -1;
    queue->current_size = 0;
}


/* Add single value (int) to queue */
bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
    print_queue_info("before", __func__, obj);

    if (myCircularQueueIsFull(obj) == true)
    {
        return false;
    }

    if (obj->ridx == obj->size - 1)
    {
        obj->ridx = -1;
    }

    obj->ridx++;
    obj->buffer[obj->ridx] = value;

    if (obj->current_size != (obj->size))
    {
        obj->current_size++;
    }

    print_queue_info("after", __func__, obj);

    return true;
}


/* Remove single value from queue*/
bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
    print_queue_info("before", __func__, obj);
    if (myCircularQueueIsEmpty(obj) == true)
    {
        return false;
    }
    if ((obj->fidx) >= obj->size - 1)
    {
        obj->fidx = -1;
    }
    obj->fidx++;
    obj->current_size--;
    print_queue_info("after", __func__, obj);
    return true;
}

/* Return oldest element in queue */
int myCircularQueueFront(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj) == true)
    {
        return QUEUE_ERROR;
    }
    else
    {
        return obj->buffer[obj->fidx];
    }
}

/* Return newest element in queue */

int myCircularQueueRear(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj) == true)
    {
        return QUEUE_ERROR;
    }
    else
    {
        return obj->buffer[obj->ridx];
    }
}


/* Check if Queue is empty */
bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
    if (obj->current_size == 0)
    {
        return true;
    }
    else
        return false;
}

/* Check if Queue is full */
bool myCircularQueueIsFull(MyCircularQueue *obj)
{
    if (obj->current_size == obj->size)
    {
        return true;
    }
    else
        return false;
}


/* De-initialize & Free  queue */
void myCircularQueueFree(MyCircularQueue *obj)
{
    obj->size = 0;
    obj->fidx = 0;
    obj->ridx = 0;
    obj->current_size = 0;
    free(obj->buffer);
    free(obj);
    
}
