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

### Day 1:
_**15-03-2021**_

<br>

**Q.** How does \n differ from std::endl ?
> \n is just the special leinebrak character. std::endl inserts the linebreak > >  character, and also "flushes the output buffer", that means that it will immediately print what you've put into cout
cout might buffer its contents for a while for performance reasons (it is faster to output a whole bunch of data at once instead of single characters), so your printing might be delayed, but that happens only in special circumstances
There should not be any limit to printing via cout.

<br>

**Q.** Is there a way to check for overflow ? To see if the result does not go over the maximum limit an integer could hold
> It's somewhat difficult. Overflowing a signed int is undefined behaviour. In practice, it will usually wrap around to negative values.
https://stackoverflow.com/questions/3944505/detecting-signed-overflow-in-c-c 
Extended reading. C++ and C behave the same here.

<br>

**Q.** when will I use i++ vs. ++i?
> `i++` increments the value, and returns the incremented value. `++i` returns the value, and then increments it.
It is a practically rather irrelevant distinction, as it only matters if you use the return value of a decrement/increment operation, which you should just don't do.
`int i = 10;`
`int a = i++;`
is different from:
`int i = 10;`
`int a = ++i;`
`i` will have different values in these examples
`i` will be 11 both times
At the end of a for loop, it does not matter, you can use both `++i` or `i++`
and you will see both in code bases. But `++i` is preferred.

<br>

**Q.** Does `sizeof()` output number of bits or bytes?
> It outputs number of bytes.


<br>

**Tip:**
>When representing numbers with modifiers like long, float, unsigned, etc. use capital letters, because they improve readability.

_Ex._
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
> This is because as an example - the l may be read as 1 by the developer.

>Also, `1E2` is the same as `10E1`.

>If you need a specific size (e.g. 1 byte or 2 bytes) then you can use int8_t or int16_t. uint8_t and uint16_t are the unsigned pendants.
These types usually serve as type aliases to the types that I mentioned before. I???ll show you later how you can create type aliases yourself.

<br>

**Something on References:**
> References are similar to constant pointers to objects. You can change the underlying values of the objects being referred (aliased), but you cannot reassign the reference.

_Ex._
```C++
int i = 1;
int& j = i;     // GOOD: you need to initialize references when declaring

int& k;         // BAD: Compiler will warn you!
```

<br>

**Stay away from Double Pointers!**
_Ex._
```C++
int i = 1;

int* pi = &i;       // pi = pointer to i

// Avoid This!!!
int** ppi = &pi;    // ppi = pointer to pi

```

<br>

**Q.** Are `int* pi = &i` and `int *pi = &i` the same while initialising?  what is the best practice?
> They are both equivalent. There is again two different camps for that question.
The `int* i` school says that the `*` belongs to the type.
The `int *i` school tries to avoid a small pitfall when declaring multiple pointers:
`int* p1, p2, p3, p4;`
declares `p1` as an integer pointer, and `p2, p3 p4` as integers
Correct would have been
`int *p1, *p2, *p3;`
which is much clearer when the * sticks to the variable

<br>

**Self-Study:** Check out _**small string optimization**_

<br>

**Q.** The referenced version (with ampersand) is therefore also more memory and speed efficient in comparison to non-ampersand (non-referenced version), is it?
> That depends. If you have a vector of int, then the reference itself is a 64bit pointer internally. So accessing it takes longer than if you had a 32bit int directly
If you iterate over types representing e.g. an image, then using a reference is much faster, as you will not copy large amounts of data every time.
This kind of implicit copying of large data structures is imho the number one performance bug in C++ code bases.

<br>

