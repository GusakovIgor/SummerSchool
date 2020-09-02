#include <stdio.h>
#include <assert.h>

void ReadArr (FILE* fileData, int Arr[], int size);

void SortArr (int Arr[], int size);

void swap (int* val1, int* val2);
void swap_Test ();

void PrintArr (int Arr[], int size);

int main()
    {
    printf ("#Bubble Sort\n");
    printf ("#by Igor Gusakov (31.08.2020)\n\n");
    
    int nStudents = 11;
    int FirstYear [11];
    swap_Test();
    
    
    FILE* fileData = fopen ("Data.txt", "r");
    assert (fileData != NULL);
    ReadArr  (fileData, FirstYear, nStudents);
    fclose   (fileData);
    
    SortArr  (FirstYear, nStudents);
    
    printf("#Sorted Students:\n"); 
    PrintArr (FirstYear, nStudents);

    return 0;
    }
    
//---------------------------------------------------------------------------------------
//!	Sort Array function:
//!
//! @param [out]  Arr   Array that we need to sort
//!	@param [in]   size  Size of that array
//!
//!	
//!	@return None
//!
//! @description: This function sorting recieved array:
//!				  1.Doing iterations until all array is sorted (when sorted = size or count = 0)
//!				  2.In each iteration doing cycles
//!				  3.In cycle swaps each paire of elements where left > right
//---------------------------------------------------------------------------------------
    
void SortArr (int Arr[], int size)                  // Sorting Array with "Bubble Sort"
    {
    int count = -1;                                 // Counter of swaps
    
    for (int sorted = 0; sorted < size && count != 0; sorted++)     // Sorted - 
        {
        count = 0;
        for (int i = 0; i < size - sorted - 1; i++)
            if (Arr[i] > Arr[i+1])
                {
                swap(&Arr[i], &Arr[i+1]);                 
                count++;
                }
        }
    
    }

void swap (int* val1, int* val2)                    // Changing two variables
    {
    int temp = *val1;
               *val1 = *val2;
                       *val2 = temp;
    }
    
void swap_Test ()                                   // Unit-test for swap func.
    {
    printf("#Testing swap function\n");
    int a[2] = {0, 1};
    swap(&a[0], &a[1]);
    
    if (a[0] == 1 && a[1] == 0)
        printf(" Test passed!\n\n");
    else
        {
        printf("#Test failed!\n");
        printf("--expected a[0] = 1, but recieved a[0] = %d\n", a[0]);
        printf("--expected a[1] = 0, but recieved a[1] = %d\n\n", a[1]);
        }
    }

void ReadArr (FILE* fileData, int Arr[], int size)  // Reading array from file
    {
    for (int i = 0; i < size; i++)
        fscanf (fileData, "%d", Arr + i);           // Don't forget about last argument in fscanf:
    }                                               //               pointer on variable, we read

void PrintArr (int Arr[], int size)                 // Printing array
    {
    for (int i = 0; i < size; i++)
        {
        if (i < 10)
            printf(" ");
        printf("FirstYear[%d] = %d\n", i, Arr[i]);
        }
    }
