// NDArray.cpp
#include "NDArray.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// 构造函数
NDArray::NDArray(const vector<int>& shape) : shape(shape) {
    size = 1;
    for (int dim : shape) {
        size *= dim;
    }
    data.resize(size, 0.0f);
}
NDArray::NDArray(const vector<int>& shape, const vector<float>& initData) :shape(shape), data(initData) {
    size = 1; 
    for (int dim : shape) { 
        size *= dim; 
    } 
    if (size != initData.size()) { 
        throw invalid_argument("Data size does not match shape size"); 
    }
}
// 设置元素值
void NDArray::set(const vector<int>& indices, float value) {
    data[calculate_index(indices)] = value;
}

// 获取元素值
float NDArray::get(const vector<int>& indices) const {
    return data[calculate_index(indices)];
}

// 打印数组
void NDArray::print() const {
    print_recursive(0, 0);
}

// 数组加法
NDArray NDArray::operator+(const NDArray& other) const {
    check_shape(other);
    NDArray result(shape);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

// 数组乘法（元素逐个相乘）
NDArray NDArray::operator*(const NDArray& other) const {
    check_shape(other);
    NDArray result(shape);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] * other.data[i];
    }
    return result;
}

// 计算线性索引
int NDArray::calculate_index(const vector<int>& indices) const {
    if (indices.size() != shape.size()) {
        throw std::out_of_range("Incorrect number of indices");
    }
    int index = 0;
    int stride = 1;
    for (int i = shape.size() - 1; i >= 0; --i) {
        if (indices[i] < 0 || indices[i] >= shape[i]) {
            throw std::out_of_range("Index out of range");
        }
        index += indices[i] * stride;
        stride *= shape[i];
    }
    return index;
}

// 检查形状是否匹配
void NDArray::check_shape(const NDArray& other) const {
    if (shape != other.shape) {
        throw std::invalid_argument("Shapes do not match");
    }
}

// 递归打印数组
void NDArray::print_recursive(int dim, int offset) const {
    if (dim == shape.size()) {
        cout << data[offset] << " ";
        return;
    }
    std::cout << "[";
    for (int i = 0; i < shape[dim]; ++i) {
        print_recursive(dim + 1, offset + i * calculate_stride(dim));
        if (i < shape[dim] - 1) {
            cout << ", ";
        }
    }
    cout << "]";
    if (dim == 0) {
        cout << std::endl;
    }
}

// 计算维度的步长
int NDArray::calculate_stride(int dim) const {
    int stride = 1;
    for (int i = shape.size() - 1; i > dim; --i) {
        stride *= shape[i];
    }
    return stride;
}


