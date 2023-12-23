#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

template <typename T> class Graph;

template <typename T>
std::ostream &operator<<(std::ostream &os, const Graph<T> &graph);

template <typename T> class Graph {
private:
  struct Edge {
    size_t to;
    T weight;

    bool operator==(const Edge &other) const {
      return to == other.to && weight == other.weight;
    }
  };

  size_t time;
  size_t numVertices;
  bool isDirected;
  std::vector<size_t> low;
  std::vector<size_t> parent;
  std::vector<size_t> discoveryTime;
  std::vector<bool> articulationVertex;
  std::vector<std::vector<Edge>> adjList;

public:
  explicit Graph(const std::string &filename, bool directed = false);
  void addEdge(size_t from, size_t to, T weight);
  friend std::ostream &operator<< <>(std::ostream &os, const Graph &graph);
  void readGraphFromFile(const std::string &filename);
  std::string toDot() const;

  std::vector<std::vector<T>> floydWarshall() const;
  T calculateDiameter() const;
};
