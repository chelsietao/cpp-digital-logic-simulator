
#include <iostream>
using namespace std;

// All input bits must be 0 or 1.
int readBit()
{
    int bit;

    while (true)
    {
        cin >> bit;

        if (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter 0 or 1: ";
        }
        else if (bit == 0 || bit == 1)
        {
            return bit;
        }
        else
        {
            cout << "Please enter 0 or 1: ";
        }
    }
}

// Basic Logic Gates
int andGate(int a, int b)
{
    return a && b;
}

int orGate(int a, int b)
{
    return a || b;
}

int notGate(int a)
{
    return !a;
}

int xorGate(int a, int b)
{
    return a != b;
}

// Logic Gates
void logicGates()
{
    cout << "A (0 or 1): ";
    int a = readBit();

    cout << "B (0 or 1): ";
    int b = readBit();

    cout << "AND: " << andGate(a, b) << '\n';
    cout << "OR : " << orGate(a, b) << '\n';
    cout << "XOR: " << xorGate(a, b) << '\n';
    cout << "NOT A: " << notGate(a) << '\n';
    cout << "NOT B: " << notGate(b) << '\n';
}

// Truth Table
void truthTable()
{
    cout << "A B | AND OR XOR | NOT A\n";
    cout << "-------------------------\n";

    for (int a = 0; a <= 1; a++)
    {
        for (int b = 0; b <= 1; b++)
        {
            cout << a << ' ' << b << " |  " << andGate(a, b)
                 << "   " << orGate(a, b) << "   " << xorGate(a, b)
                 << "  |   " << notGate(a) << '\n';
        }
    }
}

// Decimal to Binary
void decimalToBinary()
{
    int number;

    cout << "Decimal number (0-255): ";
    cin >> number;

    if (!cin || number < 0 || number > 255)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input.\n";
        return;
    }

    int bits[8];
    int remainder = number;

    for (int i = 7; i >= 0; i--)
    {
        bits[i] = remainder % 2;
        remainder = remainder / 2;
    }

    cout << "8-bit binary: ";

    for (int i = 0; i < 8; i++)
    {
        cout << bits[i];
    }

    cout << '\n';
}

// Binary to Decimal
void binaryToDecimal()
{
    int bits[8];

    cout << "Enter 8 bits from left to right.\n";

    for (int i = 0; i < 8; i++)
    {
        cout << "Bit " << (i + 1) << ": ";
        bits[i] = readBit();
    }

    int value = 0;

    for (int i = 0; i < 8; i++)
    {
        value = value * 2 + bits[i];
    }

    cout << "Decimal: " << value << '\n';
}

// Binary Converter Menu
void converter()
{
    cout << "1. Decimal to binary\n"
         << "2. Binary to decimal\n"
         << "Choice: ";

    int choice;
    cin >> choice;

    if (!cin)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid choice.\n";
        return;
    }

    if (choice == 1)
    {
        decimalToBinary();
    }
    else if (choice == 2)
    {
        binaryToDecimal();
    }
    else
    {
        cout << "Invalid choice.\n";
    }
}

// Half Adder
void halfAdder(int a, int b, int result[2])
{
    result[0] = xorGate(a, b);
    result[1] = andGate(a, b);
}

// Full Adder
void fullAdder(int a, int b, int carryIn, int result[2])
{
    int first[2], second[2];

    halfAdder(a, b, first);
    halfAdder(first[0], carryIn, second);

    result[0] = second[0];
    result[1] = orGate(first[1], second[1]);
}

// Run Half Adder
void runHalfAdder()
{
    cout << "A: ";
    int a = readBit();

    cout << "B: ";
    int b = readBit();

    int result[2];

    halfAdder(a, b, result);

    cout << "SUM=" << result[0]
         << " CARRY=" << result[1] << '\n';
}

// Run Full Adder
void runFullAdder()
{
    cout << "A: ";
    int a = readBit();

    cout << "B: ";
    int b = readBit();

    cout << "Carry-in: ";
    int carryIn = readBit();

    int result[2];

    fullAdder(a, b, carryIn, result);

    cout << "SUM=" << result[0]
         << " CARRY-OUT=" << result[1] << '\n';
}

// 4-bit Binary Adder
void fourBitAdder()
{
    int a[4], b[4], sum[4];

    cout << "Enter A's 4 bits (MSB first):\n";

    for (int i = 0; i < 4; i++)
    {
        cout << "A[" << i << "]: ";
        a[i] = readBit();
    }

    cout << "Enter B's 4 bits (MSB first):\n";

    for (int i = 0; i < 4; i++)
    {
        cout << "B[" << i << "]: ";
        b[i] = readBit();
    }

    int carry = 0;

    for (int i = 3; i >= 0; i--)
    {
        int result[2];

        fullAdder(a[i], b[i], carry, result);

        sum[i] = result[0];
        carry = result[1];
    }

    cout << "Result (5 bits): " << carry;

    for (int i = 0; i < 4; i++)
    {
        cout << sum[i];
    }

    cout << '\n';
}

// Main Program
int main()
{
    while (true)
    {
        cout << "\n=== DIGITAL LOGIC SIMULATOR ===\n"
             << "1. Logic Gates\n"
             << "2. Truth Table\n"
             << "3. Binary Converter\n"
             << "4. Half Adder\n"
             << "5. Full Adder\n"
             << "6. 4-bit Adder\n"
             << "0. Exit\n"
             << "Choose: ";

        int choice;
        cin >> choice;

        if (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice.\n";
            continue;
        }

        if (choice == 0)
        {
            break;
        }

        if (choice == 1)
        {
            logicGates();
        }
        else if (choice == 2)
        {
            truthTable();
        }
        else if (choice == 3)
        {
            converter();
        }
        else if (choice == 4)
        {
            runHalfAdder();
        }
        else if (choice == 5)
        {
            runFullAdder();
        }
        else if (choice == 6)
        {
            fourBitAdder();
        }
        else
        {
            cout << "Unknown menu option.\n";
        }
    }

    cout << "Goodbye!\n";

    return 0;
}