**Q.** ok, so if i want to optimize the runtime, i will have to pay attention to the sizes of my data and be sure to use references for everything with 64bit and larger
> As long as the data type does not allocate dynamically, a copy is fine. So for all primitive types (int, double, char ...) use copy, and also for structs.
For classes like string or vector, use a reference
If you want to modify the contents of the container, you need a reference anyway
So I actually change my advise to "always use a reference". The compiler should be able to figure it out where it could matter (and it usually doesn't)

<br>

**Q.** A reference to std::vector<int> would be 64 bits while a refernce to int would be 32 bits. Is that what you meant ?
> A reference always has the size of a pointer. If the compiler even puts it on the stack! Which it might not.
sizeof(std::vector<int>&)  is the same as sizeof(int&)
A good reference link: https://godbolt.org/z/Yh6YbK. 
I have two functions, that do a sum over a vector, once with a copy, once with references.
If you look at the assembly code at the right, the generated assembly is identical!

<br>

**Q.** How to see type of the variable?
**A.** Use `typeid` function.
_Ex._
```C++
auto a = 4;
auto b = false;
auto c = 33.0F;

std::cout << "a: " << typeid(a).name() << "\n"
          << "b: " << typeid(b).name() << "\n"
          << "c: " << typeid(c).name() << "\n";
```

<br>

**Concept:** _One Definition Rule (ODR)_
> Define a function only once. No other place (within the same file or any other files within the program) may have an implementation of that function.

---
<br>

### Day 2
_**16-03-2021**_

<br>

**Q.** Are that compiler options that can detect Runtime Errors?
> -fanalyzer may

<br>

**Q.**  does nullptr have a special type?
> Its type is std::nullptr_t.
It is a 'special' type defined just for nullptr.
You can pass it to any function expecting a pointer, say for example: std::string*
Thus, It can be implicitly converted to any pointer type.

<br>

_**Note:** You can swap 2 ints using XOR. It's a party trick :p_

<br>

_**Note:** Never return a reference to a local variable!!!_

<br>

**Concept:** _Name Mangling_
> It combines function arguments with the name to allow for writing multiple functions with same name & different arguments, and make the code more generalized.
This is not implemented in C, it is only implemented in C++.

<br>

**Q.** Does std::iterator.end() iterator method actually points to 1 past the last element ?
> Yes, you shall not dereference end()

<br>

**Tip:** Avoid using default arguments in functions. If you do use, then stick to only 1 default argument at max!!

<br>

**Concept:** _`inline` keyword_
> Sometimes, for small functions, you don't want call overhead while calling that function. So you use the `inline` keyword, and the compiler copies the function body to wherver it is called.
But if you use `inline` for big functions, it will slow down your code and there is no benifit to this.

> Another thing to note is that it is a **suggestion** to the compiler. You say, I want this thing to be _inlined_, but most of the modern compilers are smart enough to recognise which functions can be _inlined_ and which ones cannot be. So, in the end it is upto the compiler to implement. For ex. the _clang_ compiler completely ignores the `inline` keyword!.

_Ex._
```C++
inline int add_ints(const int& a, const int& b){
    return a + b;
}
```

_**Note:** `inline` keyword doesn't work with "Recursive Functions"_

<br>

_**Note:** Take a Look at the following videos:_
- The Strange details of std::string at Facebook by Nicholas Ormrod at cppcon 2016 
- "GoingNative 2013 C++ Seasoning"

<br>

**Tip:** Use underscore to make data members distinct from arguments in the constructor, because they help in preventing name collisions, while still retaining readability of your code.

_Ex._

```C++
class Person{
private:
    // Data Members
    // Both of the below naming styles are recommended
    // Use one of these
    std::string firstname_;
    std::string m_firstname;
};
```

<br>


**Tip:** Return `const` by reference for getters in classes to be fast and efficient, since returning without reference causes unnecessary copying of values.

```C++
class Person{
private:
    // Data Members
    std::string firstname_;
public:
    Person(/* some params */) = {/* some constructor */}
    
    // Getter
    const std::string& firstname() const { return firstname_; }
};
```

_**Note:** The `const` after the function signature (name) promises (tells) us that this member function will not modify any data-member of the class._

_**Note:** Basically, the first `const` (for the reference) prevents  of this data-member through this alias outside of the class. The second `const` (after the function signature) is there to prevent from this member function from mutating the data-members of the object._

_**Note:** Also, `const std::string& foo();` is the same as `std::string const& foo();`, thus position of this const doesn't matter, because this `const` belongs to the reference. It is read as 'Reference to `const`'._

<br>

**Q.** Can we use set and get as prefixes for these getters and setters to avoid confusion (and generally as a convention)?
> _Yes_ and _No_. 
_Yes_ because no one is stopping you from doing it. 
_No_ because it is more consise to write the thing that the setters and getters set and get respectively. You can overload them.

_Ex._
```C++
// Implement the Person class with both ways
class Person{
private:
    std::string name_;
    int age_;
public:
    // -------------------------------------------------------
    // GOOD GETTERS and SETTERS (most followed convention)
    // getters:
    const std::string& name() const { return name_; }
    int age() const { return age_; }

    // setters:
    void name(const std::string& name){ name_ = name; }
    void age(const int age){ age_ = age; }

    // -------------------------------------------------------
    // BAD GETTERS and SETTERS (again, just a suggestion)
    // getters:
    const std::string& getName() const { return name_; }
    int getAge() const { return age_; }
    
    // setters:
    void setName(const std::string& name){ name_ = name; }
    void setAge(const int age){ age_ = age; }
};
```

<br>

**Q.** Is it a general tip to initialize all the data-members?
> Yes, it is a general tip to have all members in a defined, initialized state after construction.
But note, that some types have a default constructor, like string. You would not need to initialize it, if it is fine that it is an empty string.
But if you leave a variable, say age (of type `int`) uninitialized, it could be anything. 
So for such data-types, it is a good practice to initialize them.

_Ex._
```C++
class Person{
private:
    // This is an example of In-class initializer
    std::string name_;              // String can be empty by default, so no need to initialize it
    int age_ = 0;                   // Integers don't have a default value, so it is a good practice
                                    // to initialize them to something to prevent us from using
                                    // garbage values
    Person* spouse = nullptr;       // Here also, the pointer is set to nullptr to prevent us from
                                    // accessing an un-initialized pointer!
public:
    Person() = default;             // Default constructor
    Person(/* Args */){/* Stuff */}
```

<br>

---

### Day 3
_**17-03-2021**_

<br>

_**Note:** The `v.end()` iterator is returned, if the `std::sort(v.begin(), v.end(),"some_value")` algorithm does not find a match._

<br>

_**Concept:** `explicit` kewrord_
> This keyword is placed in front of a constructor, which stops implicit type conversion in your code.

_Ex._
```C++
class Person{
private:
    std::string name_;

public:
    explicit Person(std::string name)
        : name_ ( name )
    {}

    const std::string& name() { return name_; }
};

void print(const Person& p){
    std::cout << p.name() << "\n";
}


int main(){
    Person p1("John Doe");
    std::string s1("Max Mustermann");

    // This is intended behaviour for print function
    print(p1);

    // This is not intended behaviour for print function
    // Here, it will create a temporary Person object from
    // the string, i.e., an implicit keyword
    // But the `explicit` keyword in front of the constructor
    // prevents this behaviour.
    // Thus `explicit` keyword is very good. 
    // Use it often similar, to `const` keyword

    print(s1);      // if `explicit` is not used, this will cause compilation error
                    // else it will work just fine.
    
    return 0;
}
```

<br>

_**Concept:** `static` keyword_
> Within **classes**, data-members with `static` type modifier is shared by each instance of the class. It is declared inside the class, but needs to be initialized outside of the class.

> Within **classes**, member functions modified with this keyword can be called without creating an instance of the class, only by using the scope operator.
A use of this is to use this to modify the `static` variables, since only `static` modified member functions can mutate `static` data members.
Static data members of a class need to defined only once in a source file

_Ex._
```C++
class Person{
private:
    std::string name;

    // static data member, declared inside the class
    static std::string defaultName_;

public:
    Person(std::string name)
        : name_ ( name )
    {}

    void name(const std::string& name) { name = name_; }

    // static member function
    static setDefaultName(const std::string& name) { name = defaultName_; }
};

// static data member initialized outside of the class definition
// permitted to be initialized only once inside a source file 
Person::defaultName_ { "Max Mustermann" };


int main(){
    // Only static member functions can mutate static variables!
    Person::setDefaultName("John Doe");
}
```

<br>

_**Concept:** `mutable` keyword_
> Used to mutate data-members inside functions with `const` keyword. A use case is in situation where you have getters (which have `const` modifier to prevent the class from modifying the underlying object).
> _Ex._ Consider a `class` `Polygon` which is made up of `Point` (having its separate `class`). `Polygon` also has a variable `area_`, which stores/caches the area of this polygon. Whenever we add or remove a point, the previous area will naturally become incorrect. So whenever we add/remove a point, we will set the area to `-1.0` (invalidation condition as an example). Then, when we call the getter `getArea()` next time, it will first check if this cached area (`area_`) is valid or not. If not, it will call another function `calculateArea()` internally.
The thing is, if we set `const` modifier (after class signature) for `getArea`,
the compiler will call 

_Ex._
```C++
class Point{
private:
    int x_, y_;

public:
    Point(int x, int y) : x_ (x), y_ (y){}
};

class Polygon{
private:
    std::vector<Points> points;
    mutable double area_;

public:
    // assume constructor

    void addPoint(const& Point p){ points.push_back(p); }
    
    
    // Note, here we use const to prevent `invalidateArea` & `calculateArea`
    // from modifying any other data member of this class.
    void invalidateArea() const{ area_ = -1.0; }
    void calculateArea() const{ /* do stuff here and set new area_*/ }

    // getters

    // If we don't use the `mutable` keyword in front of area_,
    // then this `const` qualifier here (after function signature)
    // will not let us modify the `area_` variable in any way! 
    double getArea() const{
        if(area_ < 0){
            calculateArea();
        }
        return area_;
    }

};

```

> The above optimisation (of caching a hidden variable `area_`) is only possible due to the use of the `mutable` keyword. Otherwise we would need to calculate the area every time, which may be highly inefficient. It is also inefficient to re-calculate the area whenever a new point is added. Hence, we go with this approach here.
Use the `mutable` keyword sparingly though, as it can also do harm to the program.
Use it responsibly and only for inner implementation, don't expose it to users of your code.

<br>

_**Concept:** Deque - Double-ended Queue_
> A type of combination of combination of `List` and `Array`. Very useful data structure.


<br>

**Q.** What if we created 1000-long `vector` and deleted 999 elements, will the capacity stay 1000?
> Yes, the capacity of the `vector` will stay 1000.

<br>

_**Note: Resizing of Vectors**_
> There is a resize operation that changes the capacity
resize can also upsize a vector, to avoid frequent reallocation: `std::vector::reserve()`.
`std::vector::resize()` actually inserts new elements into the vector.
And there is `std::vector::shrink_to_fit()` to trim excess capacity

<br>

_**Concept:** Every sequence container has a special constructor that takes two iterators and copies all the elements in that range._

_Ex._
```C++
std::list<int> l_ints = {1, 2, 3, 4, 5};
std::vector<int> v_ints(l_ints.begin(), l_ints.end());

// alternate way

std::vector<int> v_ints2(l_ints.size());
std::copy(l_ints.begin(),l_ints.end(), v_ints2.begin());
```

<br>

_**Note:** In ordered `std::set` and ordered `std::map`, the values are sorted. Only difference between them is: `std::set` stores only keys, while `std::map` stores pairs of keys and values._

<br>

_**Concept:** Dangling Pointer_
> When you use the `delete` command on a pointer pointing to some heap allocated memory, the data at that location is deleted and is inaccessible through the current program, but we can still use this pointer. This is known as the **Dangling Pointer**. To avoid this, always reassign the pointer after `delete` to `nullptr`.

<br>

_**Tip:** In some cases, you may try to free the same piece of heap allocated memory more than once (by calling `delete` twice on the same pointer). To avoid this, we make use of **smart pointers** from "STL"._

<br>

---

### Day 4
_**18-03-2021**_

<br>

_**Comment by Klaus:**_ 
> About performance: The stack can be a little faster indeed. But since the size is limited, you can only draw advantages for small data. Most of the data (including for instance vector and matrices) will be on the heap). unordered sets and maps may a little faster for lookup, but may require more memory. Also the data is never sorted.

