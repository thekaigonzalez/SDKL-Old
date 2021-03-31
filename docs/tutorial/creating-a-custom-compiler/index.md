# SDKL API Guide No.1
SDKL Is a simplified programming language
with over 5+ Compilers. Turn this coding language into any
other language. essentially giving the language infinite possibilities.

SDKL Also contains a Compiler Structure Client (CSC),
Used to build debugging compilers. Luckily, This "CSC" is open sourced.

This tutorial goes over the basics of a CSC, And how you can build your own
compiler structure.

## NOTE!
SDKL API Requires about 10% C++ Knowledge.
SDKL Is in no way associated with the rendering engine "SDL"
## Part 1: Constructing our client
for starters: The CSC Requires something called a Client, Which is a virtual "machine" that is able to execute tasks.
to construct a client, create a new script. Be sure you have the Compiler Client Header added. You can open a new script in the 
root directory, or add the headers to your mingw/Include. Then add the following to your script.

```c++
#include "parser/parse.h"

/*
 * Initializes a new SDK Compiler. Allows 
 * functionality of an average compiler to be 
 * passed as function
 */
SDKL::Compiler<SDK_CALLBACK_DECL> *mycompiler;

int mycompiler->ready() {
    std::cout << "The Compiler is "
                 "ready to go!\n";
}

int main(int argc, char* * argv) {
    std::string firstarg(argv[1]);
    std::string buffer;
    std::string res;
    std::ifstream ifile(firstarg);
    while (getline(ifile, buffer))
        res += buffer;
    std::string body = mycompiler->skipEntryPoints(res, ENTRY);
}
```
This code alone already is a parser for files.
This code gathers the first argument, Then opens a file with the arguments name.
After, It reads the file lines until Something errored.

Next, Create a new file. Call it whatever you want.
For this documentation I'll call it `test.sdk`.

In test.sdk, Write

```
    >> Yay
    
    
.call main() {
    return();
}

 ```
Now, execute the program above by typing:
```
myprogram.exe test.sdk
```
And the Output Received Should be something like:

```
> myprogram.exe test.sdk

.call

> ...
```

To view the entire output, Change

`std::string body = mycompiler->skipEntryPoints(res, ENTRY);`

To 

`std::cout << res << std::flush;`

The output changes to:
```
$ myprogram.exe test.sdk

>> Yay .call main() { return(); }

$ ...
```
See a difference? I do.

Basically, The Tokenizer is indexing and caching
different parts of the script. So when you do
```
std::string body = mycompiler->skipEntryPoints(res, ENTRY);
```
It goes to
```
.call
```
because you requested that certain part.

## Part 2: Appending to another file
You can compile files with SDK Support by using the SDKCompileEngine.
You can find this in compiler/engine/append.h.

```c++

const SDKCompileFile* file = new SDKCompileFile("outfile.out");


int main() {
    // Adds "hello"
    // to a file named outfile.out.
    file->write("hello");
}

```
The base compilers are written using this method.
The Compilers can be found in compiler/.
## Part 3:  Finishing your compiler

```c++
#include "parser/parse.h"

/*
 * Initializes a new SDK Compiler. Allows 
 * functionality of an average compiler to be 
 * passed as function
 */
SDKL::Compiler<SDK_CALLBACK_DECL> *mycompiler;

int mycompiler->ready() {
    std::cout << "The Compiler is "
                 "ready to go!\n";
}
SDKCompileFile file = "outfile.out";
int main(int argc, char* * argv) {
    std::string firstarg(argv[1]);
    std::string buffer;
    std::string res;
    std::ifstream ifile(firstarg);
    while (getline(ifile, buffer))
        res += buffer;
    std::string body = mycompiler->skipEntryPoints(res, ENTRY);
    file->write("<html>"
                "<body>"
                "<h1>" + body + "</h1>"
                "</body>"
                "</html>");
    
}
```
After, Run it.

There should be a html file with these contents.

```html
<html lang="no-js"><body><h1>.call main(){return();}</h1></body></html>
```
-----------
That's how you build a basic HTML Compiler from SDK_L! Thank you!