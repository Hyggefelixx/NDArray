// NDArray.cpp
#include "NDArray.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// ���캯��
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
// ����Ԫ��ֵ
void NDArray::set(const vector<int>& indices, float value) {
    data[calculate_index(indices)] = value;
}

// ��ȡԪ��ֵ
float NDArray::get(const vector<int>& indices) const {
    return data[calculate_index(indices)];
}

// ��ӡ����
void NDArray::print() const {
    print_recursive(0, 0);
}

// ����ӷ�
NDArray NDArray::operator+(const NDArray& other) const {
    check_shape(other);
    NDArray result(shape);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

// ����˷���Ԫ�������ˣ�
NDArray NDArray::operator*(const NDArray& other) const {
    check_shape(other);
    NDArray result(shape);
    for (int i = 0; i < size; ++i) {
        result.data[i] = data[i] * other.data[i];
    }
    return result;
}

// ������������
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

// �����״�Ƿ�ƥ��
void NDArray::check_shape(const NDArray& other) const {
    if (shape != other.shape) {
        throw std::invalid_argument("Shapes do not match");
    }
}

// �ݹ��ӡ����
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

// ����ά�ȵĲ���
int NDArray::calculate_stride(int dim) const {
    int stride = 1;
    for (int i = shape.size() - 1; i > dim; --i) {
        stride *= shape[i];
    }
    return stride;
}


