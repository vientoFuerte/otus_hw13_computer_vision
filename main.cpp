#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include <Eigen/Dense>

#include "helpers.h"



int main(int argc, char* argv[]) { 
    if (argc != 3) {
        std::cerr << "Usage: "<< argv[0]<<" <test.csv> <model>\n";
        std::cerr << "Example: " << argv[0] << " test.csv logreg_coef.txt" << std::endl;
        return 1; 
    }
    
    try {
        std::string testFile = argv[1];
        std::string modelFile = argv[2];
        
        // Загружаем модель
        Eigen::MatrixXf model = mnist::read_mat_from_file(10, 785, modelFile);
        
        // Загружаем тестовые данные
        std::ifstream test_file(testFile);
        if (!test_file.is_open()) {
            throw std::runtime_error("Cannot open test file");
        }
        
        double accuracy = 0;
        std::cout<<accuracy<<std::endl;

       
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
