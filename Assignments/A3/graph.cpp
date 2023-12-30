// Graph.cpp
#include "Graph.h"
#define INF 999
#include <iostream>

/**
 * The Graph constructor reads a graph from a file.
 *
 * @param filename The filename parameter is a string that
 * represents the name of the file from which the graph
 * data will be read.
 */
template <typename T>
Graph<T>::Graph(const std::string &filename, bool directed) {
  this->isDirected = directed;
  readGraphFromFile(filename);
}

/**
 * The function adds an edge between two vertices in a graph with a specified
 * weight.
 *
 * @param from The index of the vertex from which the edge starts.
 * @param to The "to" parameter represents the destination vertex of the edge
 * being added.
 * @param weight The weight parameter represents the weight or cost associated
 * with the edge between the "from" vertex and the "to" vertex. It can be any
 * value that represents the cost or weight of the edge, such as a numerical
 * value or an object that encapsulates the weight information.
 */
template <typename T> void Graph<T>::addEdge(size_t from, size_t to, T weight) {
  adjList[from].push_back({to, weight});
  if (!this->isDirected) {
    adjList[to].push_back({from, weight});
  }
}

/**
 * The function overloads the << operator to print the graph.
 *
 * @param os The os parameter represents the output stream to which the graph
 * will be printed.
 * @param graph The graph parameter represents the graph that will be printed.
 *
 * @return The function returns the output stream to which the graph was
 * printed.
 */
template <typename T>
std::ostream &operator<<(std::ostream &os, const Graph<T> &graph) {
  os << "Graph Representation (Adjacency List):\n";
  for (int i = 0; i < graph.numVertices; ++i) {
    os << "Vertex " << i << " connects to: ";
    for (const auto &edge : graph.adjList[i]) {
      os << "[Vertex " << edge.to << " with weight " << edge.weight << "] ";
    }
    if (graph.adjList[i].empty()) {
      os << "No connections";
    }
    os << "\n";
  }
  return os;
}

/**
 * The function reads a graph from a file.
 *
 * @param filename The filename parameter is a string that
 * represents the name of the file from which the graph
 * data will be read.
 *
 * @return void
 */
template <typename T>
void Graph<T>::readGraphFromFile(const std::string &filename) {
  std::ifstream file(filename);
  std::string line;

  // Determine the number of vertices
  numVertices = 0;
  while (std::getline(file, line)) {
    numVertices++;
  }

  // Resize the adjacency list
  adjList.resize(static_cast<size_t>(numVertices));

  // Reset file read position to the beginning
  file.clear();
  file.seekg(0, std::ios::beg);

  // Read the file again to populate the graph
  size_t row = 0;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    size_t col = 0;
    T weight;
    while (iss >> weight) {
      if (weight != 0 &&
          col < numVertices) { // Check that the column number is less than the
                               // number of vertices
        addEdge(row, col, weight);
      }
      col++;
    }
    row++;
  }
}

/**
 * The function returns a string representation of the graph in DOT format.
 *
 * @return The function returns a string representation of the graph in DOT
 * format.
 */
template <typename T> std::string Graph<T>::toDot() const {
  std::ostringstream dot;
  if (this->isDirected) {
    dot << "digraph G {\n";
  } else {
    dot << "graph G {\n";
  }

  // Optional: Set graph, node, and edge attributes for better aesthetics
  dot << "  node [shape=circle];\n";
  dot << "  edge [color=gray];\n";

  // To avoid duplicating edges in an undirected graph, we'll use a set
  std::set<std::pair<int, int>> addedEdges;

  for (size_t i = 0; i < adjList.size(); ++i) {
    for (const auto &edge : adjList[i]) {
      size_t from = i;
      size_t to = edge.to;
      if (!this->isDirected) {
        // Ensure both directions of the edge are considered the same
        if (addedEdges.find({from, to}) != addedEdges.end() ||
            addedEdges.find({to, from}) != addedEdges.end()) {
          continue; // Edge already added, skip it
        }
        // Add both directions to the set to handle undirected edges
        addedEdges.insert({from, to});
        addedEdges.insert({to, from});
      }

      // Escape label to handle special characters
      std::string label = std::to_string(edge.weight);
      dot << "  " << from << (this->isDirected ? " -> " : " -- ") << to
          << " [label=\"" << label << "\"];\n";
    }
  }

  dot << "}\n";
  return dot.str();
}

template <typename T> std::vector<std::vector<T>> Graph<T>::floydWarshall() 
{
  std::vector<std::vector<T>> distance;
  for (int i =0; i < adjList.size(); i++)
  {
    for(int j = 0; j < adjList[i].size();j++){
      if ( i == j ){
        distance[i][j] == 0;
      }
      // if there is no path, assign inf to distance matrix
      // When I use adjList[i][j].weight , I wanted to reach to Graph class to edge structs weight value  
      
      // this statement looks if there is a path between two nodes if not put infinity to matrix
      if ( adjList[i][j]. weight % 2 == 0 || adjList[i][j].weight % 2 != 1 ){
        distance[i][j] = INF;
      }
      
      else{
        distance[i][j] = adjList[i][j].weight;
      }
    }
  }

  // will use 0 , 1, 2 ,3 ,4 as intermediate vertices, k does that 
  for ( int k= 0; k < numVertices; k++){
    // i is  row of distance matrix
    for (int i= 0; i< numVertices; i++){
      // j is column distance matrix
      for (int j=0; j < numVertices;j++){
        distance[i][j] = std::min(distance[i][j],distance[i][k] + distance[k][j]);
      }
    }
  }
  return distance;



}


template <typename T> T Graph<T>::calculateDiameter() 
{
  std::vector<std::vector<T>> shortest_dists = floydWarshall();
  // finding the most distanced nodes
  T most_distance_node1;
  T most_distance_node2;
  for (int i = 0; i < numVertices; i++){
    for ( int j = 0; j < numVertices; j++){
      if ( shortest_dists[i][j] > shortest_dists[most_distance_node1][most_distance_node2] ){
        most_distance_node1 = i;
        most_distance_node2 = j;
      }

    }
  }
  return shortest_dists[most_distance_node1][most_distance_node2];
  
}
// Explicit template instantiation
template class Graph<int>;
template class Graph<float>;
template class Graph<double>;
