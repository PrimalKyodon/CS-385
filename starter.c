#include <stdio.h>

/*
 * Author: Aaren Patel
 * Date: 9/26/2023
 * I pledge my honor that I have abided by the Stevens Honor System.
 * Sorting Algorithm: Insertion Sort 
 * Extra Credit Consideration: Yes
 */

void copy_str(char* src, char* dst) {
    /*Copies char* src into char* dst*/
    int i = 0;
countLoop:
    //Checks for end of string
    if (src[i] == '\0') 
        dst[i] = '\0';
    //Copies the ith char in src to dst then loops back to the countLoop header
    else {
        dst[i] = src[i];
        i++;
        goto countLoop;
    }
}

int dot_prod(char* vec_a, char* vec_b, int length, int size_elem) {
    /*Calculates the dot product of vec_a and veb_b and returns it*/
    int count = 0;
    int* a = 0;
    int* b = 0;
    int dotProduct = 0;
dotProduct:
    //If all values of the vectors havent been calculated calculates the product of the next two values of the vectors and continues the loop.
    if (count < length) {
        a = (int*)(vec_a + (count * size_elem));
        b = (int*)(vec_b + (count * size_elem));
        dotProduct += *(a) * *(b);
        count++;
        goto dotProduct;
    }

    return dotProduct; 
}

void sort_nib(int* arr, int length) {
    /*Sorts the nibbles in the integer array from least to greatest*/
    int k = 0, l = 0;
    char arr2[length*8];
    //Fills the  char array with the nibs from the integer array
charArray:
    l=0;
    if (k < length) {
        //This inner loop sets one integer to the eight individual bits.
charArrayInner:
        if (l < 8) { 
            arr2[k*8+l] = (char)(arr[k] >> (4*l) & 0x0f);
            l++;
            goto charArrayInner;
        }
        k++;
        goto charArray;
    }
//Performs an insertion sort on the char array
    int i = 1, j;
    char key;
insertionSort:
    if (i < length*8) { 
        key = arr2[i];
        j = i - 1;
insertionSortInner:
        if (j >= 0 && arr2[j] > key) {
            arr2[j+1] = arr2[j];
            j--;
            goto insertionSortInner;
        }
        arr2[j+1] = key;
        i++;
        goto insertionSort;
    }
 

//Reforms the integer array with the first 8 nibs in the char array
int h = 0, g = 0;
intArray:
    g=0;
    if (h < length) {
        arr[h] = 0;
intArrayInner:
        //Performs the actions to make one integer each 8 loops.
        if (g < 8) {
            arr[h] = ((int)(arr2[h*8+g])) | (arr[h] << 4);
            g++;
            goto intArrayInner;
        }
        h++;
        goto intArray;
    }
}


int main(int argc, char** argv) {

    /**
     * Task 1
     */

    char str1[] = "382 is the best!";
    char str2[100] = {0};

    copy_str(str1,str2);
    puts(str1);
    puts(str2);

    /**
     * Task 2
     */

    int vec_a[3] = {12, 34, 10};
    int vec_b[3] = {10, 20, 30};
    int dot = dot_prod((char*)vec_a, (char*)vec_b, 3, sizeof(int));
    
    printf("%d\n",dot);

    /**
     * Task 3
     */

    int arr[3] = {0x12BFDA09, 0x9089CDBA, 0x56788910};
    sort_nib(arr, 3);
    for(int i = 0; i<3; i++) {
        printf("0x%08x ", arr[i]);
    }
    puts(" ");

    return 0;
}
