#ifndef BILLING_H
#define BILLING_H

#include <stdio.h>

/* Constants representing fixed charges and slab thresholds/rates */
/* All monetary values are maintained strictly in integer paise to avoid floating-point drift */
#define FIXED_CHARGE_PAISE 5000         /* Rs 50.00 */
#define SLAB1_LIMIT 100
#define SLAB2_LIMIT 200

#define SLAB1_RATE_PAISE 0              /* First 100 units: Free */
#define SLAB2_RATE_PAISE 225            /* Next 100 units: Rs 2.25 per unit */
#define SLAB3_RATE_PAISE 450            /* Above 200 units: Rs 4.50 per unit */

#define MAX_METER_VALUE 65535           /* 16-bit meter rollover limit */

/* Structure to hold billing transaction details */
typedef struct {
    unsigned int consumer_id;
    unsigned short prev_reading;
    unsigned short curr_reading;
    unsigned int units_consumed;
    long long energy_charge_paise;
    long long total_bill_paise;
} BillRecord;

/* Function Prototypes */
unsigned int calculate_units(unsigned short prev, unsigned short curr);
long long calculate_energy_charge(unsigned int units);
void process_bill(BillRecord *record);

#endif /* BILLING_H */
