#include <stdio.h>

int main(void) {
    printf("--- Diagnostic Demonstration of Integer Arithmetic Errors ---\n");

    /* Surprising Output 1: Truncation during integer division scaling */
    unsigned int units = 150;
    // Expected: 1.5 * 225 = 337.5 paise -> Intended 337 paise
    long long energy_charge_1 = (units / 100) * 225; 
    printf("Surprise 1 (Truncation): units/100 * 225 = %lld paise (Lost fractional units!)\n", energy_charge_1);

    /* Surprising Output 2: 32-bit Integer Overflow before 64-bit Assignment */
    int rate = 450;
    int scale_houses = 5000000; 
    long long total_overflow = rate * scale_houses; 
    printf("Surprise 2 (Overflow): rate * scale_houses = %lld (Truncated by 32-bit container math!)\n", total_overflow);

    /* Surprising Output 3: Unsigned Underflow Wraparound */
    unsigned short current = 10;
    unsigned short previous = 20;
    unsigned int usage = current - previous; 
    printf("Surprise 3 (Underflow): 10 - 20 in unsigned space = %u (Hardware wraparound!)\n", usage);

    return 0;
}
