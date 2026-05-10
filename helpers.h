#include <istream>
#include <string>

#include <Eigen/Dense>

#include <mnist/classifier.h>

namespace mnist{

/*  Читает матрицу из потока (файла) */
Eigen::MatrixXf read_mat_from_stream(size_t rows, size_t cols, std::istream& );

/*  Читает матрицу из файла */
Eigen::MatrixXf read_mat_from_file(size_t rows, size_t cols, const std::string&);

/* читает одну строку из файла и преобразует её в вектор признаков. */
bool read_features(std::istream& stream, mnist::Classifier::features_t& features);

/* читает одну строку из файла и преобразует её в вектор признаков. */
bool read_features_with_label(std::istream& stream, mnist::Classifier::features_t& features, int& label);

/*  читает все числа из потока, складывает в вектор. */
std::vector<float> read_vector(std::istream&);

}