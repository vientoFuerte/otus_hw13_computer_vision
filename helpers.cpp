#include "helpers.h"

#include <fstream>
#include <sstream>
#include <iterator>

namespace mnist {

Eigen::MatrixXf read_mat_from_stream(size_t rows, size_t cols, std::istream& stream) {
    Eigen::MatrixXf res(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            float val;
            stream >> val;
            res(i, j) = val;
        }
    }
    return res;
}

Eigen::MatrixXf read_mat_from_file(size_t rows, size_t cols, const std::string& filepath) {
    std::ifstream stream{filepath};
    return read_mat_from_stream(rows, cols, stream);
}

bool read_features(std::istream& stream, Classifier::features_t& features) {
    std::string line;
    std::getline(stream, line);

    features.clear();
    std::istringstream linestream{line};
    double value;
    while (linestream >> value) {
        features.push_back(value);
    }
    return stream.good();
}

/* Тоже самое что и read_features(), но считывает первое число отдельно - метку для сравнения, а остальное будут признаки. */
bool read_features_with_label(std::istream& stream, mnist::Classifier::features_t& features, int& label){

    std::string line;
    std::getline(stream, line);

    //нашли первую метку
    size_t comma_pos = line.find(",");
    std::string labelStr = line.substr(0, comma_pos);
    label = std::stoi(labelStr);

    // признаки от запятой и до конца строки
    std::string featuresStr = line.substr(comma_pos + 1);
    features.clear();
    std::istringstream linestream{featuresStr};
    double value;
    while (linestream >> value) {
        features.push_back(value);
    }
    return stream.good();
}

std::vector<float> read_vector(std::istream& stream) {
    std::vector<float> result;

    std::copy(std::istream_iterator<float>(stream),
              std::istream_iterator<float>(),
              std::back_inserter(result));
    return result;
}

}