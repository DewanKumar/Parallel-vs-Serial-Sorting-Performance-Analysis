# Parallel Sorting Performance Analysis (OS Project)

## Overview
This project aims to determine the most efficient programming technique among **Serial**, **OpenMP**, and **POSIX Threads (pthreads)** by implementing and comparing their performance on three sorting algorithms:
- Binary Insertion Sort
- Selection Sort
- Cocktail Sort

The project measures sorting times across different techniques to evaluate performance improvements achieved through parallel programming.

---

## Objective
The goal is to analyze execution time differences between sequential and parallel implementations.  
- **Serial implementation** – Standard single-threaded approach.  
- **OpenMP implementation** – Utilizes multi-core processing via OpenMP.  
- **Pthreads implementation** – Uses POSIX threads for parallelism.

---

## Features
- Three sorting algorithms implemented in three techniques (Serial, OpenMP, Pthreads).  
- Performance measurement using timers.  
- Client-server architecture for executing sorting remotely and collecting results.  
- Modular file structure for easier understanding and testing.

---

## Technologies Used
 - C / C++ for core implementation
 - OpenMP for shared-memory parallelism
 - POSIX Threads (Pthreads) for thread-level parallelism
 - Timers for performance measurement

---

## Directory & File Structure
project-root/

│

├── clients.cpp # Client-side code for sending sorting tasks to the server

├── servers.cpp # Server-side code for handling sorting tasks

├── servom2.c # Additional server implementation (optional/variant)

│

├──binary_insertion_serial.c # Binary Insertion Sort (Serial)

├── binary_insertion_openmp.c # Binary Insertion Sort (OpenMP)

├── binary_insertion_pthreads.c # Binary Insertion Sort (Pthreads)

│

├── selection_serial.c # Selection Sort (Serial)

├── selection_openmp.c # Selection Sort (OpenMP)

├── selection_pthreads.c # Selection Sort (Pthreads)

│

├── cocktail_serial.c # Cocktail Sort (Serial)

├── cocktail_openmp.c # Cocktail Sort (OpenMP)

├── cocktail_pthreads.c # Cocktail Sort (Pthreads)

│

├── Makefile # Build instructions for compiling all programs
└── README.md # Project documentation (this file)


---

## Compilation & Execution
### 1. Compile Serial Programs
```bash
gcc binary_insertion_serial.c -o bin_insert_serial
gcc selection_serial.c -o selection_serial
gcc cocktail_serial.c -o cocktail_serial
```
### 2. Compile OpenMP Programs
```bash
gcc -fopenmp binary_insertion_openmp.c -o bin_insert_openmp
gcc -fopenmp selection_openmp.c -o selection_openmp
gcc -fopenmp cocktail_openmp.c -o cocktail_openmp
```
### 3. Compile Pthreads Programs
```bash
gcc -pthread binary_insertion_pthreads.c -o bin_insert_pthreads
gcc -pthread selection_pthreads.c -o selection_pthreads
gcc -pthread cocktail_pthreads.c -o cocktail_pthreads
```
### 4. Compile Client and Server
```bash
Compile Client and Server
```
---

## Running the Project
1. Start the server:
```bash
./server
```
2. Run the client (in a separate terminal):
```bash
./client
```
3.Choose sorting technique and algorithm.
4.Observe sorting times recorded for comparison.

---

## Expected Output
 - Display of sorting time for each algorithm in different modes (Serial, OpenMP, Pthreads).
 - Comparative analysis of performance.

---

## Future Improvements
 - Add more sorting algorithms for a wider comparison.
 - Integrate a GUI for visual performance comparison.
 - Support larger datasets and distributed systems.
