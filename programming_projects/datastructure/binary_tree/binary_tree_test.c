#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node_queue{
    struct Node* data;
    struct Node_queue* next;
};

struct Node* create_node(int data){
    struct Node* return_element = (struct Node*)malloc(sizeof(struct Node));
    (*return_element).data = data;
    (*return_element).right = (*return_element).left = NULL;
    return return_element;
}

struct Node* insert(struct Node* root, int data){
    if(root == NULL){
        root = create_node(data);
    }
    else if(data <= (*root).data){
        (*root).left = insert((*root).left, data);
    }else{
        (*root).right = insert((*root).right, data);
    }
    return root;
}


void insert_loop(struct Node** root, int data){
    struct Node* temp = *root;
    if(*root == NULL){
        *root = create_node(data);
    }else{
        while(1 == 1){
            if(data <= (*temp).data){
                if((*temp).left == NULL){
                    (*temp).left = create_node(data);
                    return;
                }else{
                    temp = (*temp).left;
                }
            }
            else if(data > (*temp).data){
                if((*temp).right == NULL){
                    (*temp).right = create_node(data);
                    return;
                }else{
                    temp = (*temp).right;
                }
            }

        }

    }
}

void search(struct Node* root, int data){
    if(root == NULL){
        printf("Value not found\n");
    }
    else if((*root).data == data){
        printf("Value found\n");
    }
    else if(data < (*root).data){
        search((*root).left, data);
    }else{
        search((*root).right, data);
    }
}

int find_min(struct Node* root){
    while((*root).left != NULL){
        root = (*root).left;
    }
    return (*root).data;
}

int find_max(struct Node* root){
    while((*root).right != NULL){
        root = (*root).right;
    }
    return (*root).data;
}

int find_min_recursion(struct Node* root){
    if((*root).left == NULL){
        return (*root).data;
    }
    int return_value = find_min_recursion((*root).left);
    return return_value;
}

int find_max_recursion(struct Node* root){
    if((*root).right == NULL){
        return (*root).data;
    }
    int return_value = find_max_recursion((*root).right);
    return return_value;
}

int max_f(int a, int b){
    if(a <= b){
        return b;
    }else{
        return a;
    }
}

int find_height(struct Node* root){
    if(root == NULL){
        return -1;
    }
    int left_height = find_height((*root).left);
    int right_height = find_height((*root).right);
    return max_f(left_height, right_height) + 1;
}

void enqueue(struct Node_queue** head, struct Node_queue** tail, struct Node* data){
    struct Node_queue* new_node = (struct Node_queue*)malloc(sizeof(struct Node_queue));
    (*new_node).data = data;
    (*new_node).next = NULL;
    if(*head == NULL || *tail == NULL){
        *head = *tail = new_node;
    }
    else{
        (*(*head)).next = new_node;
        *head = new_node;
    }
}

struct Node* dequeue(struct Node_queue** head, struct Node_queue** tail){

    if(*head == NULL || *tail == NULL){
        printf("Nothing dequeue\nsomething went wrong\n");
        return NULL;
    }
    else if(*head == *tail){
        struct Node* return_value = (**tail).data;
        free(*tail);
        *head = *tail = NULL;
        return return_value;
    }
    else{
        struct Node* return_value = (**tail).data;
        struct Node_queue* next_ptr = (**tail).next;
        free(*tail);
        *tail = next_ptr;
        return return_value;
    }
}

int print_tree_with_rizz(struct Node* root){
    struct Node_queue* head = NULL;
    struct Node_queue* tail = NULL;
    enqueue(&head, &tail, root);
    int j = 1;
    for(int i = 1; i >-1 ;i++){
        struct Node* temp = dequeue(&head, &tail);
        if(temp != NULL){
            printf("%d, ", (*temp).data);
            j = i;
            if(i%10 == 0){
                printf("\n");
            }
        }else{
            break;
        }
        if((*temp).left != NULL){
            enqueue(&head, &tail, (*temp).left);
        }
        if((*temp).right != NULL){
            enqueue(&head, &tail, (*temp).right);
        }
    }
    return j;
}

