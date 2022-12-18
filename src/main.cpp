#include "Element.h"
#include "PeriodicTable.h"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

int main() {
    std::cout << "Hello World from " << std::filesystem::current_path() << "!\n";

    std::ifstream pTableFile("pTable.txt");
    PeriodicTable pTable(pTableFile);

    for (const Element &e : pTable.elements) {
        std::cout << e << "\n";
    }
}