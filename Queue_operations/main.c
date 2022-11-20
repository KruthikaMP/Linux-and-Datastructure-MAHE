#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define CAPACITY 100

int queue[CAPACITY];
unsigned int size  = 0;
unsigned int rear  = CAPACITY - 1;   // Initally assumed that rear is at end
unsigned int front = 0;

/* Function declaration for various operations on queue */
int enqueue(int data);
int dequeue();
int isFull();
int isEmpty();
int getRear();
int getFront();
void display();

int main()
{
    int ch, data;

    while (1)
    {
        /* Queue menu */
        printf("--------------------------------------\n");
        printf("  QUEUE ARRAY IMPLEMENTATION PROGRAM  \n");
        printf("--------------------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Size\n");
        printf("4. Get Rear\n");
        printf("5. Get Front\n");
        printf("6. Display\n");
        printf("0. Exit\n");
        printf("--------------------------------------\n");
        printf("Select an option: ");

        scanf("%d", &ch);


        /* Menu control switch */
        switch (ch)
        {
            case 1:
                printf("\nEnter data to enqueue: ");
                scanf("%d", &data);

                if (enqueue(data))
                    printf("Element added to queue.");
                else
                    printf("Queue is full.");

                break;

            case 2:
                data = dequeue();

                if (data == INT_MIN)
                    printf("Queue is empty.");
                else
                    printf("Data => %d", data);

                break;

            case 3:


                if (isEmpty())
                    printf("Queue is empty.");
                else
                    printf("Queue size => %d", size);

                break;

            case 4:

                if (isEmpty())
                    printf("Queue is empty.");
                else
                    printf("Rear => %d", getRear());

                break;

            case 5:

                if (isEmpty())
                    printf("Queue is empty.");
                else
                    printf("Front => %d", getFront());

                break;
            case 6:

                if (isEmpty())
                    printf("Queue is empty.");
                else
                    display();

                break;

            case 0:
                printf("Exiting from app.\n");
                exit(0);

            default:
                printf("Invalid choice, please input number between (0-5).");
                break;
        }

        printf("\n\n");
    }
}



/**
 * Enqueue/Insert an element to the queue.
 */
int enqueue(int data)
{
    if (isFull())
    {
        return 0;
    }

    rear = (rear + 1) % CAPACITY;

    size++;

    queue[rear] = data;

    return 1;
}

int dequeue()
{
    int data = INT_MIN;

    if (isEmpty())
    {
        return INT_MIN;
    }

    data = queue[front];

    front = (front + 1) % CAPACITY;

    size--;

    return data;
}

int isFull()
{
    return (size == CAPACITY);
}

int isEmpty()
{
    return (size == 0);
}

int getFront()
{
    return (isEmpty())
            ? INT_MIN
            : queue[front];
}


int getRear()
{
    return (isEmpty())
            ? INT_MIN
            : queue[rear];
}
void display()
{
int i;
if(front == - 1)
printf("Queue is empty \n");
else
{
printf("Queue is : \n");
for(i = front; i <= rear; i++)
printf("%d ", queue[i]);
printf("\n");
}
}
