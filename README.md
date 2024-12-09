

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
Welcome to the Inland Empire Solar Sales Travel Program!
Here are the cities:
0: Riverside
1: Moreno Valley
2: Perris
3: Hemet
Enter the number of the starting city: 0

Adjacency Matrix of Distances:
Distances (Miles):

                     Riverside  Moreno Valley         Perris          Hemet
---------------------------------------------------------------------------
      Riverside              0             16             24             33
  Moreno Valley             16              0             18             26
         Perris             24             18              0             30
          Hemet             33             26             30              0


Adjacency Matrix of Costs:
Costs (Dollars):

                     Riverside  Moreno Valley         Perris          Hemet
---------------------------------------------------------------------------
      Riverside           0.00           2.40           3.60           4.95
  Moreno Valley           2.40           0.00           2.70           4.35
         Perris           3.60           2.70           0.00           4.80
          Hemet           4.95           4.35           4.80           0.00


Calculating shortest paths...
Results for Shortest Distance (in miles) from Riverside:
------------------------------------------------------------
Destination    Distance/Cost  Path
------------------------------------------------------------
Riverside      0.00           Riverside
Moreno Valley  16.00          Riverside -> Moreno Valley
Perris         24.00          Riverside -> Perris
Hemet          33.00          Riverside -> Hemet


Calculating most cost-effective paths...
Results for Lowest Cost (in U.S dollars) from Riverside:
------------------------------------------------------------
Destination    Distance/Cost  Path
------------------------------------------------------------
Riverside      0.00           Riverside
Moreno Valley  2.40           Riverside -> Moreno Valley
Perris         3.60           Riverside -> Perris
Hemet          4.95           Riverside -> Hemet
```

---

## File Structure
- **`travel_program.cpp`**: Contains the complete source code of the program.

---

## Notes
- The distance and cost matrices are fully customizable to add more cities or adjust the values.
- Ensure valid input (a number between `0` and `3`) when selecting the starting city to avoid errors.

---

