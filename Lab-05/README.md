# Lab 05: Relocating Loader 🚚

This lab demonstrates the basic address modification step used by a relocating loader. The program calculates a relocation factor and uses it to change addresses before a program is loaded into memory.

> Important: This C program is a simple interactive demonstration. It takes the relocatable addresses manually instead of reading a complete object-program file. 📌

## 🧠 What Is a Relocating Loader?

When a program is assembled, it has an original starting address. The program may later be loaded at a different memory address. A relocating loader changes the address-dependent parts of the program so that it can run from the new location.

## 📐 Mathematical Concept

The relocation factor is calculated as:

```text
Relocation Factor = Loading Address - Original Starting Address
```

For every address in the program, the new address is:

```text
Relocated Address = Original Address + Relocation Factor
```

For example:

```text
Original Starting Address = 1000
Loading Address           = 3000
Relocation Factor         = 3000 - 1000 = 2000

Original Address          = 1250
Relocated Address         = 1250 + 2000 = 3250
```

## ✅ Learning Objectives

- Understand the purpose of a relocating loader.
- Calculate the relocation factor.
- Modify an address using the relocation factor.
- Use a loop to process multiple addresses.
- Compile and run a simple C program.

## 📁 File in This Lab

```text
relocating_loader.c
```

## 🛠️ Requirements

You need a C compiler. On macOS, install Xcode Command Line Tools if `clang` is not available:

```bash
xcode-select --install
```

Check that the compiler is available:

```bash
clang --version
```

## ▶️ Compile and Run

Open a terminal in the `Lab-05` directory and run:

```bash
clang -Wall -Wextra -std=c11 relocating_loader.c -o loader
./loader
```

On Linux, the same source can be compiled with GCC:

```bash
gcc -Wall -Wextra -std=c11 relocating_loader.c -o loader
./loader
```

## ⌨️ Input Instructions

The program asks for four types of input:

1. **Original starting address**: the address where the program was originally assembled.
2. **Loading address**: the new memory address where the program will be loaded.
3. **Number of relocatable addresses**: how many addresses need to be changed.
4. **Relocatable addresses**: enter each original address one by one.

Enter addresses as whole numbers, such as `1000` or `2500`.

## 🧪 Example Run

```text
Enter original starting address: 1000
Enter loading address: 3000

Relocation Factor = 2000

Enter number of relocatable addresses: 3

Enter the addresses:
1250
1500
1800
Original Address = 1250 --> Relocated Address = 3250
Original Address = 1500 --> Relocated Address = 3500
Original Address = 1800 --> Relocated Address = 3800
```

The calculations are:

```text
1250 + 2000 = 3250
1500 + 2000 = 3500
1800 + 2000 = 3800
```

## ⚠️ Common Problems

- **Wrong relocated address**: Check that the original starting address and loading address are entered correctly.
- **No output for an address**: Enter the same number of addresses given for the number of relocatable addresses.
- **Compiler not found**: Install the macOS Command Line Tools or use a C compiler available on your system.
- **Unexpected input**: Enter only whole numbers for the addresses.

## 🔍 How the Code Works

1. The program reads the original starting address and loading address.
2. It subtracts the original address from the loading address.
3. It stores the result in `relocationFactor`.
4. A `for` loop reads each relocatable address.
5. The relocation factor is added to each address.
6. The program prints both the original and relocated addresses.

## 🚀 Possible Improvements

To make this a more complete relocating loader, you could add:

- Reading addresses from an object-program file.
- Hexadecimal address handling.
- Validation for negative numbers and invalid input.
- A separate memory table to store the relocated program.
- Processing modification records automatically.

## 📚 Key Terms

- **Original address**: The address assigned when the program was assembled.
- **Loading address**: The memory address where the program is actually loaded.
- **Relocation factor**: The difference between the loading address and original starting address.
- **Relocation**: Changing address-dependent values for a new memory location.
- **Relocatable address**: An address that must be modified before loading.

## 🎯 Conclusion

The program successfully calculates the relocation factor and modifies each relocatable address so that the program can be loaded at a new memory location.
