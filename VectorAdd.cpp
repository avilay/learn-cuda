#include <functional>
#include <iostream>
#include <random>

using namespace std;

std::ostream& operator<<(std::ostream& out, pair<float*, int> array)
{
    float* arr = array.first;
    int len = array.second;
    out << "[";
    for (int i = 0; i < len - 1; i++) {
        out << arr[i] << " ";
    }
    out << arr[len - 1] << "]";
    return out;
}

void add(float* x, float* y, float* z, int len)
{
    for (int i = 0; i < len; i++) {
        z[i] = x[i] + y[i];
    }
}

int main()
{
    default_random_engine generator;
    uniform_real_distribution<float> distribution(-1.0, 1.0);
    auto generate = bind(distribution, generator);

    int len;
    cout << "Enter length of array: " << endl;
    cin >> len;
    float* x = new float[len];
    float* y = new float[len];
    float* z = new float[len];

    for (int i = 0; i < len; i++) {
        x[i] = generate();
        y[i] = generate();
        z[i] = 0.0;
    }

    add(x, y, z, len);
    cout << "x = " << pair(x, len) << endl;
    cout << "y = " << pair(y, len) << endl;
    cout << "z = " << pair(z, len) << endl;

    delete[] x;
    delete[] y;
    delete[] z;
    cout << "Done" << endl;
}