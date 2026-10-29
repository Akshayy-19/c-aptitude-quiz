# Smart Aptitude Quiz (C)

A console-based aptitude quiz written in C. It asks 10 multiple-choice questions and reports the student's score, percentage, performance message, and grade.

## Features
- Student name entry
- 10 multiple-choice aptitude questions
- Input validation for menu choices and answers
- Score and percentage calculation
- Performance category and grade

## Files
- `main.c` — source code for the quiz

## Compile and run

### GCC (Windows with MinGW, Linux, or macOS)
Open a terminal in this folder and run:

```bash
gcc main.c -o aptitude-quiz
```

On Windows, run:

```bash
aptitude-quiz.exe
```

On Linux/macOS, run:

```bash
./aptitude-quiz
```

Alternatively, open `main.c` in your preferred C IDE and build/run it.

## Notes
- This is a console application; it does not save quiz attempts to a file or database.
- The question bank is currently defined in `main.c`.
