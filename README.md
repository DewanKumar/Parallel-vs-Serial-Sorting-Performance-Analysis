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

## Directory & File Structure
project-root/
│

├── clients.cpp # Client-side code for sending sorting tasks to the server
├── servers.cpp # Server-side code for handling sorting tasks
├── servom2.c # Additional server implementation (optional/variant)
│
├── binary_insertion_serial.c # Binary Insertion Sort (Serial)
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
