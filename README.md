# Student Database (C)

A command-line student management system written in C, built to practice core programming concepts like pointers, dynamic memory, linked lists, and file I/O.

---

## Features

- Add students with unique IDs  
- Remove students  
- Edit student name and GPA (with confirmation loop)  
- Search students by name or ID  
- List all students  
- Save students to file  
- Load students from file  
- Handles malformed file input safely  

---

## How to Compile

From the project root:

Bash

gcc src/main.c src/student.c lib/src/input.c -Iinclude -Ilib/include -o studentdb.exe

---

Example file to load

Alice Johnson,1000,3.80

Bob Smith,1001,2.95

Charlie Brown,1002,3.25
