#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { TRUE = 1, FALSE = 0 } Boolean;


typedef struct {
    int vehicleNo;
    char laneType;
} Vehicle;


typedef struct node {
    Vehicle vehicle;
    struct node* next, * prev;
} Node;

typedef struct {
    int count;
    Boolean full;
    Node* front;
    Node* rear;
} DeQueue;


void createNode(DeQueue* dq) {
    dq->count = 0;
    dq->full = FALSE;
    dq->rear = dq->front = NULL;
}


Node* createNewNode(int v_no, char l_type) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->vehicle.vehicleNo = v_no;
    newNode->vehicle.laneType = l_type;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


Boolean isEmpty(DeQueue* dq) {
    return dq->front == NULL;
}


void enqueueNormal(DeQueue* normalLane, int v_no) {
    Node* newNode = createNewNode(v_no, 'N');

    if (isEmpty(normalLane)) {
        normalLane->front = newNode;
        normalLane->rear = newNode;
    } else {

        normalLane->rear->next = newNode;
        newNode->prev = normalLane->rear;
        normalLane->rear = newNode;
    }
    normalLane->count++;
    printf("Enqueued Vehicle %d to Normal Lane (End).\n", v_no);
}

void enqueueExpress(DeQueue* expressLane, int v_no) {
    Node* newNode = createNewNode(v_no, 'E');

    if (isEmpty(expressLane)) {
        expressLane->front = newNode;
        expressLane->rear = newNode;
    } else {

        expressLane->front->prev = newNode;
        newNode->next = expressLane->front;
        expressLane->front = newNode;
    }
    expressLane->count++;
    printf("Enqueued Vehicle %d to Express Lane (Front).\n", v_no);
}


void dequeueNormal(DeQueue* normalLane) {
    if (isEmpty(normalLane)) {
        printf("Normal Lane is Empty. Cannot dequeue.\n");
        return;
    }

    Node* temp = normalLane->front;
    int removed_v_no = temp->vehicle.vehicleNo;

    if (normalLane->front == normalLane->rear) {
        normalLane->front = NULL;
        normalLane->rear = NULL;
    } else {
        normalLane->front = normalLane->front->next;
        normalLane->front->prev = NULL;
    }

    free(temp);
    normalLane->count--;
    printf("Dequeued Vehicle %d from Normal Lane (Front).\n", removed_v_no);
}

void dequeueExpress(DeQueue* expressLane) {
    if (isEmpty(expressLane)) {
        printf("Express Lane is Empty. Cannot dequeue.\n");
        return;
    }

    Node* temp = expressLane->rear;
    int removed_v_no = temp->vehicle.vehicleNo;

    if (expressLane->front == expressLane->rear) {

        expressLane->front = NULL;
        expressLane->rear = NULL;
    } else {
        expressLane->rear = expressLane->rear->prev;
        expressLane->rear->next = NULL;
    }

    free(temp);
    expressLane->count--;
    printf("Dequeued Vehicle %d from Express Lane (Rear).\n", removed_v_no);
}

void displayLanes(DeQueue* expressLane, DeQueue* normalLane) {
    Node* current;

    printf("\nExpress Lane\n");
    printf("Queue items -->\n");
    if (isEmpty(expressLane)) {
        printf(" (Empty)\n");
    } else {
        current = expressLane->front;
        while (current != NULL) {
            printf("%d - %c\n", current->vehicle.vehicleNo, current->vehicle.laneType);
            current = current->next;
        }
    }

    printf("\nNormal Lane\n");
    printf("Queue items -->\n");
    if (isEmpty(normalLane)) {
        printf(" (Empty)\n");
    } else {
        current = normalLane->front;
        while (current != NULL) {
            printf("%d - %c\n", current->vehicle.vehicleNo, current->vehicle.laneType);
            current = current->next;
        }
    }
}

int main() {

    DeQueue normalLane, expressLane;
    createNode(&normalLane);
    createNode(&expressLane);

    int choice;
    int v_num;
    char lane_type_char;

    do {
        printf("\nEnter the Selection\n");
        printf("1- Enqueue the Vehicle\n");
        printf("2- Dequeue from Express\n");
        printf("3- Dequeue from Normal\n");
        printf("4- Display\n");
        printf("0- Exit\n");

        printf("> ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -1;
        }

        switch (choice) {
            case 1: {
                printf("Enter Vehicle Number: ");
                scanf("%d", &v_num);
                printf("Enter Lane Type Express-[E]| Normal Lane-[N]: ");

                scanf(" %c", &lane_type_char);

                if (lane_type_char == 'E' || lane_type_char == 'e') {
                    enqueueExpress(&expressLane, v_num);
                } else if (lane_type_char == 'N' || lane_type_char == 'n') {
                    enqueueNormal(&normalLane, v_num);
                } else {
                    printf("Invalid lane type entered.\n");
                }
                break;
            }
            case 2:
                dequeueExpress(&expressLane);
                break;
            case 3:
                dequeueNormal(&normalLane);
                break;
            case 4:
                displayLanes(&expressLane, &normalLane);
                break;
            case 0:
                printf("Exiting Toll Booth System.\n");
                break;
            default:
                printf("Invalid selection. Please try again.\n");
        }
    } while (choice != 0);

    Node *current, *temp;
    current = expressLane.front;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    current = normalLane.front;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}