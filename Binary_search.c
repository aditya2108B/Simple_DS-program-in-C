

#include<stdio.h>
int List[100];  
int size;       
void Binary_Search(int Element);
int Element();
void sort();
void Read_input();
void main() {
    // Prompt for the List size
    printf("Enter the Size of List: ");
    scanf("%d", &size);
    Read_input();
    sort();
    Binary_Search(Element());
    }

int Element(){
int Element;
    printf("\nEnter the Element You want to Search in List : ");
    scanf("%d", &Element);
    return Element;
}

// Binary Search Algorithm
void Binary_Search(int Element) {
    int low = 0, high = size - 1, mid, Flag = 0;
    while (low <= high) {
        mid = (low + high) / 2; 
        if (Element == List[mid]) {
            Flag = 1;  // Set flag if element is found in list
            break;
        } 
        else if (Element < List[mid]) {
            high = mid - 1;
        }else if (Element > List[mid]) {
            low = mid + 1;
        } 
    }
    if (Flag == 1) {
        printf("\nElement is Found in List\n");
    } else {
        printf("\nElement is not Found in List\n");
    }
}
void sort(){
    // Sorting the List in ascending order
    int i,j;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (List[i] >= List[j]) {
                // Swap elements 
                int t = List[i];
                List[i] = List[j];
                List[j] = t;
            }
        }
    }
}
void Read_input(){
    // Input the elements of the List   
     int i, j;
    for (i = 0; i < size; i++) {
        printf("\nEnter %d Element of List: ", (i + 1));
        scanf("%d", &List[i]);
    }
}
