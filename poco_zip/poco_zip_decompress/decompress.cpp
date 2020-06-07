#include<iostream>
#include<fstream>

#include<Poco/Path.h>
#include<Poco/Zip/Decompress.h>

//avoid using namespace declarations to prevent clashes.

int main(void) {
    std::string zipName = "test.zip";

    // create a path for output files
    Poco::Path path = Poco::Path(); // creates a path till current directory
    path.pushDirectory("test"); // adds a directory to path

    //  create a file decompressor object
    std::ifstream inp(zipName, std::ios::binary);
    Poco::Zip::Decompress decompressor(inp, path);

    // decompressing all files at once
    decompressor.decompressAllFiles();

    return 0;
}