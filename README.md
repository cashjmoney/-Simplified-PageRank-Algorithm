# PageRank Algorithm Implementation

## Overview

This C++ program implements the PageRank algorithm using an adjacency list to represent a directed graph. The algorithm calculates the importance of nodes (webpages) based on the number and quality of links to them. The program uses power iteration to compute the PageRank values for each node over a specified number of iterations.

## Code Structure

### Header Files

- `#include <iostream>`: For input and output operations.
- `#include <string>`: To work with the `std::string` class.
- `#include <map>`: Provides the `std::map` container to store graph data.
- `#include <set>`: Provides the `std::set` container to manage unique nodes.
- `#include <vector>`: To work with the `std::vector` container for storing adjacency lists.
- `#include <iomanip>`: To format the output of floating-point numbers.

### Class: `AdjacencyList`

This class encapsulates the functionality for storing and processing the graph for the PageRank algorithm.

#### Private Members

- `map<string, float> current_ranking`: Stores the current rank of each node.
- `map<string, float> old_ranking`: Stores the previous rank of each node (used for power iteration).
- `map<string, float> hyperlink_probability`: Counts the outdegrees (number of outgoing edges) for each node.
- `map<string, vector<pair<string, float>>> graph`: Stores the adjacency list of the graph where each node points to a vector of pairs containing a destination node and the probability of following that link.
- `float node_count`: Tracks the total number of unique nodes in the graph.
- `set<string> node_unique`: Stores unique nodes in the graph.
- `set<string> to`: Stores nodes that have incoming edges (nodes that are pointed to).

#### Public Methods

- **Constructor**: Initializes an empty adjacency list.

- **`void insertion(string start, string end)`**: 
  - Inserts a directed edge from `start` to `end`.
  - Updates the unique node set and outdegree counts.
  - Ensures that no duplicate edges are inserted.

- **`void PageRank(int n)`**:
  - Executes the PageRank algorithm for `n` iterations.
  - Initializes the rank of each node to `1 / number_of_nodes`.
  - Performs power iterations to update the ranks based on the graph's structure.
  - Prints the final PageRank values for all nodes.

### `main()` Function

- **Input**:
  - First line: Number of edges in the graph (`no_of_lines`) and the number of power iterations (`power_iterations`).
  - Next `no_of_lines` lines: Pairs of strings representing directed edges (`from` -> `to`).

- **Execution**:
  - The program reads the input and constructs the graph using the `AdjacencyList` class.
  - It then calculates the PageRank values using the specified number of iterations.

### Example Usage

Given the following input:

The program constructs the graph and runs 10 power iterations to compute the PageRank values for nodes A, B, and C.

### Output

The program outputs the final PageRank values for all nodes, formatted to two decimal places.

### Sample Output

A 0.33 B 0.33 C 0.33

## Key Points

- The PageRank algorithm assigns equal probability initially and then iteratively adjusts these probabilities based on the structure of the graph.
- The number of power iterations determines the accuracy of the rank values.
- The algorithm handles edge cases where nodes have no incoming edges by assigning them a rank of 0.

## Example Command Line Execution

You can compile and run the program as follows:

```bash
g++ -std=c++11 -o pagerank pagerank.cpp
./pagerank
