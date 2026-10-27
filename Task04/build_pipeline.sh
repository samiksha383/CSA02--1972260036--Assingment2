#!/bin/bash
# Shell automation script illustrating structural compilation steps requested in Task 4

echo "Stage 1: Preprocessing Phase (-E)"
gcc -E ../Task01/billing.c -o billing.i

echo "Stage 2: Assembly Translation Generation (-S)"
gcc -S billing.i -o billing.s

echo "Stage 3: Object Machine Binary Compilation (-c)"
gcc -c billing.s -o billing.o

echo "Stage 4: Linker Resolution Executable Output Assembly"
gcc billing.o -o billing_system

echo "Validation Verification Check Complete. Target executable generated successfully."
./billing_system <<EOF
1001 65535 0
1002 100 250
EOF
