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

Attempts to compare a statement.
```c
entry(if compare, return);
```
