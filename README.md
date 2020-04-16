# Internal Unions training
## 1. What the hell is union? 
A union is a special class type that can hold only one of its non-static data members at a time. The class specifier for a union declaration is similar to class or struct declaration. 

```c++
union myUnion{
  int someMember;
  float anotherMember;
}
```

Union may have member functions, but cannot have virtual functions.

Union is only as big as necessary to hold its largest data member. The other data members are allocated in the same bytes as part of that largest member. The details of that allocation are implementation-defined but all non-static data members will have the same address.

It's **undefined behavior** to read from the member of the union that wasn't most recently written. Many compilers implement, as a non-standard language extension, the ability to read inactive members of a union. 

## 2. Use cases
### 2.1 Saving memory
A union allows a single piece of memory to be used for different types of objects at different times. Consequently, it can be used to save memory when we have several objects that are never used at the same time.

> It is like a room in a hotel. Different people live in it for non-overlapping periods of time. These people never meet, and generally don't know anything about each other. By properly managing the time-sharing of the rooms (i.e. by making sure different people don't get assigned to one room at the same time), a relatively small hotel can provide accommodations to a relatively large number of people, which is what hotels are for. 
>
> -Somebody on StackOverflow 
```c++
union value {
  int x;
  double d;
};

value v = { 123 };              // now v holds an int
std::cout << v.x << std::endl;  // write 123
v.d = 987.654;                  // now v holds a double
std::cout << v.d << std::endl;  // write 987.654
```
What is wrong here? 

Unions shouldn't be used 'naked'. In this use case, it is useful and safer to have some indicator of currently used member. 

### 2.2 Type punning
#### 2.2.1 What is type punning?
 Type punning is the possibility of a programming language to intentionally subvert the type system to treat a type as a different type. One typical way to do type punning in C++ is to read the member of a union with a different type from the one with which it was written.
#### 2.2.2 How to safely convert data from one datatype to another? 
 Still not the best solution, but better is to use `reinterpret_cast`. Generally, from my experience, data punning is most useful for converting values into raw bytes and vice versa. Even better solution is to use bit shifting and masking to get raw bytes. 
#### 2.2.3 But wait, there's more!
 The best and safest way to access raw bytes is to use distinct data type `std::byte`
##### 2.2.3.1 What is advantage here?
 std::byte is really just a bunch of un-interpreted bits. If you use uint8_t or unsigned char, you are actually interpreting the bits as an 8-bit numerical value, which might not be the right semantics that you want. Also, std::byte will not allow accidental arithmetic on it, while uint8_t does.  
 



