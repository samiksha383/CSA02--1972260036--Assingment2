# Task 3: Value Type Conversions and Precision Control

### Data Conversion Operations
* **Implicit Conversion:** Narrower variables automatically scale up to match wider target registers during evaluation (e.g., an `unsigned short` value scales up to an `unsigned int` workspace during math operations).
* **Integer Division Truncation:** Math operations like `150 / 100` drop remaining fractional parts, evaluating cleanly to `1` instead of `1.5`. In billing systems, this causes logic errors by dropping charges for partial usage blocks. Always perform multiplication steps before division to safeguard precision.

### Dissecting Arithmetic Pitfalls (Three Demonstrated Surprises)
1. **Integer Truncation:** `(150 / 100) * 225` evaluates to `225` instead of `337` because the division discards the remainder before the multiplication happens.
2. **Container Type Overflow:** `rate * scale_houses` performs the math in a 32-bit signed space before saving it to a 64-bit target, cutting off high-order binary digits.
3. **Unsigned Wraparound:** `10 - 20` using unsigned numbers evaluates to `4294967286` instead of a negative value, because unsigned types cannot represent numbers below zero.

### Consistent Rounding Rules
All calculations are scaled up and kept as whole numbers. This strategy guarantees complete accuracy to the smallest monetary unit without using floating-point rounding functions.

### Alternative Concept & Complexity Analysis
* **Floating-Point Processing Strategy (`float` calculations with single final rounding):**
  * **Error Accumulation Profile:** Standard binary floats cannot precisely store fractional base-10 decimals like `0.25`. As data scales, these small rounding discrepancies multiply across the system.
  * **Systemic Error Scaling:** Across a dataset of $N$ billing records:
    $$\text{Total System Error} \approx \sum_{i=1}^{N} \epsilon_i \propto O(N \cdot \epsilon)$$
  * For a large district with 800,000 households, an average drift of just $\pm0.1$ paise per invoice creates a significant imbalance of **Rs 800.00** every single month. Tracking balances purely as integer paise prevents this variance entirely, keeping system error at absolute zero ($O(0)$).
