

---
 ## Inland Empire Solar Sales Travel Program

## General Description
The **Inland Empire Solar Sales Travel Program** is a C++ application designed to help solar sales representatives efficiently plan their travel routes. It computes both the shortest distances and the most cost-effective paths between four cities in the Inland Empire: Riverside, Moreno Valley, Perris, and Hemet. The program uses **Dijkstra's algorithm** to determine optimal paths for distance and cost and provides clear, formatted output for easy interpretation.

---

## Programming Approaches
- **Dijkstra's Algorithm**: Used for calculating the shortest path based on distance and cost.
- **Adjacency Matrices**: Represent the distances (in miles) and costs (in dollars) between cities.
- **Templates**: Allow flexibility in handling matrices with both integer and floating-point values.
- **Formatted Output**: Ensures user-friendly display of results using `iomanip` for alignment and precision.
- **Input Validation**: Prevents invalid inputs to ensure program stability.
- **Path Tracing**: Builds the optimal path dynamically and displays the route along with the total metric (distance/cost).

---

## Authors
- Vincent Rosales 
- Daniel Rios

---

## Date Published
December 8, 2024

---

## How to Use the Program

### Prerequisites
- A C++ compiler (e.g., g++, clang++) installed on your system.

### Compilation
Run the following command to compile the program:
```bash
g++ -o travel_program travel_program.cpp
```

### Execution
Run the compiled program:
```bash
./travel_program
```

### Instructions
1. Upon running, the program displays the list of cities along with their indices.
2. Enter the index of your starting city (a number between 0 and 3).
3. The program will output:
   - The distance matrix (miles) and cost matrix (dollars).
   - The shortest paths based on distance and cost from your selected starting city.
   - A step-by-step breakdown of the optimal routes.

---

## Example Run
### Input:
```
Enter the number of the starting city: 1
```

### Output:
```
Results for Shortest Distance from Moreno Valley:
Destination     Distance/Cost   Path
Riverside       16.00           Moreno Valley -> Riverside
Moreno Valley   0.00            Moreno Valley
Perris          18.00           Moreno Valley -> Perris
Hemet           26.00           Moreno Valley -> Hemet

Results for Lowest Cost from Moreno Valley:
Destination     Distance/Cost   Path
Riverside       2.40            Moreno Valley -> Riverside
Moreno Valley   0.00            Moreno Valley
Perris          2.70            Moreno Valley -> Perris
Hemet           4.35            Moreno Valley -> Hemet
```

---

## File Structure
- **`travel_program.cpp`**: Contains the complete source code of the program.

---

## Notes
- The distance and cost matrices are fully customizable to add more cities or adjust the values.
- Ensure valid input (a number between `0` and `3`) when selecting the starting city to avoid errors.

---