<br>

_**Tip:** Remember, for `std::map` and `std::set`, `operator[]` inserts new element if that key does not exist. So avoid using it to traverse those particular associative containers and stick to iterators._

<br>

_**Concept:** Lazy Instantiation_
> Whenever we create a class Template, only the data members and the member functions that we have called are instantiated. This is known as _Lazy Instantiation_.

<br>

---

### Day 5
_**19-03-2021**_

<br>

_**Concept:** Nested templates as well as `using` declarations outside of the class templates require use of the `typename` keyword to tell the compiler that a certain type exists within the class._

_Ex._
```C++
template< typename T >
class Vector{
using Iterator = T*;
private:
    /* Data Members come here */
public:
    /* Constructors and Member-functions come here */
}; 


// implementing a find function that uses this Iterator
template<typename T>
typename Vector<T>::Iterator find(typename Vector<T>::Iterator begin, typename Vector<T>::Iterator end, const T& value){
    // find algorithm
}
```

> If we don't use the `typename` keyword in front of the `Vector<T>::Iterator`, the compiler throw an error saying that this type does not exist. So to assure the compiler, we need to add this keyword (`typename`) and confirm that there is indeed a return type and/or function argument of this type!

<br>

_**Concept:** `public`, `protected`, and `private` access specifiers_
> 

