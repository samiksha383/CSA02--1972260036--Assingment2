#include "../Task01/billing.h"

/* Reference Implementation for Task 2 Focus Areas */
int main(void) {
    BillRecord record;
    int scan_status;

    printf("%-12s %-12s %-12s\n", "ConsumerID", "PrevRead", "CurrRead");
    printf("----------------------------------------\n");

    /* Using return value of scanf to validate inputs robustly */
    while ((scan_status = scanf("%u %hu %hu", &record.consumer_id, &record.prev_reading, &record.curr_reading)) != EOF) {
        if (scan_status != 3) {
            fprintf(stderr, "[ERROR] Malformed input row encountered. Clearing line buffers.\n");
            int ch;
            /* Clear line buffer to recover gracefully from invalid character inputs */
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        /* Mock calculations for IO demonstration */
        record.total_bill_paise = 16250; // Mock value: Rs 162.50

        /* Split output into Rupees and Paise cleanly from pure integer variables */
        long long rupees = record.total_bill_paise / 100;
        long long paise = record.total_bill_paise % 100;

        /* Print formatting forces a 2-digit paise pad */
        printf("%-12u %-12u %-12u -> Rs %lld.%02lld\n",
               record.consumer_id, record.prev_reading, record.curr_reading, rupees, paise);
    }
    return 0;
}
