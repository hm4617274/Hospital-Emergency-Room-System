# Hospital Emergency Room Management System

**Language:** C++  
**Concepts:** Linked List, Queue, Priority Handling

## Project Overview
This is a console-based Hospital Emergency Room Management System developed in C++. The system simulates real-time patient handling in an emergency department, managing patients dynamically with automatic unique IDs and priority-based treatment.

## Features
- Automatic unique patient ID assignment  
- Priority-based patient handling (Critical, Serious, Normal)  
- Queue management using FIFO principle  
- Add new patients with full name and disease details  
- Treat next patient based on priority  
- Display all waiting patients  
- Search patient by unique ID  
- Dynamic memory management using linked lists  

## How It Works
1. Patients are added to the system with their details.  
2. Each patient is assigned a priority level and placed in the corresponding queue.  
3. The system treats patients based on priority: Critical → Serious → Normal.  
4. Patient details can be displayed or searched using unique ID.  
5. Treated patients are removed and memory is released.

## How to Run
1. Clone the repository.  
2. Compile the `main.cpp` file using a C++ compiler.  
   ```bash
   g++ main.cpp -o HospitalER
