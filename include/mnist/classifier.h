#pragma once

#include <vector>
#include <cstddef>

namespace mnist {

 /* aбстрактный базовый класс (интерфейс) для классификаторов */
class Classifier {
public:
    using features_t = std::vector<float>;  // вектор признаков (784 пикселя) 
    using probas_t = std::vector<float>;    // вектор вероятностей принадлежности к каждому классу

    virtual ~Classifier() {}

    virtual size_t num_classes() const = 0;                // Возвращает количество классов, которые умеет распознавать классификатор(10).

    virtual size_t predict(const features_t&) const = 0;   // Предсказывает номер(0-9) класса для входных признаков

    virtual probas_t predict_proba(const features_t&) const = 0;  // Возвращает вероятности для каждого класса
};


}
