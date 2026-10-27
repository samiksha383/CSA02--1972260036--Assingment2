# Task 4: Detailed Compilation Pipeline Analysis

### Structural Compiling Phase Diagnostics
1. `gcc -E`: **Preprocessing Phase**. The compiler expands macro values, applies include code injections, and strips away unused conditional blocks (like inactive `#ifdef DEBUG` blocks).
2. `gcc -S`: **Assembly Phase**. High-level code structures are translated into low-level processor instruction text files (`.s`).
3. `gcc -c`: **Object Compilation Phase**. Converts assembly text files into machine-readable object code modules (`.o`).
4. Linker Synthesis: **Linking Phase**. Connects system libraries and maps addresses to produce a standalone executable program.

### Error Taxonomy
* **Compile-time Error:** Occurs when language syntax rules are broken. For example, omitting a closing brace or semicolon stops compilation during the initial parsing phase.
* **Link-time Error:** Occurs when structural declarations are missing their implementation. For example, declaring a prototype like `long long calculate_energy_charge(unsigned int units);` but failing to provide the matching logic body causes a linker failure.
* **Run-time Error:** Occurs during execution. For example, attempting to divide by zero causes the operating system to immediately stop execution and throw a crash exception.

### Compiler Diagnostics & Quality Flags
Compiling with strict flags (`-Wall -Wextra`) highlights hidden runtime issues early:
* *Type Sign Warning:* Notifies the developer when comparing signed and unsigned numbers, which can be resolved by using explicit type casting.
* *Unused Asset Tracking:* Finds variables that are declared but never used, allowing developers to clean up dead code and optimize final application sizes.

### Alternative Concept & Complexity Analysis
* **Multi-Module Code Separation Architecture:**
  * **Compilation Speeds:** Splitting code into individual files like `input.c`, `tariff.c`, and `report.c` enables incremental builds. If you change a value inside `tariff.c`, only that specific file needs to be recompiled into an object file before linking the final binary. This saves considerable build time compared to compiling a single large monolithic source file from scratch.
  * **Space Footprint:** Creates multiple independent object binaries (`.o`). While this temporarily uses slightly more storage space for project metadata, it provides clear benefits for software organization, maintenance, and testing.
