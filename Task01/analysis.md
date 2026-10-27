# Task 1: Architectural Organization & Preprocessing Controls

### Structure of a C Program
* **Header Files (`.h`):** Declare structural blueprints, global constants, and function prototypes. They separate design contracts from compilation footprints.
* **Global Declarations:** Expose data types or variables globally across compilation units. This design isolates data within explicit structures to preserve code reliability.
* **Main Function:** Standard application runtime entry point handling execution cycles and data control flow.

### Include Guards Optimization
Include guards prevent type redefinition compile errors when headers are included across multiple code branches. The preprocessor evaluates the block guard condition:
```c
#ifndef BILLING_H
#define BILLING_H
// Content parsed exactly once
#endif
```
If a file pulls this header multiple times downstream, the second pass skips parsing entirely, preventing symbol redefinition errors.

### Conditional Compilation vs. Dynamic Code Blocks
Using `#ifdef DEBUG` allows developers to add diagnostic logging statements that only exist during testing.
* Compiling with `gcc -DDEBUG billing.c` includes the debugging code.
* Omitting the `-DDEBUG` flag completely removes the logging logic from the code before it is compiled into a binary.

### Key Preprocessor Differences
* `#include <file>`: Instructs the preprocessor to search for system headers inside standard environment include pathways (e.g., `/usr/include/`).
* `#include "file"`: Explicitly directs the engine to look in the local project working directory first before checking system paths.

### Alternative Concept & Complexity Analysis
* **Runtime Debug Flag Approach:** If debugging were handled via a runtime variable (`if (debug) printf(...)`):
  * **Time Complexity:** Adds an $O(1)$ branch prediction and test check execution penalty to every computation loop.
  * **Space Complexity:** Retains structural string data inside the production binary, increasing the final application image size.
  * **Trade-off Summary:** The preprocessing approach (`#ifdef DEBUG`) delivers zero runtime performance overhead ($O(0)$ time and space cost) in production environments, making it ideal for high-throughput utility automation.
