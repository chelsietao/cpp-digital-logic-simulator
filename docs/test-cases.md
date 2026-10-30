# Manual test cases

Run each case in the terminal and compare the result. These are **manual tests** (no test framework required).

| Menu | Input | Expected output |
|---|---|---|
| 1 | A=0, B=0 | AND=0, OR=0, XOR=0, NOT A=1, NOT B=1 |
| 1 | A=1, B=1 | AND=1, OR=1, XOR=0, NOT A=0, NOT B=0 |
| 3 → 1 | 143 | 10001111 |
| 3 → 1 | 0 | 00000000 |
| 3 → 1 | 255 | 11111111 |
| 3 → 2 | 1 0 0 0 1 1 1 1 | 143 |
| 4 | A=1, B=1 | SUM=0, CARRY=1 |
| 5 | A=1, B=1, carry-in=1 | SUM=1, CARRY-OUT=1 |
| 6 | A=1111, B=0001 (one bit per prompt) | 10000 |
| 6 | A=0011, B=0101 (one bit per prompt) | 01000 |

## Suggested exercises

1. Write down why XOR is needed for an adder's SUM output.
2. Modify `truthTable()` to include both NOT A and NOT B.
3. Add an option to show an 8-bit one's complement and explain its meaning.
4. Try every full-adder input combination and verify all eight cases.
