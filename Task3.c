#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


typedef struct {
    char items[MAX][50];
    int front, rear;
} Queue;


void initialize(Queue *q) {
    q->front = q->rear = -1;
}


int isEmpty(Queue *q) {
    return (q->front == -1);
}

void enqueue(Queue *q, char *value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    strcpy(q->items[++(q->rear)], value);
}

char *dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return NULL;
    }
    char *value = q->items[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return value;
}

void generateBinaryNumbers(int N) {
    Queue q;
    initialize(&q);

    char s1[20], s2[20];

    enqueue(&q, "1");

    printf("First %d Binary Numbers:\n", N);

    for (int i = 1; i <= N; i++) {
        strcpy(s1, dequeue(&q));
        printf("%s ", s1);


        strcpy(s2, s1);
        strcat(s1, "0");
        strcat(s2, "1");

        enqueue(&q, s1);
        enqueue(&q, s2);
    }
    printf("\n");
}

int main() {
    int N;
    printf("Enter how many binary numbers to generate: ");
    scanf("%d", &N);

    generateBinaryNumbers(N);
    return 0;
}