<br>

_**Concept:** The `virtual` keyword in front of a function in the base class states that further derived classes are free to override/change the implementation of this function in their class body._

<br>

_**Tip:** If you want to override a function which is also in the base class, then compulsorily use the `override` keyword._

 [A good reference link](https://stackoverflow.com/questions/29760375/are-there-any-subtleties-in-using-both-the-virtual-and-override-keywords-in-c1)

<br>

_**Concept:** To stop anymore overriding/derivation of virtual functions/classes respectively, use the `final` keyword._

_Ex._
```C++
class Animal {
private:
    std::string name_;

public:
    Animal(const std::string& name): name_ { name } {}
    virtual ~Animal() = default;        // virtual destructor
    virtual void make_noise() = 0;      // pure virtual function
};

struct Dog : public Animal {
public:
    Dog(const std::string& name) : Animal { name } {}

    // "final" qualifier here means that this function cannot be overridden further
    void make_noise() const override final { std::cout << "Wof Wof!\n"; }
};

// The "final" keyword here means that this class cannot be derived from further
struct ShibaInu final : public Dog {
public:
    ShibaInu(const std::string& name) : Dog { name } {}
}

```

<br>

_**Concept:** `__vptr__` (virtual table pointer) and Virtual Dispatch_
> The compiler introduces/defines a "virtual table pointer" in the base class for all overrided functions within the derived classes of this class. Thus, the `__vptr__` resolves everything at run-time and calls the appropriate functions.

> Only disadvantage of this function overriding is that keeping tab of this virtual table pointer and the table itself has a good amount of overhead and can slow down your program.

<br>

---

#### OOP Gotchas (in C++):
_**Foreword:** OOP is not bad. It's that it is not useful/good for everything. It's tool that is really good for specific tasks and bad for others. Use it wisely._ ;)

