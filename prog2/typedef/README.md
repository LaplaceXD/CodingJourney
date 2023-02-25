# Typedef

`typedef` is an **aliasing** keyword in C. 

### Key Facts:
- Mostly used to aliast complex data types such as structs.
```c
// For example if you have an array list implementation looking like
struct {
  int data[10];
  int count;  
};

// You wouldn't want to see this in the main function block like so
int main(void) {
    struct {
        int data[10];
        int count;
    } List1; // <-- imagine having multiple of these lists, your code would work, but would have a lot of noise

    struct {
        int data[10];
        int count;
    } List2;

    struct {
        int data[10];
        int count;
    } List3;
}

// instead you can typedef the struct, and make it simpler
typedef struct {
    int data[10];
    int count;
} ArrayList; // <- Now the struct is named as the ArrayList datatype, which is a user-defined data type

// So our main function block would now look cleaner
int main(void) {
    ArrayList List1;
    ArrayList List2;
    ArrayList List3;
}

```
- Single source of truth data type, and also provides encapsulation.
```c
// For example if you were to change the content of the List struct to now allow for 15 items in the data
int main(void) {
    struct {
        int data[10]; // <-- You will have to change this from 10 to 15
        int count;
    } List1;

    struct {
        int data[10]; // <-- This 
        int count;
    } List2;

    struct {
        int data[10]; // <-- And this
        int count;
    } List3;

    // That takes too long to do, and could also potentially cause bugs, if ever you forget to change one of them.
}

// With a typedef you can just change one single location, thus we have a single source of truth
typedef struct {
    int data[10]; // <-- Just change this from 10 to 15
    int count;
} ArrayList;

// Now, we don't have to change anything in the main function block, since they are using an aliasing of the type defined ArrayList
int main(void) {
    ArrayList List1;
    ArrayList List2;
    ArrayList List3;
}
```
- Type definitions do not occupy any space in the RAM.
```c
typedef struct {
    int data[10];
    int count;
} ArrayList; // <-- This doesn't take any space

// You might try using sizeof(ArrayList), and it will print out a non-zero value, but that is usually used for allocating space to that struct. In memory, it truly doesn't occupy space.

struct {
    int data[10];
    int count;
} ArrayList; // <-- This takes space

// This is no longer a type definition but rather a declaration of an ArrayList variable. This would then take space in the RAM.
```