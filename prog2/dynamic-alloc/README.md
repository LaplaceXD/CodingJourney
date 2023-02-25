# Dyanmic Allocation

Dynamic allocation is important for C, since most of the variables are stored in the Stack. The Stack, which is usually referred to as the execution stack is the location where all of your variables live when declared. The Stack is quite fast; however, most of the variables stored here are automatically removed once execution ends. Thus, we have to use of dynamic allocation to ensure that our returned arrays are not garbage collected after a function ends.

## Quick Difference of normal allocation and dynamic allocation
| | Normal Allocation | Dynamic Allocation |
| --- | --- | --- |
| Declaration | `int items[10];` | `int *items = (int *) malloc(sizeof(int) * 10)` |
| Storage Location | Stack | Heap |
| Garbage Collection | Automatically overwritten by CPU processes | Manually done by the user through the use of `free()` |
| When to use? | Usually used in the main function, or when the short-lived variable will not be used later on in the execution of the program | Usually used when the variable will be used throughout the program's lifetime, and not just within the lifetime of a function. |

## Functions
There are 4 functions that are used for dynamic allocation, you must always include the following library to use these
```c
#include <stdlib.h> // <-- This is the standard library that contains all the functions that we require for memory manipulation
```
### Malloc
```c
void * malloc(size_t chunk_size);
```
This is the first function, which is malloc, short for memory allocate.
> Params
> - chunk_size - a value in bytes, which is the size of memory that will be allocated in the Heap

> Returns
> - a generic pointer to the first position of the chunk of memory in the heap

```c
// Example usage:
int *items = (int *) malloc(sizeof(int) * 10);
```
This returns an integer array of size 10. Notice, that we are using the sizeof function, this is because the passed argument to `malloc` requires the value to be in bytes. Since, an `int` data type varies between CPU architectures, with x32 having 2 bytes for `int`, while x64 requiring 4 bytes for `int`, we then have to use the sizeof(int) to automatically let the compiler adjust that for us. Afterwards, we need 10 of those int sizes, so we just multiply it by 10, hence we have `sizeof(int) * 10`.

### Calloc
```c
void * calloc(size_t number_of_chunks, size_t chunk_size)
```
> Params
> - number_of_chunks - the number of chunks to be allocated
> - chunk_size - a value in bytes, which is the size of memory allocated for each chunk

> Returns
> - a generic pointer to the first position of the chunk of memory in the heap

```c
// Example:
char *chars = (char *) calloc(10, sizeof(char)); 
```
Here, unlike `malloc`, `calloc` requires 2 arguments. First, the number of items in your array, and the size of these items in your array. Since, we require a character array of size 10, we then have the following declaration above. The special thing about calloc, is unlike malloc it initializes the value inside of the array to defaults.
```c
char *chars = (char *) calloc(3, sizeof(char)); 
// This is an array of ['\0', '\0', '\0'], since '\0' is the null character which is the default of char

int *items = (int *) calloc(3, sizeof(int)); 
// This is an array of [0, 0, 0], since 0 is the default of int

int **ptrs = (int **) calloc(3, sizeof(int *));
// This is an array of [NULL, NULL, NULL], since this is an array of integer pointers, and the default of any pointer is NULL
```

### Free
```c
void free(void *ptr);
```
> Params
> - ptr - a pointer to a dynamically allocated array

> Returns
> - nothing

```c
// Example:
int *items = (int *) malloc(sizeof(int) * 5);
free(items); //<-- This frees up the space allocated for the items array.
```

### Realloc
```c
void * realloc(void *ptr, size_t new_chunk_size); 
```
> Params
> - ptr - a pointer to a dynamically allocated array
> - new_chunk_size - the new size of the passed dynamically allocated array

> Returns
> - a pointer to the reallocated memory array

```c
int *items = (int *) malloc(sizeof(int) * 5);
items = (int *) realloc(items, sizeof(int) * 10);
```
The code above initializes a dynamically allocated array items using malloc. The current size of the `items` array is 5. However, with `realloc` we can resize items to an array of size 10.