void preorder_traversal(struct Node* root){
    if(root == NULL){
        return;
    }
    printf("%d\n", (*root).data);
    preorder_traversal((*root).left);
    preorder_traversal((*root).right);
}

void inorder_traversal(struct Node* root){
    if(root == NULL) return;
    inorder_traversal((*root).left);
    printf("%d\n", (*root).data);
    inorder_traversal((*root).right);
}

void postorder_traversal(struct Node* root){
    if(root == NULL) return;
    postorder_traversal((*root).left);
    postorder_traversal((*root).right);
    printf("%d\n", (*root).data);
}

int is_lesser(struct Node* root, int data){
    if(root == NULL){
        return 1;
    }
    if((*root).data <= data && is_lesser((*root).left, data) == 1 && is_lesser((*root).right, data) == 1){
        return 1;
    }else{
        return 0;
    }
}

int is_greater(struct Node* root, int data){
    if(root == NULL){
        return 1;
    }
    if((*root).data > data && is_greater((*root).left, data) == 1 && is_greater((*root).right, data)){
        return 1;
    }else{
        return 0;
    }
}

int is_search_tree(struct Node* root){
    if(root == NULL){
        return 1;
    }
    int data = (*root).data;
    printf("%d\n", data);
    if(is_lesser((*root).left, data) == 1 && is_greater((*root).right, data) == 1 && is_search_tree((*root).left) && is_search_tree((*root).right)){
        return 1;
    }else{
        return 0;
    }
}

int is_search_tree_fast(struct Node* root, int min, int max){
    if(root == NULL){
        return 1;
    }
    int data = (*root).data;
    printf("%d\n", data);
    if(data >= min && data < max && is_search_tree_fast((*root).left, INT_MIN, (*root).data) == 1 && is_search_tree_fast((*root).right, (*root).data, INT_MAX) == 1){
        return 1;
    }else{
        return 0;
    }
}

int is_search_tree_fast_usable(struct Node* root){
    return is_search_tree_fast(root, INT_MIN, INT_MAX);
}

int is_sorted(struct Node_queue* head){
    struct Node_queue* next_head = (*head).next;
    while(next_head != NULL){
        printf("Comapring %d to %d\n", (*(*head).data).data, (*(*next_head).data).data);
        if((*(*head).data).data > (*((*next_head).data)).data){
            return 0;
        }else{
            head = next_head;
            next_head = (*next_head).next;
        }
    }
    return 1;
}

void inorder_enqueue(struct Node_queue** head, struct Node_queue** tail, struct Node* root){
    if(root == NULL){
        return;
    }
    inorder_enqueue(head, tail, (*root).left);
    enqueue(head, tail, root);
    inorder_enqueue(head, tail, (*root).right);
}

