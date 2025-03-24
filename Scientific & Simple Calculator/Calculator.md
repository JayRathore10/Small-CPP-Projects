# Scientific Calculator in C++

## Project Overview
This project is a console-based Scientific Calculator implemented in C++ that supports both basic arithmetic operations and advanced scientific functions. It utilizes OOP concepts like classes and inheritance, along with template functions for flexibility.

## Features
1. **Simple Calculator**
   - Addition (`+`)
   - Subtraction (`-`)
   - Multiplication (`*`)
   - Division (`/`)

2. **Scientific Calculator**
   - Trigonometric Functions: `sin`, `cos`, `tan`, `asin`, `acos`, `atan`
   - Exponential and Logarithmic Functions: `pow`, `sqrt`, `log`, `log10`
   - Mixed Operations using Variadic Templates

## Files
- `calculator.cpp` — Main source code.
- `scientific_calculator.md` — Project documentation (this file).

## How to Run
1. Compile the code using a C++ compiler:
```bash
 g++ calculator.cpp -o calculator -std=c++17
```
2. Run the executable:
```bash
./calculator
```

## Classes and Functions
- **Calculator**
  - `add(Args... args)`: Adds multiple numbers.
  - `sub(Args... args)`: Subtracts multiple numbers.
  - `mul(Args... args)`: Multiplies multiple numbers.
  - `div(Args... args)`: Divides multiple numbers (handles division by zero).

- **SciCal** (inherits from Calculator)
  - `root(num)`: Square root of a number.
  - `power(base, exp)`: Base raised to the exponent.
  - `logBase10(num)`: Logarithm to base 10.
  - `logBaseN(num)`: Natural logarithm.
  - `sinR(degree)`, `cosR(degree)`, `tanR(degree)`: Trigonometric functions.
  - `aSinR(x)`, `aCosR(x)`, `aTanR(x)`: Inverse trigonometric functions.

## Usage Instructions
1. Choose between Simple Calculator (`C/c`) or Scientific Calculator (`S/s`).
2. Enter numbers one by one, and type `=` to finish input.
3. Results are displayed immediately after computation.
4. To quit, enter `Q/q`.

## Example Usage
- **Simple Calculation:**
```
Select Operation: +
Enter numbers one by one (type '=' to finish):
5
10
=
Result: 15
```
- **Scientific Calculation:**
```
Select Operation: sin
Enter the degree:
30
Result: 0.5
```

## Dependencies
- Windows OS (uses `windows.h` for `Sleep()` function).
- C++ Standard Library (`cmath`, `vector`, `string`, `iomanip`).

## Future Enhancements
- Add support for angle modes (degrees/radians).
- Implement error handling for invalid inputs.
- Add more scientific functions.

## Author
- **Jay**

## License
This project is open-source and free to use.

---
Feel free to improve and expand this project!

