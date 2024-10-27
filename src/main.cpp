#include <algorithm>
#include <iostream>
#include <string>

#include "SafetensorsReader.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <safetensors file> [-all]"
              << std::endl;
    return 1;
  }

  std::string filePath = argv[1];
  if (filePath.size() < 12 ||
      filePath.substr(filePath.size() - 12) != ".safetensors") {
    std::cerr << "Only .safetensors files are supported." << std::endl;
    return 1;
  }
  bool printAll = false;

  if (argv[2] && std::string(argv[2]) == "-all") {
    printAll = true;
  }

  SafetensorsReader reader(filePath);
  if (reader.loadMetadata()) {
    reader.printMetadata(printAll);
  } else {
    std::cerr << "Failed to load metadata." << std::endl;
    return 1;
  }

  return 0;
}
