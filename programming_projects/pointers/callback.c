#include <stdio.h>
#include <time.h>


int ascending_order(int a, int b){
    if (a > b){
        return 1;
    }else{
        return 0;
    }
}

int decending_order(int a, int b){
    if (a < b){
        return 1;
    }else{
        return 0;
    }
}

void bubble_sort(int (*compare)(int,int), int* array_of_numbers, int size){
    int repeat = 1;
    while (repeat == 1){
        for (int i = 0; i < size - 1; i++){
            while (compare(array_of_numbers[i],array_of_numbers[i+1]) == 1 ){
                int temp = array_of_numbers[i];
                array_of_numbers[i] = array_of_numbers[i+1];
                array_of_numbers[i+1] = temp;
            }
        }
        for (int j = 0; j < size - 1; j++){
            if (compare(array_of_numbers[j],array_of_numbers[j+1]) == 0 & j == size - 2){
                repeat = 0;
            }
            if(compare(array_of_numbers[j],array_of_numbers[j+1]) == 1){
                repeat = 1;
                break;
            }
        }
    }
}



int main(void){
    clock_t begin_t;
    clock_t end_t;
    begin_t = clock();
    int size_of_input = 1000;

    int numbers[] = {78, 282, 916, 689, 788, 575, 753, 829, 981, 428, 529, 931, 744, 722, 443, 
    64, 155, 142, 993, 261, 160, 686, 379, 549, 480, 416, 551, 324, 651, 903, 
    805, 677, 132, 484, 40, 726, 720, 773, 710, 419, 743, 978, 123, 491, 402,
    778, 315, 771, 114, 248, 238, 396, 509, 319, 577, 964, 809, 762, 876, 218,
    887, 367, 511, 353, 898, 849, 992, 977, 501, 693, 847, 611, 278, 266, 871,
    921, 262, 874, 585, 699, 137, 827, 683, 784, 173, 914, 667, 489, 94, 922,
    302, 807, 394, 508, 433, 22, 342, 617, 973, 58, 631, 486, 338, 904, 561,
    134, 608, 391, 143, 30, 339, 431, 487, 343, 764, 420, 128, 643, 528, 437,
    479, 785, 642, 889, 789, 503, 826, 659, 550, 956, 29, 541, 56, 985, 75,
    427, 93, 298, 117, 53, 930, 25, 919, 621, 656, 415, 285, 88, 204, 536,
    272, 33, 76, 180, 695, 251, 797, 701, 382, 390, 95, 377, 41, 638, 622,
    997, 335, 795, 603, 586, 410, 945, 504, 678, 85, 568, 366, 556, 545, 476,
    301, 613, 105, 857, 932, 706, 432, 853, 774, 892, 712, 810, 655, 49, 525,
    90, 374, 924, 323, 816, 445, 188, 176, 463, 628, 782, 610, 82, 960, 852,
    941, 321, 171, 284, 760, 733, 761, 38, 274, 450, 820, 775, 682, 351, 331,
    202, 730, 560, 162, 616, 206, 376, 159, 523, 944, 793, 170, 240, 590, 496,
    514, 728, 750, 231, 232, 594, 141, 855, 801, 157, 745, 350, 958, 304, 763,
    548, 897, 384, 614, 840, 32, 124, 700, 739, 139, 606, 521, 181, 97, 665,
    446, 453, 441, 841, 527, 264, 208, 270, 190, 599, 943, 4, 152, 766, 221,
    965, 835, 168, 787, 349, 974, 619, 800, 154, 408, 859, 347, 952, 983, 469, 
    661, 794, 754, 473, 348, 332, 187, 381, 732, 318, 751, 426, 370, 670, 759,
    138, 776, 144, 572, 567, 576, 954, 635, 715, 89, 664, 230, 607, 645, 404,
    885, 263, 741, 5, 982, 505, 119, 81, 492, 630, 959, 468, 604, 895, 191,
    55, 241, 122, 229, 422, 73, 804, 54, 10, 175, 510, 806, 424, 709, 602,
    731, 863, 103, 905, 359, 185, 893, 902, 125, 439, 199, 165, 671, 704, 50,
    2, 584, 309, 890, 539, 110, 817, 267, 225, 253, 71, 899, 555, 106, 256,
    299, 198, 918, 317, 169, 991, 333, 118, 729, 464, 970, 20, 184, 277, 80,
    862, 968, 721, 650, 637, 815, 194, 798, 963, 955, 15, 573, 104, 537, 459,
    286, 182, 843, 149, 735, 102, 813, 63, 276, 444, 976, 52, 361, 368, 26,
    12, 11, 780, 371, 660, 133, 747, 520, 306, 909, 605, 705, 598, 790, 765,
    130, 935, 652, 912, 296, 953, 460, 212, 252, 418, 530, 337, 430, 288, 293,
    596, 636, 482, 44, 17, 115, 151, 836, 153, 559, 258, 136, 821, 346, 344,
    856, 834, 581, 454, 398, 403, 579, 927, 322, 703, 356, 609, 399, 389, 532,
    475, 986, 99, 101, 70, 378, 740, 565, 195, 19, 860, 620, 259, 779, 648,
    200, 522, 485, 737, 873, 830, 879, 31, 287, 327, 702, 281, 66, 354, 37,
    647, 271, 383, 405, 591, 818, 822, 654, 832, 861, 308, 723, 734, 777, 823,
    243, 570, 215, 148, 691, 979, 488, 811, 920, 310, 3, 57, 98, 865, 708,
    625, 552, 257, 838, 694, 111, 967, 687, 303, 28, 472, 770, 24, 725, 513,
    886, 429, 756, 512, 174, 971, 717, 675, 471, 936, 294, 582, 279, 540, 447,
    360, 189, 43, 358, 580, 940, 808, 305, 260, 386, 547, 107, 627, 755, 61,
    519, 495, 490, 249, 1, 497, 330, 108, 752, 601, 913, 392, 925, 515, 436, 
    457, 923, 297, 481, 421, 769, 164, 456, 220, 538, 593, 542, 984, 13, 546,
    666, 929, 524, 632, 975, 566, 837, 589, 595, 265, 942, 633, 707, 748, 201,
    77, 896, 116, 47, 245, 448, 84, 461, 313, 848, 499, 311, 334, 674, 786,
    891, 493, 289, 59, 135, 535, 407, 483, 900, 280, 312, 6, 362, 120, 831,
    934, 395, 179, 352, 839, 516, 406, 910, 574, 623, 711, 494, 646, 21, 268,
    736, 329, 719, 23, 803, 417, 223, 79, 477, 205, 355, 423, 254, 369, 224,
    681, 400, 640, 692, 819, 987, 228, 880, 676, 150, 966, 626, 210, 474, 388,
    186, 824, 989, 872, 163, 799, 814, 669, 34, 46, 129, 227, 372, 100, 295,
    112, 884, 462, 812, 161, 951, 48, 413, 557, 121, 544, 696, 746, 233, 314,
    663, 716, 928, 938, 684, 166, 414, 996, 571, 51, 639, 409, 145, 449, 738,
    947, 866, 911, 16, 901, 506, 833, 62, 714, 96, 583, 657, 995, 592, 850,
    939, 196, 275, 868, 147, 197, 502, 192, 109, 146, 882, 597, 844, 237, 131,
    864, 412, 578, 127, 273, 193, 156, 961, 587, 27, 435, 662, 858, 45, 126,
    209, 83, 554, 467, 452, 345, 999, 888, 35, 300, 972, 214, 393, 783, 217,
    668, 588, 425, 7, 569, 438, 167, 933, 867, 113, 618, 875, 365, 9, 624,
    553, 969, 563, 998, 478, 498, 507, 158, 320, 36, 758, 845, 846, 226, 742,
    455, 649, 994, 8, 653, 236, 558, 434, 854, 641, 518, 86, 375, 255, 990,
    698, 946, 235, 672, 341, 292, 222, 470, 242, 68, 207, 894, 42, 92, 908,
    757, 18, 387, 851, 244, 219, 962, 634, 203, 772, 685, 697, 65, 60, 411,
    792, 69, 679, 907, 915, 768, 385, 340, 442, 67, 534, 177, 718, 72, 458,
    526, 644, 828, 531, 988, 825, 239, 906, 291, 948, 401, 957, 629, 211, 336,
    290, 283, 980, 673, 440, 87, 74, 937, 325, 500, 877, 373, 917, 91, 802,
    39, 380, 950, 878, 234, 612, 328, 307, 842, 796, 562, 451, 564, 600, 172,
    316, 465, 213, 949, 216, 250, 724, 247, 326, 749, 178, 357, 14, 883, 364,
    690, 363, 926, 881, 517, 688, 658, 246, 870, 680, 791, 466, 713, 767, 543,
    781, 533, 1000, 869, 183, 727, 397, 140, 269, 615};
    bubble_sort(decending_order, numbers, size_of_input);
    printf("Sorted array: \n");
    int threashold = 10;
    for (int i = 0; i < 1000; i++){
        printf("%d, ", numbers[i]);
        if (i >= threashold){
            threashold = threashold + 10;
            printf("\n");
        }
    }
    end_t = clock();
    printf("\nthis program ran for %f", (float)(end_t - begin_t)/1000);
}