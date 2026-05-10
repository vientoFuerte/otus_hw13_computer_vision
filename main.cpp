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
        std::string modelFile = argv[2]; //   КОЭФФИЦИЕНТЫ ДЛЯ ВСЕХ 10 КЛАССОВ
        
        // Загружаем модель 10 строк, 785 столбцов, из файла
        // Eigen::MatrixXf - матрица чисел с плавающей точкой из библиотеки Eigen.
        // model.rows()        // Количество строк (10)
        // model.cols()        // Количество столбцов (785)
        // model.size()        // Общее количество элементов (7850)
        Eigen::MatrixXf model = mnist::read_mat_from_file(10, 785, modelFile);
        std::cout << "Matrix loaded: " << model.rows() << "x" << model.cols() << std::endl;
        
        
        std::ifstream model_file(modelFile);
        if (!model_file.is_open()) {
            throw std::runtime_error("Cannot open test file");
        }
        // загрузили коэффициенты
        //auto coefs = mnist::read_vector(model_file);
        //model_file.close();

        // Загружаем тестовые данные
        std::ifstream test_file(testFile);
        if (!test_file.is_open()) {
            throw std::runtime_error("Cannot open test file");
        }
        
        int label;
        mnist::Classifier::features_t features;


        while(mnist::read_features_with_label(test_file, features, label))
        {
            // вектор из Eigen на 785 чисел float-ов, коэффициентов z = w1*x1 + w2*x2 + ... + w784*x784 + b
            Eigen::VectorXf x(785);
            x(0) = 1.0f;                 // Присваиваем первому элементу 1 тк b - свободный член
            for (size_t i = 0; i < 784; i++) {
                x(i + 1) = features[i];  // Присваиваем остальным
            }

            // Вычисляем все 10 скалярных произведений сразу: A * x
            // A (10x785) * x (785x1) = scores (10x1)
            Eigen::VectorXf scores = model * x;


        }


        // прочитала первую строку
        
        {

            // auto y_pred = predictor.predict_proba(features);

        }

       
        
        //std::cout<<label<<std::endl;

        test_file.close();


        double accuracy = 0;
        std::cout<<accuracy<<std::endl;

       
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