Don't be discouraged though: _[Great Talk on OOP - CppCon 2019](https://www.youtube.com/watch?v=32tDTD9UJCE)_


#####  1. <ins>Overloading and Overriding don't mix well in C++ when using ihneritance</ins>

```C++
struct Thing {
    virtual void update(int);           // Function (1)
    virtual void update(double);        // Function (2)
};

struct MyThing : public Thing {
    void update(double) override;       // Function (3) [override of Function (2)]
};

int main(){
    Thing t* = new Thing();
    MyThing mt* = new Thing();

    t->update(12);          // This calls Function (1): Expected behaviour
    mt->update(12);         // This calls Function (3): Surprising behaviour!!!
}
```

> Why you ask? Because when you use `mt->update(12)`, the `mt` pointer goes to/looks at the `class` "`MyThing`" first. And because it does not find an overloaded function in MyThing for `int`, it will implicitly convert the `12` to a `double` and call the 3rd version [Function (3)].
>
> To include overloads from the base class, you can use `using` declaration. Example: use `using Base::foo;` in the derived class to make sure that the overloaded function `foo` from the base class can be called.

```C++
struct Thing {
    virtual void update(int);           // Function (1)
    virtual void update(double);        // Function (2)
};

struct MyThing : public Thing {
    using Thing::update;                // using declaration to include update from
                                        // the Thing class (Base class)
    void update(double) override;       // Function (3) [override of Function (2)]
};

int main(){
    Thing t* = new Thing;
    MyThing mt* = new Thing;

    t->update(12);          // This calls Function (1): Expected behaviour
    mt->update(12);         // This calls Function (1): Fixed it
}
```

