# C++ Print Statement Debugger
A convenient C++ print debugger that has the capability to log statements in a variety of formats and colors. Uses a counter system to log the number of statements printed. 

## Usage

Firstly, you have to create a new `Debug` object. Then you are free to use the methods. I'd recommend the debugger to have a global scope so you aren't re-allocating the memory for the object multiple times.
```c++
Debug* debugger = new Debug();
	debugger->NormalPrint("NormalPrint\n");
	debugger->GreenPrint("GreenPrint\n");
	debugger->RedPrint("RedPrint\n");
	debugger->GreyPrint("GreyPrint\n");
	debugger->RandomPrint("RandomPrint\n");
	debugger->BadOutput("BadOutput\n");
	debugger->GoodOutput("GoodOutput\n");
	debugger->RandomPrintNoLog("RandomPrintNoLog\n");
	debugger->PrintAddressNoLog("PrintAddressNoLog\n");
	debugger->printf("printf\n");
```
One instance of the code block above appears like:
![debug outputs](https://user-images.githubusercontent.com/52811202/126396448-1047c1df-ab5b-4e64-9250-7a8c4b9bf7a2.png)