int elements[] = {326, 275, 840, 297, 767, 659, 191, 592, 560, 281, 670, 887, 359, 796, 313, 
259, 799, 130, 732, 175, 928, 347, 565, 875, 491, 609, 748, 62, 282, 131, 
218, 341, 802, 877, 805, 446, 917, 147, 718, 182, 781, 749, 905, 383, 203,
954, 691, 384, 979, 657, 248, 327, 721, 208, 587, 644, 51, 690, 498, 623,
960, 141, 302, 562, 303, 372, 23, 879, 503, 769, 197, 285, 300, 277, 736,
632, 833, 55, 962, 135, 803, 371, 24, 125, 964, 973, 588, 137, 734, 814,
714, 48, 496, 830, 773, 76, 996, 548, 531, 717, 893, 356, 663, 870, 169,
713, 249, 146, 649, 505, 211, 687, 988, 575, 499, 867, 791, 409, 438, 528,
513, 260, 545, 497, 148, 362, 59, 976, 738, 652, 756, 598, 686, 699, 770,
489, 678, 414, 708, 140, 671, 280, 634, 838, 801, 828, 87, 494, 583, 586,
319, 261, 413, 622, 377, 179, 220, 502, 543, 787, 390, 847, 997, 250, 613,
766, 792, 432, 764, 915, 241, 336, 448, 308, 240, 938, 84, 857, 669, 93,
251, 620, 466, 611, 263, 797, 286, 920, 476, 910, 942, 589, 862, 871, 389,
872, 98, 849, 762, 553, 101, 343, 462, 428, 604, 720, 602, 627, 330, 158,
651, 518, 516, 284, 304, 751, 918, 199, 293, 127, 956, 790, 464, 14, 187,
207, 163, 643, 441, 202, 785, 474, 888, 361, 430, 931, 889, 747, 704, 571, 
658, 75, 605, 835, 4, 312, 679, 193, 975, 449, 557, 109, 569, 161, 365,
317, 784, 982, 338, 810, 374, 116, 908, 401, 742, 913, 96, 444, 696, 382,
306, 710, 451, 439, 157, 30, 818, 26, 396, 925, 899, 50, 231, 559, 897, 
447, 334, 778, 783, 719, 533, 123, 437, 5, 8, 626, 95, 15, 621, 145,
607, 519, 855, 664, 556, 901, 821, 819, 353, 936, 727, 866, 514, 534, 961,
117, 56, 181, 926, 911, 808, 159, 257, 633, 196, 424, 352, 624, 558, 121,
832, 728, 224, 595, 929, 104, 701, 655, 827, 793, 469, 546, 490, 294, 195, 
420, 868, 355, 706, 318, 256, 859, 726, 946, 852, 411, 339, 205, 126, 246,
298, 705, 894, 228, 958, 703, 271, 373, 989, 176, 289, 94, 966, 552, 800,
650, 406, 237, 156, 427, 900, 31, 272, 680, 495, 192, 848, 970, 363, 666,
550, 576, 201, 79, 288, 461, 693, 108, 34, 61, 775, 214, 349, 935, 184,
379, 431, 945, 684, 436, 537, 18, 188, 416, 831, 927, 744, 985, 467, 386,
616, 909, 258, 43, 25, 295, 69, 772, 600, 173, 1, 316, 615, 16, 641, 
238, 501, 606, 391, 10, 234, 921, 572, 677, 85, 279, 167, 874, 269, 826,
759, 529, 354, 484, 811, 959, 660, 60, 554, 215, 358, 162, 580, 328, 150,
190, 170, 400, 510, 42, 65, 83, 114, 614, 332, 512, 999, 898, 522, 794,
953, 174, 103, 561, 933, 119, 950, 948, 689, 937, 244, 139, 66, 245, 299,
222, 991, 122, 845, 698, 722, 171, 892, 656, 291, 118, 331, 36, 902, 70,
419, 745, 540, 183, 914, 525, 37, 733, 243, 481, 527, 765, 253, 683, 67, 
795, 822, 368, 610, 577, 434, 394, 392, 454, 232, 2, 155, 825, 951, 345,
200, 854, 483, 967, 882, 324, 758, 217, 993, 807, 998, 405, 64, 320, 813,
239, 771, 407, 591, 99, 89, 640, 972, 480, 254, 385, 273, 564, 563, 593,
266, 105, 58, 850, 397, 57, 54, 276, 172, 233, 723, 884, 102, 873, 415,
860, 351, 124, 932, 323, 344, 128, 41, 283, 290, 422, 752, 292, 844, 268, 
547, 965, 980, 29, 630, 71, 115, 711, 477, 32, 12, 213, 971, 44, 707,
667, 255, 817, 350, 450, 916, 779, 74, 151, 380, 381, 694, 348, 393, 590,
639, 724, 417, 177, 981, 843, 433, 816, 642, 110, 82, 798, 445, 665, 551,
189, 750, 735, 579, 763, 369, 22, 274, 35, 661, 753, 578, 134, 80, 342,
521, 194, 73, 743, 947, 903, 346, 675, 17, 919, 458, 410, 305, 876, 435,
568, 152, 471, 387, 78, 111, 322, 225, 28, 456, 252, 46, 625, 746, 786,
6, 788, 697, 9, 869, 38, 754, 739, 681, 943, 995, 429, 939, 403, 538,
573, 21, 676, 153, 404, 216, 865, 19, 221, 107, 138, 647, 618, 768, 574,
685, 198, 673, 154, 421, 149, 839, 930, 287, 457, 230, 880, 77, 672, 364, 
823, 168, 695, 180, 329, 582, 566, 333, 712, 72, 20, 940, 132, 504, 395,
922, 755, 804, 321, 730, 645, 142, 100, 815, 716, 654, 837, 584, 544, 968,
314, 45, 178, 136, 160, 700, 47, 478, 235, 864, 227, 367, 955, 120, 264,
608, 440, 532, 526, 737, 757, 907, 242, 617, 978, 488, 206, 212, 412, 398,
963, 247, 601, 186, 388, 941, 511, 740, 596, 878, 357, 378, 992, 262, 482,
370, 402, 13, 668, 485, 337, 682, 366, 223, 399, 486, 842, 472, 49, 648,
229, 923, 841, 52, 776, 861, 470, 863, 219, 881, 885, 515, 311, 301, 812,
886, 459, 904, 1000, 994, 267, 636, 549, 88, 858, 315, 774, 112, 493, 335,
425, 912, 599, 674, 709, 789, 890, 81, 829, 824, 541, 629, 144, 423, 688,
307, 166, 806, 53, 637, 475, 278, 509, 715, 90, 638, 612, 164, 468, 567,
851, 761, 969, 702, 555, 86, 646, 628, 265, 990, 106, 3, 984, 520, 506, 
536, 463, 891, 986, 846, 853, 455, 974, 957, 508, 570, 896, 782, 453, 934,
92, 418, 7, 63, 524, 408, 581, 68, 143, 204, 340, 360, 442, 91, 376,
270, 325, 924, 952, 33, 906, 129, 977, 809, 725, 492, 597, 585, 40, 460,
834, 692, 987, 426, 517, 729, 760, 487, 530, 209, 777, 507, 836, 465, 473,
113, 236, 133, 603, 185, 949, 731, 11, 535, 883, 539, 39, 27, 309, 210,
542, 500, 452, 662, 97, 780, 820, 741, 296, 895, 226, 653, 619, 375, 631,
856, 479, 635, 443, 310, 594, 523, 165, 944, 983, 10000 };

