#include <iostream>
#include <map>

int main() {
    // Declare a map with int keys and string values
    std::map<int, std::string> orderedMap;

    // Insert elements into the map
    orderedMap[3] = "Three";
    orderedMap[1] = "One";
    orderedMap[4] = "Four";
    orderedMap[2] = "Two";

    // Iterate over the map and print its elements
    for (const auto& pair : orderedMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return 0;
}
