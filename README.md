# Algorithm Design

This repository contains exercises developed for the completion of the Algorithm Design course at ICMC-USP, using advanced C++ programming.

## Requirements

To run the exercises and test cases, you will need:

- G++
- Make

## Instructions

Each folder represents an exercise and contains a corresponding file named `main.cpp`. Therefore, when executing the commands, you must define the `EX` variable, which indicates the path to the specific exercise.

To compile:

```sh
make EX=./path
```

To run the tests cases:

```sh
make tests EX=./path
```

To execute the program:

```sh
make run EX=./path
```

To debug a result (you must add the test case number in the `IN` variable):

```sh
make debug EX=./path IN=1
```

To clean the build files:

```sh
make clean EX=./path
```
