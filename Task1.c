#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int job_array[MAX_SIZE];
    int front;
    int rear;
    int count;
} Deque;


void initializeDeque(Deque* dq) {
    dq->front = -1;
    dq->rear = 0;
    dq->count = 0;
}


int isFull(Deque* dq) {
    return dq->count == MAX_SIZE;
}


int isEmpty(Deque* dq) {
    return dq->count == 0;
}


void insertRear(Deque* dq, int job_num) {
    if (isFull(dq)) {
        printf("Deque is Full. Cannot add more jobs.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {

        dq->rear = (dq->rear + 1) % MAX_SIZE;
    }

    dq->job_array[dq->rear] = job_num;
    dq->count++;
    printf("Added Job %d to the rear.\n", job_num);
}

void insertFront(Deque* dq, int job_num) {
    if (isFull(dq)) {
        printf("Deque is Full. Cannot add more jobs.\n");
        return;
    }

    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {

        dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    }

    dq->job_array[dq->front] = job_num;
    dq->count++;
    printf("Added Job %d to the front.\n", job_num);
}
void deleteFront(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is Empty. Cannot remove from front.\n");
        return;
    }

    int removed_job = dq->job_array[dq->front];
    printf("Removed Job %d\n", removed_job);

    if (dq->front == dq->rear) {

        dq->front = -1;
        dq->rear = -1;
    } else {

        dq->front = (dq->front + 1) % MAX_SIZE;
    }
    dq->count--;
}

void deleteRear(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is Empty. Cannot remove from rear.\n");
        return;
    }

    int removed_job = dq->job_array[dq->rear];
    printf("Removed Job %d\n", removed_job);

    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {

        dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    dq->count--;
}
void display(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Available jobs: (Empty)\n");
        return;
    }

    printf("Available jobs: ");
    int i = dq->front;
    int count = 0;


    while (count < dq->count) {
        printf("%d", dq->job_array[i]);
        i = (i + 1) % MAX_SIZE;
        count++;
    }
    printf("\n");
}


int main() {
    Deque job_deque;
    initializeDeque(&job_deque);
    int choice, job_num;


    insertFront(&job_deque, 8);
    insertRear(&job_deque, 5);

    do {
        printf("\nEnter the Selection\n");
        printf("1- Add job to front\n");
        printf("2- Add job to rear\n");
        printf("3- Remove job front\n");
        printf("4- Remove job rear\n");
        printf("5- Display\n");
        printf("0 to exit\n");

        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Job Number : ");
                scanf("%d", &job_num);
                insertFront(&job_deque, job_num);
                break;
            case 2:
                printf("Enter Job Number : ");
                scanf("%d", &job_num);
                insertRear(&job_deque, job_num);
                break;
            case 3:
                deleteFront(&job_deque);
                break;
            case 4:
                deleteRear(&job_deque);
                break;
            case 5:
                display(&job_deque);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
