\page diy Extra: Making Your Own VN

# How-To {#how-to}

Want to make a game similar to Work Life?
Copy the files and take a look at the API.
Of course, you can always reference this game's code for design patterns.

## Prerequistes {#prerequistes}

* butano repo
* devkitarm
* emulator (I used mGBA)

## The Library {#the-library}

header files:

* util.h
* vnlib.h

source files:

* util.cpp
* vnlib.cpp

## Guide {#guide}

### Phase 1: Start with template {#phase-1}

You will need a functioning bulid environment before moving forward with the guide:

1. start with the template folder provided by butano: [link to folder](https://github.com/GValiente/butano/tree/master/template)

2. `make` the template

3. open project in emulator

### Phase 2: Initialize the library {#phase-2}

1. copy the library header files (`util.h` and `vnlib.h`) into your `include` directory

2. copy this library source files (`util.cpp` and `vnlib.cpp`) into your `src` directory

3. update the `main.cpp` file to the following. Start with the smallest possible program to ensure library files are copied and bulid environment is functional.
```
#include "vnlib.h"

int main() {
    vnlib::main()
}
```

4. update your `Makefile`. Make sure `DEFAULTLIBS` is enabled.
```
DEFAULTLIBS 	:=  true
```

5. `make` the project

6. open project in emulator

### Phase 3: Start your story! {#phase-3}

1. update `main.cpp` to have a story start function
```
#include "vnlib.h"

void my_story() {
    vnlib::say("MyChar", {"hello", "world!"});
}

int main() {
    vnlib::set_story_start(my_story);
    vnlib::main();
}
```

2. `make`

## Limitations {#limitations}

* TODO