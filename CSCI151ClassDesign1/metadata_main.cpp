
#include "metadata.h"
#include <iostream>

int main()
{
    try
    {
        Metadata md{
            "test_name",
            "png",
            std::vector<int>{ 2020, 2, 29 },
            1.2,
            "test_author",
            std::vector<int>{ 500, 1000 },
            22,
            1000,
            3000,
            true
        };
        printMetadata(md);
    }
    catch (std::invalid_argument& e)
    {
        std::cout << e.what();
    }
}
