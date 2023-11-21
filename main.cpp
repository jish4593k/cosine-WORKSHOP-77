#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> vector_inner_product(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> result;
    for (size_t i = 0; i < a.size(); ++i) {
        result.push_back(a[i] * b[i]);
    }
    return result;
}

int vector_size(const std::vector<int>& v) {
    int result = 0;
    for (int value : v) {
        result += value * value;
    }
    return static_cast<int>(std::sqrt(result));
}

double cosine_similarity(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> numerator = vector_inner_product(a, b);
    int denominator = vector_size(a) * vector_size(b);

    std::cout << "> numerator   : " << numerator << std::endl;
    std::cout << "> denominator : " << denominator << std::endl;

    return static_cast<double>(numerator) / denominator;
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b = {6, 7, 8, 9, 10};

    std::vector<int> d1 = {1, 0, 1, 1};
    std::vector<int> d2 = {1, 1, 0, 1};
    std::vector<int> d3 = {1, 2, 0, 2};

    std::cout << "\n*** Cosine Similarity ***\n" << std::endl;
    std::cout << cosine_similarity(a, b) << std::endl;
    std::cout << cosine_similarity(d1, d2) << std::endl;
    std::cout << cosine_similarity(d1, d3) << std::endl;
    std::cout << cosine_similarity(d2, d3) << std::endl;

    return 0;
}
