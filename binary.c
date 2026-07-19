#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};   // Sorted array
    int low = 0, high = 4, mid;
    int key;

    printf("Array Elements: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            printf("Element %d found at index %d.\n", key, mid);
            return 0;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("Element %d not found in the array.\n", key);

    return 0;
}