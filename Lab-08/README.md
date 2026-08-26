# 📝 Simple Text Editor

A beginner-friendly **C program** that simulates basic text editing operations using strings and character arrays.  
It allows users to insert, delete, and display characters, words, and sentences through a simple menu.

---

## ✨ Features

```text
┌─────────────────────────────────────┐
│        📝 SIMPLE TEXT EDITOR        │
├─────────────────────────────────────┤
│ ✏️ Insert Character                 │
│ ❌ Delete Character                 │
│ 🔤 Insert Word                      │
│ 🗑️ Delete Word                     │
│ 📄 Insert Sentence                  │
│ ✂️ Delete Sentence                  │
│ 👀 Display Current Text             │
│ 🚪 Exit                             │
└─────────────────────────────────────┘
```

---

## 🔄 How It Works

```text
              ┌───────────────┐
              │  🚀 Start      │
              └───────┬───────┘
                      ↓
             ┌─────────────────┐
             │  📋 Show Menu   │
             └────────┬────────┘
                      ↓
             ┌─────────────────┐
             │  🎯 Select      │
             │    Operation    │
             └────────┬────────┘
                      ↓
          ┌───────────┼───────────┐
          ↓           ↓           ↓
       ✏️ Insert   ❌ Delete    👀 Display
          │           │           │
          └───────────┼───────────┘
                      ↓
             ┌─────────────────┐
             │  📝 Updated Text│
             └────────┬────────┘
                      ↓
                ┌───────────┐
                │ 🚪 Exit?  │
                └─────┬─────┘
                      │
               No ────┴──── Yes
                ↓            ↓
             📋 Menu        🛑 End
```

---

## 🛠️ Technologies Used

- 💻 **C**
- ⚡ **Clang / GCC**
- ⌨️ **Terminal**

---

## 📁 Project Structure

```text
Lab-08/
│
├── 📝 text_editor.c
└── 📖 README.md
```

---

## ▶️ How to Run

### 1️⃣ Compile

Using **Clang**:

```bash
clang text_editor.c -o text_editor
```

Or using **GCC**:

```bash
gcc text_editor.c -o text_editor
```

### 2️⃣ Run

```bash
./text_editor
```

---

## 🎮 Input / Output

### 📝 Insert Sentence

```text
--- Simple Text Editor ---
1. Insert Character
2. Delete Character
3. Insert Word
4. Delete Word
5. Insert Sentence
6. Delete Sentence
7. Display Text
8. Exit

Enter your choice: 5
Enter sentence: Hello World
```

### 👀 Display Text

```text
Enter your choice: 7

Current Text: Hello World
```

### ❌ Delete Text

```text
Enter your choice: 6
Enter sentence to delete: World

Enter your choice: 7

Current Text: Hello
```

---

## 📌 Operations

| Operation | Purpose |
|---|---|
| ✏️ Insert Character | Add a character at a position |
| ❌ Delete Character | Remove a character |
| 🔤 Insert Word | Add a word at a position |
| 🗑️ Delete Word | Remove a word |
| 📄 Insert Sentence | Add a sentence |
| ✂️ Delete Sentence | Remove a sentence |
| 👀 Display Text | Show the current text |

---

## 🎯 Learning Objective

This project helps beginners understand:

- 🔤 Strings and character arrays
- 🔧 String functions
- ✏️ Insertion and deletion
- 📋 Menu-driven programming
- 🧠 Basic text manipulation

---



---