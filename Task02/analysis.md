# Task 2: Advanced Stream Formatting & Resilient Data Ingestion

### Format Specifiers Mapping
* `%d`: Signed 32-bit integer register.
* `%u`: Unsigned 32-bit integer register.
* `%hd` / `%hu`: Signed / Unsigned 16-bit short value (tracks values up to 65535, matching our hardware meter specifications).
* `%lld`: Signed 64-bit wide register.

### Diagnostic Evaluation of Structural Mismatches
When printing a 64-bit value using a standard `%d` placeholder, the parsing engine truncates data by extracting only the lower 32 bits from the data frame. This generates wildly inaccurate numerical outputs and corrupts downstream logs.

### Input Channel Controls
`scanf` returns an integer value representing the number of data tokens successfully matched and stored. For `scanf("%u %hu %hu")`, a valid input row returns exactly `3`. 
* If text strings are entered instead of numeric values, `scanf` stops processing immediately and returns a value less than 3.
* The remaining unparsed text stays in the input buffer, which can cause an infinite loop if left unhandled.
* This code prevents infinite loops by catching invalid returns, clearing out the bad data with a `getchar()` loop, and moving on to the next line safely.

### Accurate Monetary Formatting
To avoid floating-point rounding issues, financial balances are tracked entirely as whole integer paise. They are split into standard currency formatting only during output rendering:
```c
long long rupees = total_paise / 100;
long long paise  = total_paise % 100;
printf("Rs %lld.%02lld\n", rupees, paise);
```
Using `%02lld` ensures small single-digit balance values (like 5 paise) display correctly as `Rs 0.05` instead of incorrectly dropping digits to display as `Rs 0.5`.

### Alternative Concept & Complexity Analysis
* **Line-buffered approach (`fgets` combined with `sscanf`/`strtol`):**
  * **Time Complexity:** Runs in linear time $O(L)$ relative to line length $L$, adding a slight processing overhead because it makes two passes over the data string.
  * **Space Complexity:** Requires allocating a temporary text character array on the stack.
  * **Recovery Capacity:** Highly resilient. `fgets` reads and clears the entire invalid input line up to the newline character in a single step, cleanly resolving error recovery without needing manual stream flushes.
