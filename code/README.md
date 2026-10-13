# University Campus Network Planner Using Prim’s Algorithm

## Project Overview

The **University Campus Network Planner** is a menu-driven C program that uses **Prim’s Greedy Algorithm** to find the Minimum Spanning Tree (MST) of a university campus network.

The program helps plan a minimum-cost cable network connecting campus buildings. Users can enter building names, specify distances between buildings, select a starting building, and calculate the minimum cable length and total installation cost.

The application also displays the distance matrix, compares results from different starting buildings, and checks whether the graph is connected.

## Academic Details

- **Module:** Module 3 – Greedy Method Approach
- **Algorithm:** Prim’s Algorithm
- **Subject:** Analysis of Algorithms (AOA)
- **Programming Language:** C
- **Project Type:** Menu-driven console application

## Objectives

- Create a weighted, undirected graph representing campus buildings and their connections.
- Implement Prim’s greedy choice to construct a Minimum Spanning Tree.
- Calculate the minimum total cable length and installation cost.
- Display the MST connections in parent–child format.
- Compare results obtained from different starting vertices.
- Detect disconnected graphs and warn users when all buildings cannot be connected.

## Features

1. **Create Graph:** Enter the number of buildings, their names, distances between building pairs, and cable installation rate.
2. **Display Distance Matrix:** View the distance matrix representing direct connections between buildings.
3. **Find Minimum-Cost Network:** Select a starting building and generate the MST using Prim’s Algorithm.
4. **Compare Starting Buildings:** Calculate and compare the total cable length and installation cost for every starting building.
5. **Check Connectivity:** Determine whether all buildings can be connected through the given network.
6. **Input Validation:** Reject invalid building counts, negative distances, and invalid starting-building selections.
7. **Disconnected-Graph Detection:** Display a warning if the graph does not allow all buildings to be connected.

## Algorithm: Prim’s Greedy Method

Prim’s Algorithm constructs a Minimum Spanning Tree by repeatedly selecting the minimum-weight edge that connects a visited vertex to an unvisited vertex.

### Steps

1. Create the weighted, undirected graph using an adjacency matrix.
2. Initialize the `key[]` array with infinity, the `parent[]` array with `-1`, and the `visited[]` array with `0`.
3. Set the key of the selected starting vertex to `0`.
4. Select the unvisited vertex with the smallest key value.
5. Mark the selected vertex as visited and add its key value to the total cable length.
6. Update the key and parent values of its unvisited neighbours whenever a cheaper connection is found.
7. Repeat until all vertices are included in the MST or the graph is found to be disconnected.
8. Display the selection order, MST edges, total cable length, and installation cost.

## Menu Options

| Option | Description |
|---|---|
| 1 | Create graph (buildings and distances) |
| 2 | Show distance matrix |
| 3 | Find minimum-cost network from a starting building |
| 4 | Compare results from all starting buildings |
| 5 | Check connectivity |
| 6 | Exit the program |

## Input Requirements

- Number of buildings: 2 to 20
- Building names: Single-word names; use underscores instead of spaces.
- Distances: Non-negative integers representing metres.
- Distance `0`: Indicates no direct connection between two different buildings.
- Cable installation rate: Cost per metre.
- Starting building: Selected using its menu number.

## Output

The program generates:

- The distance matrix of the campus network.
- The order in which buildings are selected by Prim’s Algorithm.
- MST edges in parent–child format.
- Total cable length in metres.
- Total installation cost based on the specified rate.
- Connectivity status and warnings for disconnected graphs.
- A comparison of total cable length and installation cost for different starting vertices.

## Time and Space Complexity

Let `V` be the number of buildings.

- **Time Complexity:** `O(V²)` for Prim’s Algorithm implemented using an adjacency matrix and a linear search for the minimum key.
- **Space Complexity:** `O(V²)` for the distance matrix, with `O(V)` additional space for the key, parent, visited, and selection-order arrays.

## Technologies Used

- C Programming Language
- Standard C Library (`stdio.h`, `string.h`)
- Graphs and Adjacency Matrices
- Greedy Algorithm
- Minimum Spanning Tree

## Applications

- University campus cable network planning
- Computer network infrastructure
- Connecting buildings with minimum cable length
- Basic network design and cost estimation
- Understanding greedy algorithms and graph theory

## Future Enhancements

- Add Kruskal’s Algorithm for comparison with Prim’s Algorithm.
- Support dynamically allocated graphs with more buildings.
- Display the campus network graphically.
- Export MST connections and cost reports to a file.
- Add support for building names containing spaces.

## Conclusion

The University Campus Network Planner demonstrates the practical application of **Prim’s Greedy Algorithm** for finding a Minimum Spanning Tree. It provides a simple way to plan connections between campus buildings while minimizing total cable length and installation cost, provided the graph is connected.


## TEAM MEMBERS
Shubham Sahni (25102B0047) ,
Saish Patil (25102B0046) ,
Tanishk Mahajan (25102B0044) ,
Pranav Arjugade (251020056)
