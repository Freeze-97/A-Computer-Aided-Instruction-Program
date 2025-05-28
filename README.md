# 🖥️ Computer-Aided Instruction (CAI) Program

This C program is a simple command-line based learning tool that helps students practice and test their skills in basic arithmetic: addition, subtraction, and a mix of both. It provides two main modes—**Practice** and **Test**—with randomized questions and motivational feedback for correct or incorrect answers.

## Features

- **Personalized greeting**: Prompts the user to enter their name for a more personal experience.
- **Practice Mode**: 
  - Choose to practice **Addition**, **Subtraction**, or both.
  - Each practice session contains **10 questions**.
  - Users can retry incorrect answers until they get them right.
  - Randomized encouraging or corrective feedback is given.
- **Test Mode**:
  - Choose to test on **Addition**, **Subtraction**, or both.
  - Each test session contains **15 questions**.
  - Results include a **score percentage** and a **summary table** showing each question, the correct answer, and the user’s answer.

## How It Works

When you run the program:
1. You are greeted and asked to enter your name.
2. You can choose:
   - `1`: Do practice exercises
   - `2`: Take a test
   - `3`: Quit the program

## Compilation & Execution

To compile:
```bash
gcc -o cai cai.c
```
To run:
```bash
./cai
```