/*int main(void){
    struct Node* root = NULL;
    for(int i = 0; i > -1; i++){
        if(elements[i] == 10000){
            break;
        }else{
            root = insert(root, elements[i]);
        }
    }
    int min_value = find_min(root);
    int max_value = find_max(root);
    printf("The minimum value of this tree is %d and the maximum value is %d\n", min_value, max_value);
    int min_value_recursion = find_min_recursion(root);
    int max_value_recursion = find_max_recursion(root);
    printf("\n\nThe minimum value of this tree is %d and the maximum value is %d\n", min_value_recursion, max_value_recursion);
    int height = find_height(root);
    printf("\nThe height of this thang is %d\n", height);
    for(int i = 0; i < 100; i++){
        search(root, i );
    }
}*/

int main(void){
    struct Node* root = NULL;
    for(int i = 0; i > -1; i++){
        if(elements[i] == 10000){
            break;
        }else{
            insert_loop(&root, elements[i]);
        }
    }
    /*struct Node* temp = root;
    while((*temp).left != NULL){
        temp = (*temp).left;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    (*new_node).left = (*new_node).right = NULL;
    (*new_node).data = 100000;
    (*temp).left = new_node;
    if(is_search_tree(root) == 1){
        printf("This is a search tree\n");
    }else{
        printf("This isn't a search tree\n");
    }
    if(is_search_tree_fast_usable(root) == 1){
        printf("This is a search tree\n");
    }else{
        printf("This isn't a search tree\n");
    }
    struct Node_queue* head = NULL;
    struct Node_queue* tail = NULL;
    inorder_enqueue(&head, &tail, root);
    if(is_sorted(tail) == 1){
        printf("This is a search tree\n");
    }else{
        printf("This isn't a search tree\n");
    }*/

}