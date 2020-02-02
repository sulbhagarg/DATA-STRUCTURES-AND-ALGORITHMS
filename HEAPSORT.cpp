/* Heap Sort */
#include<stdio.h>
#include<math.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void max_heapify(int array[], int index, int size_of_array){
    int i;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest;
    if(left <= size_of_array && array[left] > array[index])
        largest = left;
    else
        largest = index;
    if(right <= size_of_array && array[right] > array[largest])
        largest = right;
    if(largest != index){
        swap(&array[index], &array[largest]);
        max_heapify(array, largest, size_of_array);
    }
}
void build_max_heap(int array[], int size_of_array){
    int i;
    for(i = size_of_array/2; i >= 0; i--){
        max_heapify(array, i, size_of_array);
    }
}
void heap_sort(int array[], int size_of_array){
    int i;
    build_max_heap(array, size_of_array);
    for(i = size_of_array; i > 0; i--){
        swap(&array[0], &array[i]);
        size_of_array--;
        max_heapify(array, 0, size_of_array);
    }
}
int main(){
    int n, i;
    printf("Enter the size of array:\n");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++)
        scanf("%d",&array[i]);
    heap_sort(array, n-1);
    printf("Sorted array:\n");
    for(i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
}