<br>

#####  2. <ins>Avoid having default arguments on virtual functions!!!</ins>
> Why?! Because it mixes static values with dynamic polymorphism (virtual function call resolution), leading to a function potentially using defalut values from a base virtual function in an overridden function at run-time, leading to undefine behaviour.

```C++
struct Thing {
    virtual void update(int i = 10);    // Function (1)
};

struct MyThing: public Thing {
    void update(int i = 20) override;   // Function (2)
};


int main(){
    Thing* t  = new Thing;
    Thing* mt = new MyThing;

    t->update();                        // calls (1), i = 10 [Expected]
    mt->update();                       // calls (2), i = 10 [Unexpected!!]
}
```

> During compilation, the compiler sees `mt->update()` and thinks: it is a `Thing` object calling `update()` without any arguments, so I will set `i = 10` here. BUT, during run-time, the program resolves `mt` as a pointer to object `MyThing` and calls the overridden `update()` function from it, leading to taking `i = 10` as the defauly argument instead of `i = 20`.

_Solution: If you absolutely need to use default arguments for virtual functions, provide an overloaded set of (virtual) functions._
```C++
struct Thing {
    void update() { update(10); }
    virtual void update(int i = 10);    // Function (1)
};

struct MyThing: public Thing {
    using Thing::update;
    void update(int i = 20) override;   // Function (2)
};


int main(){
    Thing* t  = new Thing;
    Thing* mt = new MyThing;

    t->update();                        // calls (1), i = 10 [Expected]
    mt->update();                       // calls (2), i = 10 [Unexpected!!]
}
```

<br>

#####  3. <ins>Don't create Arrays of Pointers with Abstract Class, always use the Base class it</ins>
```C++
struct Thing {
    Thing(int i ) : x(i) {}
    int x;
}

struct MyThing {
    MyThing(int i, int j) : Thing(i), y(j) {}
    int y;
};


int main(){
    myThing mt[] = { {1,2}, {3,4}, {5,6} };
    Thing* t = mt;

    t[1].x = 7;     // This should update mt[1].x, right?
                    // NO, it doesn't
                    // Instead mt[0].y is changed to 7
                    // Thus mt becomes: { {1,7}, {3,4}, {5,6} }
}
```

> Why?! Because when you assign `t = mt`, the pointer `t` is of class `Thing` and can only hold 4 bytes of info (beacuse of one `int x`), so when you do `t[1]`, it is actually accessing `mt[0]`. Hence `t[1].x` mutates `mt[0].y` to `7`.

_**Note:** Never assign a pointer to an array of derived class objects to a pointer to its base._

_**Note:** In interfaces, use raw pointers to denote individual objects (only)._

<br>

---

<br>

_**Side Note:**_

- Stuttgart and Vienna computing centers have an intermediate course that is an extension of this!

- Advanced cpp course offered by RRZE in 2nd Half of 2021 (hopefully!)

<br>

_**Links:**_
- [Link to the complete course material](https://faubox.rrze.uni-erlangen.de/dl/fiUYFHHUjhqnrb4oPPL79WYu/CppTraining_2021_03_15_RRZE_full.zip)

<br>

_**Literature:**_
1. C++ Primers and References:
    - C++ Primer by Lippman, Lajoie, Moo (800 pages -_-) ***
    - A Tour of C++ 2nd Ed. by Bjarne Stroustrup (256 pages => only new and necessary stuff included here. small but very dense in info) **

2. Advanced C++ Programming:
    - Effective Modern C++ (C++2014) by Scott Meyers *** : good for C++11 and 14 Features

    - Effective STL by Scott Meyers (C++98)
    - C++ Templates by Vandevoorde, Josuttis, Gregor (C++17) [a.k.a Bible for Templates]

3. C++ Software Design:
    - Large-Sacle C++ by John Lakos [get the version with picture of Dam]

4. Refactoring and Testing:
    - Modern C++ Programming with Test-Driven Development by Jeff Langr (Only for C++11) [a very good intro to TDD]

5. Professional Programming (not limited to C++, but in General applicable to SD):
    - The Pragmatic Programmer by David Thomas, Andrew Hunt (2nd Ed.) *****
    - The Clean Coder by Robert C. Martin ***
