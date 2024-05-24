// NDArray.h
#ifndef NDARRAY_H
#define NDARRAY_H

#include <vector>
using namespace std;
class NDArray {
public:
    // 构造函数
    NDArray(const vector<int>& shape);

    //根据初始值构造
    NDArray(const vector<int>& shape, const vector<float>& initData);

    // 设置元素值
    void set(const vector<int>& indices, float value);

    // 获取元素值
    float get(const vector<int>& indices) const;

    // 打印数组
    void print() const;

    // 数组加法
    NDArray operator+(const NDArray& other) const;

    // 数组乘法（元素逐个相乘）
    NDArray operator*(const NDArray& other) const;

private:
    vector<int> shape;
    vector<float> data;
    int size;

    // 计算线性索引
    int calculate_index(const vector<int>& indices) const;

    // 检查形状是否匹配
    void check_shape(const NDArray& other) const;

    // 递归打印数组
    void print_recursive(int dim, int offset) const;

    // 计算维度的步长
    int calculate_stride(int dim) const;
};

#endif // NDARRAY_H

