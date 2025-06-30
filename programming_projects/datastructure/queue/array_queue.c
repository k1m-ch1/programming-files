#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int* queue_data_struct;
    int head;
    int tail;
    int size_of_queue;
};

struct Queue* create_queue(int size_of_queue){
    struct Queue* new_queue = (struct Queue*)malloc(sizeof(struct Queue));
    (*new_queue).queue_data_struct = (int*)malloc(sizeof(int)*size_of_queue);
    (*new_queue).head = -1;
    (*new_queue).tail = -1;
    (*new_queue).size_of_queue = size_of_queue;
    return new_queue;
}

void enqueue(struct Queue* data_structure, int x){
    if((*data_structure).head == -1 & (*data_structure).tail == -1){
        printf("in this thing \n");
        (*data_structure).head = 0;
        (*data_structure).tail =  (*data_structure).head;
        (*data_structure).queue_data_struct[(*data_structure).head] = x;
    }
    else{
        (*data_structure).head = ((*data_structure).head + 1 + (*data_structure).size_of_queue)%(*data_structure).size_of_queue;
        if((*data_structure).head == (*data_structure).tail){
            printf("this thing is full \n");
        }
        else{
            (*data_structure).queue_data_struct[(*data_structure).head] = x;
        }
    }
}

int dequeue(struct Queue* data_structure){
    int return_value;
    if((*data_structure).head == -1 & (*data_structure).tail == -1){
        printf("THERE'S NOTHING TO DEQUEUE\n");
        return_value = NULL;

    }
    else if((*data_structure).head == (*data_structure).tail){
        return_value = (*data_structure).queue_data_struct[(*data_structure).tail];
        (*data_structure).head = -1;
        (*data_structure).tail = -1;
    }
    else{
        return_value = (*data_structure).queue_data_struct[(*data_structure).tail];
        (*data_structure).tail = ((*data_structure).tail + 1 + ((*data_structure).size_of_queue*2))%(*data_structure).size_of_queue;
    }
    return return_value;
}


        

int main(void){
    struct Queue* new_queue = create_queue(10);
    enqueue(new_queue, 12);
    enqueue(new_queue, 100);
    enqueue(new_queue, 20);
    dequeue(new_queue);
    dequeue(new_queue);
    dequeue(new_queue);
    printf("%d", dequeue(new_queue));
    printf("\n%d", dequeue(new_queue));

}