# Compiler Design Lab — NFA & DFA

A simple **C implementation of Finite Automata** for a Compiler Design lab.

This repo contains two programs:

- 🔄 **NFA → DFA Conversion** (Subset Construction)
- 🧩 **Mini Language NFA** — recognizes identifiers, constants, and operators

---

## 📁 Project Structure

```text
Lab-o9/
├── mini_language_nfa       # Compiled executable
├── mini_language_nfa.c     # NFA for mini-language tokens
├── nfa_to_dfa              # Compiled executable
└── nfa_to_dfa.c            # NFA → DFA conversion
```

```text
.c file  →  clang  →  Executable  →  ./program  →  Output
```

> Files without `.c` are the compiled programs.
> Files ending in `.c` are the source code.

---

# 🔄 1. NFA → DFA (Subset Construction)

### Main idea

A single DFA state can represent a **set** of NFA states.

```text
NFA states            DFA states
──────────            ──────────
q0                    D0 = {q0}
q1        ───────►    D1 = {q0,q1}
q2                    D2 = {q1,q2}
```

### Process

```text
        NFA
         │
         ▼
 Take all possible transitions
         │
         ▼
 Group results into sets of NFA states
         │
         ▼
 Treat each set as ONE DFA state
         │
         ▼
 Repeat until no new sets appear
         │
         ▼
 DFA Transition Table
```

### How the code works

Transitions are stored as:

```c
nfa[state][symbol][next_state]
```

For every DFA state, the program asks:

> "From this group of NFA states, where can we go on this input symbol?"

```text
Current DFA state = {q0,q1}
Input = a

q0 --a--> q1
q1 --a--> q2
                    ⇒   {q0,q1} --a--> {q1,q2}
```

If `{q1,q2}` doesn't exist yet, it becomes a new DFA state. This repeats until nothing new is found, then the program prints the final table:

```text
DFA State       a       b
──────────────────────────
D0={q0}         D1      D2
D1={q0,q1}      D1      D3
D2={q1}         D0      D3
```

---

# 🧩 2. Mini Language NFA

Recognizes three token types:

```text
IDENTIFIER   CONSTANT   OPERATOR
```

### 👤 Identifier

Must start with a **letter or `_`**, then any mix of letters/digits/`_`.

```text
       letter / _                letter / digit / _
q0 ───────────────► q1* ───────────────────────────┐
                      ▲                             │
                      └─────────────────────────────┘
```

```c
if (isalpha(ch) || ch == '_') state = 1;      // start
if (isalnum(ch) || ch == '_') state = 1;      // continue
```

```text
student123  → IDENTIFIER
123student  → INVALID   (starts with a digit)
```

### 🔢 Constant

Integers and decimals:

```text
      digit                . 
q0 ─────────► q1* ──┬────► q2 ──digit──► q3*
                     │digit               │digit
                     └───► q1             └───► q3
```

```text
123      → CONSTANT (integer)
3.14     → CONSTANT (decimal)
```

### ➕ Operator

Single-char: `+  -  *  /  =  <  >`
Two-char (needs an extra transition step):

```text
q0 ──=──► q1 ──=──► q2*        ⇒  ==
q0 ──<──► q1 ──=──► q2*        ⇒  <=, >=, !=
```

Anything else → `INVALID TOKEN`

---

# 💻 Compile & Run

### Step 1 — Go to the folder

```bash
cd path/to/Lab-o9
ls
```

Expected:

```text
mini_language_nfa   mini_language_nfa.c
nfa_to_dfa          nfa_to_dfa.c
```

### Step 2 — Compile

```bash
clang nfa_to_dfa.c -o nfa_to_dfa
clang mini_language_nfa.c -o mini_language_nfa
```

```text
clang            →  C compiler
nfa_to_dfa.c     →  your source code
-o nfa_to_dfa    →  "output" — name the executable
```

> **Rule:** every time you edit a `.c` file, recompile it. The old executable does **not** auto-update.
> Recompiling just overwrites the old executable — no manual delete needed.

### Step 3 — Run

```bash
./nfa_to_dfa
./mini_language_nfa
```

```text
./   =  "look in the current directory"
```

---

## ▶️ Running NFA → DFA

```text
Enter number of NFA states: 3
Enter number of input symbols: 2
Enter input symbols:
a
b
Enter number of NFA transitions: 4
0 a 0
0 b 0
0 b 1
1 a 2
```

Format: `from_state  input_symbol  to_state`
→ `0 b 1` means `q0 --b--> q1`

The program then prints the equivalent DFA transition table.

---

## ▶️ Running Mini Language NFA

```text
====================================
 Mini Language NFA Recognizer
====================================
Enter a token:
```

| Input | Output |
|---|---|
| `student123` | `student123 -> IDENTIFIER` |
| `_count` | `_count -> IDENTIFIER` |
| `12345` | `12345 -> CONSTANT` |
| `3.14` | `3.14 -> CONSTANT` |
| `==` | `== -> OPERATOR` |
| `<=` | `<= -> OPERATOR` |
| `123abc` | `123abc -> INVALID TOKEN` |
| `@test` | `@test -> INVALID TOKEN` |

---

# 🧪 Quick Test Cases

| Input | Expected Result |
|---|---|
| `student` | IDENTIFIER |
| `student123` | IDENTIFIER |
| `_count` | IDENTIFIER |
| `123` | CONSTANT |
| `3.14` | CONSTANT |
| `+` | OPERATOR |
| `==` | OPERATOR |
| `<=` | OPERATOR |
| `123abc` | INVALID TOKEN |
| `@test` | INVALID TOKEN |

---

# 📚 Concepts Covered

```text
NFA · DFA · NFA → DFA Conversion · Subset Construction
Transition Tables · State Transitions · Finite Automata
Lexical Analysis · Token Recognition · C Programming
```

---

## 🎯 Lab Objective

Understand how **finite automata** are used in Compiler Design, especially during lexical analysis:

- **Program 1** shows how an NFA converts into a DFA via Subset Construction.
- **Program 2** shows how finite-state logic recognizes identifiers, constants, and operators in a mini language.

```text
NFA → DFA                          Mini Language
──────────                         ─────────────
"Many possible paths"              Input
       ↓                             ↓
"Group the possibilities"          Automaton
       ↓                             ↓
"Create deterministic states"      Identifier? / Constant? / Operator?
                                      ↓
                                    Token
```
