#include <iostream>






int main(int argc, char* argv[])
{ 
    if (argc != 3) {
            std::cerr << "Usage: ./"<< argv[0]<<" <test.csv> <model>\n";
            std::cerr << "Example: ./" << argv[0] << " fashion_mnist_test.csv model.bin" << std::endl;
            return 1; 
    }
    

    try
    {

        double accuracy = 0;
        std::cout<<accuracy<<std::endl;
       
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

