# SDK-L
My and 749470322570559528 (Bill Nye The Coding Guy#3188)'s
coding language. Featuring an extensible C API Providing 
interfaces for SDK Classes
## API
Enjoy the rich functionalities of the
- Package Installer
- Interpreter
In your hands.
  
With the C API Comes extra functionality.

`SDK.WildCard` : Any SDK Value.

`SDK.Class`  Class with methods.

`SDK.State` A Certain Position within the SDK Interpreter.

### Enum

`SDK.enum.SDKReturnType` AN SDK Return type.
# Standard
Code can be difficult to write, SDK Has a standard which developers
should follow in order to write neater code.

These exceptions are named NOTUPTOSTANDARD______.
# Tree
The parser tree is the order in which words are read to determine
what should be what.

The parser tree is open sourced and can be found in
state/dom.h state/cur.h tokenizer/read.h

```
script
    |__     
       Statement
            |__
                Expression Parser
                    |__
                        Return Value
                            |__
                                Value Evaluator
                                    |__ 
                                        Finalizing changes and running.
```
# Functionalities
## Documentation
`Entry(compareStatement: SDKCompareStatement, Value: SDKWildCard)`

(UPDATED)
Calls a method and returns if it's able to be
an entry waypoint.
```c
entry(.call, return);
```
# EntryPoints

An **Entry Point** As defined in READ.h, Is a point
that defines a way for your program to communicate
with the Windows / Linux APIs.
## Windows
```
>>[[
    Entry Point Examples for windows
]]

>>[[
    Interface With the Windows api
]]
>> The System's default call.
win wtdl(string command) {
    assrt(command);
}

>> If the system runs `cls`, It fires this function.
msvc oncls() {
    assrt(3)
}

```
## Linux
```
>>[[
    Entry Examples For Linux / Ubuntu Systems.
]]

nix* main() {
    bash.run('printf "hello\n"');
}
```
# License
This project is licensed under multiple different
licenses.

## The SCC
The SDK-L Compiler Collection is licensed under
the GNU General Public License.
## SDK-LP
The SDK Parser is licensed under the MIT License.
## SPM
SDK Package Manager is licensed under the Apache 2.0 License
## Other
Most of SDK Is licensed under the MIT License.
# SDK Project Management File
The SDKPMF Is a file usually with the name,
`sdkSourceDir.xml`, It is parsed by the SDK
Project manager. It sets the C++ Output directory,
The Node.js Directories, Dependencies, ETC.

Using this file creates a tool.json.

here's an example of how yours should look.
```xml
<?xml version="1.0" encoding="utf-8" ?>

<!---

SDK Project Template
<https://www.github.com/Kai-Builder/SDKProjectTemplate/>

Enjoy!

-->



<project name="helloWorldAPP">

    <!-- Sets GNU Source Directory -->
    <if>
        <set type="COMPILER-DIR">C:\MinGW\bin\g++.exe</set>
    </if>

    <!--

        Allows the Build file to download local dependencies from git.

    -->
    <dependencies />
    <!--

    Runs a Build Configuration script.

    -->
    <script type="build-config">
        buildout.cfg
    </script>
    <!--

    This Part Checks if our "Dependencies" are installed.

    -->
    <dependenciescheck on="true"/>

    <sourcedir>
        src
    </sourcedir>

    <index>main.sdk</index>

    <localeversion>1.0</localeversion>
    <run>echo hello!</run>
    <if>
        <set type="SYSTEM-COMMAND">
            echo Hello! Using this app makes me happy!
        </set>
    </if>
    <!--
        REQUIRED!

        Runs the SDK.exe Binary with the file.

        If it is incorrect, Returns -1. Requires a valid binary to be present.

       Download them here <https://www.github.com/Kai-Builder/SDK-L/>

        This allows functionalities to be passed by version.
        Also allows for the SDK Code Check to be valid with valid functions.
    -->
    <set-compiler-dir>C:\sdk.exe</set-compiler-dir>
</project>

```


-----------------
This project is the work of 50+ hours. I hope you
find some sort of use out of it.