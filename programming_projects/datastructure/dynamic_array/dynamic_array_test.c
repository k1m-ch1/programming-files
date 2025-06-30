#include <stdio.h>
#include <stdlib.h>
struct Dynamic_a{
    int size;
    int* a;
};

void insert(struct Dynamic_a* array, int x);
struct Dynamic_a* new_array();

int main(void){
     
 

}

struct Dynamic_a* new_array(){
    struct Dynamic_a* temp = (struct Dynamic_a*)malloc(sizeof(struct Dynamic_a));
    (*temp).size = 1;
    (*temp).a = (int*)malloc(sizeof(int));
    *((*temp).a) = NULL;
    return temp;
}

void insert(struct Dynamic_a* array, int x){
    int size_rn = sizeof(int) * (int)(*array).size;
    int* sus = (int*)malloc(size_rn + sizeof(int));
    for (int i = 0; i < (*array).a; i++){
        sus[i] = ((*array).a)[i];
    }
    sus[size_rn + sizeof(int)] = x;
    (*array).size = (*array).size + 1;
    for (int i = 0; i < size_rn/4; i++){
        free((*array).a + i);
    }
    (*array).a = sus;
}
