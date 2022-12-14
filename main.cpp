#include <iostream>

namespace MyArray {

    class Array;
    class Int;

    class Array {
        friend class Int;

        int dim;
        int *size;

        struct data {
            int* location;
            int num;
        };

        data* start;

    public:
        Array(int dim, int *size) : dim(dim), size(size) {

            int capacity = size[0];
            for(int i = 1; i < dim; i++) {
                capacity *= size[i];
            }

            start = new data[capacity];
        }

        Int operator[](const int index);
    };

    class Int {
        int depth;

        Array* arr;
        data* target;

    public:
        Int(int index, int depth, Array* arr) : depth(depth), arr(arr) {
        }

        Int operator[](const int index) {
            return Int(index, depth + 1, arr);
        }

        operator int() {
            return target->num;
        }
    };

    Int Array::operator[](const int index) {
        Int temp = Int(index, 1, this);

        return temp; //반환
    }
}

int main() {

}