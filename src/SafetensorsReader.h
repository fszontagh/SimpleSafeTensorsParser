#ifndef SafetensorsReader_H
#define SafetensorsReader_H
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class SafetensorsReader {
public:
  explicit SafetensorsReader(const std::string &filePath)
      : filePath(filePath) {}

  bool loadMetadata() {
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
      std::cerr << "Can not open the file: " << filePath << std::endl;
      return false;
    }

    // Első 8 byte beolvasása az N érték meghatározásához
    uint64_t metadataSize;
    file.read(reinterpret_cast<char *>(&metadataSize), sizeof(metadataSize));
    if (!file) {
      std::cerr << "Can not read metadata size from the first 8 bytes."
                << std::endl;
      return false;
    }

    // N byte beolvasása JSON metaadatként
    std::vector<char> buffer(metadataSize);
    file.read(buffer.data(), metadataSize);
    if (!file) {
      std::cerr << "Can not read metadata." << std::endl;
      return false;
    }

    // JSON elemzése
    try {
      metadata = nlohmann::json::parse(buffer.data());
    } catch (const nlohmann::json::parse_error &e) {
      std::cerr << "JSON error: " << e.what() << std::endl;
      return false;
    }

    return true;
  }

  void printMetadata(bool all = false) const {
    if (metadata.is_null()) {
      std::cout << "No metadata." << std::endl;
      return;
    }

    if (metadata.contains("__metadata__") && !all) {
      std::cout << "Metadatas: " << metadata["__metadata__"].dump(4)
                << std::endl;
    }
    if (all) {
      std::cout << "Metadatas: " << metadata.dump(4) << std::endl;
    }
  }

private:
  std::string filePath;
  nlohmann::json metadata;
};

#endif // SafetensorsReader_H