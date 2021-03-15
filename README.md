### Intro to C++ for Beginners:

#### Content:

1. Getting Started
2. Variables and Basic Types
3. Library Types
4. Expressions
5. Statements
6. Functions
7. Generic Algorithms
8. Classes
9. Sequence Containers
10. Associative Containers
11. Choosing a Container
12. Dynamic Memory
13. Copy Control
14. Overloaded Operations and Conversions
15. Templates
16. Inheritance
17. Exceptions
18. Namespaces
19. Summary/Literature

---

#### Day 1:

Q. How does \n differ from std::endl ?
A. \n is just the special leinebrak character. std::endl inserts the linebreak character, and also "flushes the output buffer", that means that it will immediately print what you've put into cout
cout might buffer its contents for a while for performance reasons (it is faster to output a whole bunch of data at once instead of single characters), so your printing might be delayed, but that happens only in special circumstances
There should not be any limit to printing via cout


Q. Is there a way to check for overflow ? To see if the result does not go over the maximum limit an integer could hold
A. It's somewhat difficult. Overflowing a signed int is undefined behaviour. In practice, it will usually wrap around to negative values.
https://stackoverflow.com/questions/3944505/detecting-signed-overflow-in-c-c 
Extended reading. C++ and C behave the same here.


Q. when will I use i++ vs. ++i?
A. i++ increments the value, and returns the incremented value. ++i returns the value, and then increments it
It is a practically rather irrelevant distinction, as it only matters if you use the return value of a decrement/increment operation, which you should just don't do.
int i = 10;
int a = i++;
is different from:
int i = 10;
int a = ++i;
a will have different values in these examples
i will be 11 both times
At the end of a for loop, it does not matter, you can use both
++i or i++
and you will see both in code bases


Q. Does `sizeof()` output number of bits or bytes?
A. It outputs number of bytes.


Tip:
When representing numbers with modifiers like long, float, unsigned, etc. use capital letters, because they improve readability.

Ex.

Use these:
```C++
int i = 1;
long l = 10L;
unsigned u = 10U;
unsigned long ul = 10UL;

float f = 10.0F;
double d = 10.0;
long double ld = 10.0L;

double e = 1E2;
```

Instead of these (lower case):
```C++
int i = 1;
long l = 10l;
unsigned u = 10u;
unsigned long ul = 10ul;

float f = 10.0f;
double d = 10.0;
long double ld = 10.0l;

double e = 1e2;
```
This is because as an example - the l may be read as 1 by the developer.


Also, `1E2` is the same as `10E1`.


If you need a specific size (e.g. 1 byte or 2 bytes) then you can use int8_t or int16_t. uint8_t and uint16_t are the unsigned pendants.
These types usually serve as type aliases to the types that I mentioned before. I’ll show you later how you can create type aliases yourself.


**Something on References:**

References are similar to constant pointers to objects. You can change the underlying values of the objects being referred (aliased), but you cannot reassign the reference.

Ex.
```C++
int i = 1;
int& j = i;     // GOOD: you need to initialize references when declaring

int& k;         // BAD: Compiler will warn you!
```



**Stay away from Double Pointers!**
Ex.
```C++
int i = 1;

int* pi = &i;       // pi = pointer to i

// Avoid This!!!
int** ppi = &pi;    // ppi = pointer to pi

```


Q. Are "int*    pi = &i" and "int    *pi = &i" the same while initialising? 
what is the best practice?
A. They are both equivalent. There is again two different camps for that question.
The int* i school says that the * belongs to the type.
The int *i school tries to avoid a small pitfall when declaring multiple pointers:
int* p1, p2, p3, p4;
declares p1 as an integer pointer, and p2, p3 p4 as integers
Correct would have been
int *p1, *p2, *p3;
which is much clearer when the * sticks to the variable


**Self-Study:** Check out _small string optimization_


Q. The referenced version (with ampersand) is therefore also more memory and speed efficient in comparison to non-ampersand (non-referenced version), is it?
A. That depends. If you have a vector of int, then the reference itself is a 64bit pointer internally. So accessing it takes longer than if you had a 32bit int directly
If you iterate over types representing e.g. an image, then using a reference is much faster, as you will not copy large amounts of data every time.
This kind of implicit copying of large data structures is imho the number one performance bug in C++ code bases.


Q. ok, so if i want to optimize the runtime, i will have to pay attention to the sizes of my data and be sure to use references for everything with 64bit and larger
A. As long as the data type does not allocate dynamically, a copy is fine. So for all primitive types (int, double, char ...) use copy, and also for structs.
For classes like string or vector, use a reference
If you want to modify the contents of the container, you need a reference anyway
So I actually change my advise to "always use a reference". The compiler should be able to figure it out where it could matter (and it usually doesn't)


Q. A reference to std::vector<int> would be 64 bits while a refernce to int would be 32 bits. Is that what you meant ?
A. A reference always has the size of a pointer. If the compiler even puts it on the stack! Which it might not.
sizeof(std::vector<int>&)  is the same as sizeof(int&)
A good reference link: https://godbolt.org/z/Yh6YbK. 
I have two functions, that do a sum over a vector, once with a copy, once with references.
If you look at the assembly code at the right, the generated assembly is identical!


Q. How to see type of the variable?
A. Use `typeid` function. Ex.
```C++
auto a = 4;
auto b = false;
auto c = 33.0F;

std::cout << "a: " << typeid(a).name() << "\n"
          << "b: " << typeid(b).name() << "\n"
          << "c: " << typeid(c).name() << "\n";
```


**Concept:** _One Definition Rule (ODR)_

Define a function only once. No other place (within the same file or any other files within the program) may have an implementation of that function.


