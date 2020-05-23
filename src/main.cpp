
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "CdBG.hpp"

int main(int argc, const char** argv)
{
    std::string refs(argv[1]);
    uint16_t k(std::atoi(argv[2]));
    std::string output_file(argv[3]);

    if(argc != 4)
    {
        std::cerr << "Command format: cuttlefish <ref_file> <k> <out_file>\n";
        std::exit(EXIT_FAILURE);
    }


    std::cout << "Constructing compacted de Bruijn graph for references at " << argv[1] << ", with k = " << k << "\n";


    CdBG cdbg(refs, k);

    // Classify the vertices.
    cdbg.construct(output_file);

    // For debugging.
    cdbg.print_vertices();


    return EXIT_SUCCESS;
}