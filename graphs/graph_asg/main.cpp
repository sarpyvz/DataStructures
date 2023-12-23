// main.cpp
#include "Graph.cpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  Graph<size_t> floydWarshallGraph("graphs/floydWarshallGraph.txt");

  // Generate DOT representation and save to file
  // std::string floydWarshallDotRepresentation = floydWarshallGraph.toDot();
  // std::ofstream floydWarshallOut("outputs/dots/floydWarshallGraph.dot");
  // floydWarshallOut << floydWarshallDotRepresentation;
  // floydWarshallOut.close();
  // system("dot -Tpng outputs/dots/floydWarshallGraph.dot -o "
  //        "outputs/img/floydWarshallGraph.png");

  auto distances = floydWarshallGraph.floydWarshall();

  for (const auto &row : distances) {
    for (const auto &dist : row) {
      std::cout << std::setw(5)
                << (dist == std::numeric_limits<size_t>::max()
                        ? "INF"
                        : std::to_string(dist))
                << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "Diameter: " << floydWarshallGraph.calculateDiameter()
            << std::endl;
  std::cout << std::endl;

  Graph<size_t> floydWarshallGraph2("graphs/floydWarshallGraph2.txt");

  // Generate DOT representation and save to file
  // std::string floydWarshallDotRepresentation2 = floydWarshallGraph2.toDot();
  // std::ofstream floydWarshallOut2("outputs/dots/floydWarshallGraph2.dot");
  // floydWarshallOut2 << floydWarshallDotRepresentation2;
  // floydWarshallOut2.close();
  // system("dot -Tpng outputs/dots/floydWarshallGraph2.dot -o "
  //        "outputs/img/floydWarshallGraph2.png");

  auto distances2 = floydWarshallGraph2.floydWarshall();

  for (const auto &row : distances2) {
    for (const auto &dist : row) {
      std::cout << std::setw(5)
                << (dist == std::numeric_limits<size_t>::max()
                        ? "INF"
                        : std::to_string(dist))
                << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "Diameter: " << floydWarshallGraph2.calculateDiameter();

  return 0;
}
