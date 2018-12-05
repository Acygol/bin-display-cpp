# bin-display-cpp

Concept code for an 8bit binary display using C++. The STL is used throughout!

### Example
```Cpp
#include "LedDisplay.h"

int main(void)
{
    LedDisplay display{ /* 1 to 8 pins */ };
    display.Method(); // any of the public member functions can be used
}
```
Most member functions do the printing for you. `BinConvert` does not, for example.
