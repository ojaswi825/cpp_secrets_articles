#include<iostream>
#include<fstream>

#include<Poco/File.h>
#include<Poco/Path.h>
#include<Poco/Zip/Compress.h>


//avoid using namespace declarations to prevent clashes.

int main(void) {

    std::string zipName = "test.zip";

    // create a file compressor object
    std::ofstream out(zipName, std::ios::binary);
    Poco::Zip::Compress compressor(out, true);  //second arg is seekableOut (set to true for small and local files)

    // create suitable file objects
    Poco::File f1("file1.txt");
    Poco::File f2("file2.txt");

    // create path objects from file objects
    Poco::Path p1 = f1.path();
    Poco::Path p2 = f2.path();


    // verifying and adding file 1
    if (f1.isDirectory()) {
        std::cout << "Ignored directory: " << f1.path() << std::endl;
    }
    else if (f1.isFile()) {
        std::cout << "Added file " << f1.path() << " to " << zipName << std::endl;
        compressor.addFile(p1, p1.getFileName());
    }

    // verifying and adding file 2
    if (f2.isDirectory()) {
        std::cout << "Ignored directory: " << f2.path() << std::endl;
    }
    else if (f2.isFile()) {
        std::cout << "Added file " << f2.path() << " to " << zipName << std::endl;
        compressor.addFile(p2, p2.getFileName());
    }

    // finalize the zip file
    compressor.close();
    out.close();
    
    return 0;
}
