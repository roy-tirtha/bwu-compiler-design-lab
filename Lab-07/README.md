# 🚚 Lab 07: Pass 2 Direct-Linking Loader

This lab demonstrates the basic address modification step used by **Pass 2 of a direct-linking loader**. The program uses an **ESTAB (External Symbol Table)** to find a symbol address and then adds or subtracts that address from a current address.

> 📌 **Important:** The current C program is an interactive demonstration of ESTAB lookup and address modification. It does not yet read complete object-program records such as `H`, `D`, `R`, `T`, or `M` records.

## 🧠 What Is a Direct-Linking Loader?

When a program is assembled, the final memory address of every external symbol may not be known. A direct-linking loader loads the program into memory and resolves these addresses while loading it.

The work is commonly divided into two passes:

### 1️⃣ Pass 1: Build ESTAB

Pass 1 reads the object modules and creates an **External Symbol Table**. Each entry contains:

| Symbol | Address |
| --- | ---: |
| `SUM` | `1200` |
| `COUNT` | `2500` |

### 2️⃣ Pass 2: Modify Addresses

Pass 2 uses the symbol address from ESTAB to modify an address in the object code.

For example:

```text
Current address = 4000
Operation       = +
Symbol address  = 1200

Modified address = 4000 + 1200 = 5200
```

The program in this folder focuses on this second step.

## ✅ Learning Objectives

- Understand the purpose of an ESTAB.
- Search for a symbol in a table.
- Resolve a symbol to its numeric address.
- Perform address relocation using `+` or `-`.
- Compile and run a C program from the terminal.

## 📁 File in This Lab

```text
pass2_dirrect-linking-loader.c
```

The filename contains the spelling `dirrect`, but it is kept unchanged so the source file and these instructions match.

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

Open a terminal in the `Lab-07` directory and run:

```bash
clang -Wall -Wextra -std=c11 pass2_dirrect-linking-loader.c -o loader
./loader
```

On Linux, the same source can be compiled with GCC:

```bash
gcc -Wall -Wextra -std=c11 pass2_dirrect-linking-loader.c -o loader
./loader
```

## ⌨️ Input Instructions

The program asks for five types of input:

1. **Number of symbols in ESTAB**: how many symbol-address entries you will provide.
2. **Symbol and address**: enter a symbol name followed by its integer address.
3. **Current address value**: the address that must be modified.
4. **Operation**: enter `+` to add or `-` to subtract the symbol address.
5. **Symbol name**: enter the symbol whose address should be used.

Use a symbol name without spaces, such as `SUM` or `BUFFER`.

## 🧪 Example: Symbol Found

```text
Enter number of symbols in ESTAB: 2

Enter ESTAB entries:
Enter symbol and address: SUM 1200
Enter symbol and address: COUNT 2500

Enter current address value: 4000
Enter operation (+ or -): +
Enter symbol name: SUM

Modified Address = 5200
```

The calculation is:

```text
4000 + 1200 = 5200
```

## ➖ Example: Subtraction

```text
Enter number of symbols in ESTAB: 1

Enter ESTAB entries:
Enter symbol and address: BUFFER 800

Enter current address value: 3000
Enter operation (+ or -): -
Enter symbol name: BUFFER

Modified Address = 2200
```

The calculation is:

```text
3000 - 800 = 2200
```

## ⚠️ Common Problems

- **`Symbol not found in ESTAB.`**: Check spelling and capitalization. `SUM` and `sum` are different strings in C.
- **`Invalid operation!`**: Enter only `+` or `-`.
- **Compiler not found**: Install the macOS Command Line Tools or use a C compiler available on your system.
- **Unexpected input**: Enter the address as a whole number and do not put spaces inside a symbol name.

## 🔍 How the Code Works

1. An array of `ESTAB` structures stores symbol names and addresses.
2. A loop reads the ESTAB entries from the user.
3. Another loop compares the requested symbol with each stored symbol using `strcmp()`.
4. When the symbol is found, its address is added to or subtracted from the current value.
5. The program prints the modified address or reports that the symbol was not found.

## 🚀 Possible Improvements

To turn this demonstration into a complete Pass 2 loader, you could add:

- Reading object-program files instead of manual input.
- Processing header, definition, text, modification, and end records.
- Hexadecimal address handling.
- Validation for negative symbol counts and oversized ESTAB tables.
- A separate Pass 1 program that builds ESTAB automatically.

## 📚 Key Terms

- **ESTAB**: External Symbol Table containing symbol names and addresses.
- **Relocation**: Adjusting addresses when a program is loaded at a new memory location.
- **External symbol**: A symbol defined in one object module and used by another.
- **Pass 2**: The loader pass that resolves references and modifies addresses.
- **Direct linking**: Resolving external references while loading and linking object modules.

Happy learning! 🎓
