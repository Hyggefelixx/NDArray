// NDArray.h
#ifndef NDARRAY_H
#define NDARRAY_H

#include <vector>
using namespace std;
class NDArray {
public:
    // ���캯��
    NDArray(const vector<int>& shape);

    //���ݳ�ʼֵ����
    NDArray(const vector<int>& shape, const vector<float>& initData);

    // ����Ԫ��ֵ
    void set(const vector<int>& indices, float value);

    // ��ȡԪ��ֵ
    float get(const vector<int>& indices) const;

    // ��ӡ����
    void print() const;

    // ����ӷ�
    NDArray operator+(const NDArray& other) const;

    // ����˷���Ԫ�������ˣ�
    NDArray operator*(const NDArray& other) const;

private:
    vector<int> shape;
    vector<float> data;
    int size;

    // ������������
    int calculate_index(const vector<int>& indices) const;

    // �����״�Ƿ�ƥ��
    void check_shape(const NDArray& other) const;

    // �ݹ��ӡ����
    void print_recursive(int dim, int offset) const;

    // ����ά�ȵĲ���
    int calculate_stride(int dim) const;
};

#endif // NDARRAY_H

