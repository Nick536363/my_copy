# A simple implementation of the cp utility written in C

## About

This project represents CP command for UNIX systems in the POSIX for educational purposes. 

## Installation

To install and compile this project you'll need **Git**, **GCC** and **make**.

1. Download the repository

```bash
git clone https://github.com/Nick536363/my_copy
```

2. Change working directory

```bash
cd my_copy
```

3. Compile project using **make** or use **GCC** insted.

```bash
make
```

## Usage

The program operates according to the syntax below.

```bash
./mycp <source> <destination>
```

Here is a simple example of using this program.

```bash
$ ls
1.txt  mycp
$ ./mycp 1.txt 1_copy.txt
$ ls
1_copy.txt  1.txt  mycp
$ 
```

## Notes

This version of the program does not support recursive copying, so you will not be able to copy directories.