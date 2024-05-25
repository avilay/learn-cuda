#include <functional>
#include <iostream>
#include <random>

using namespace std;

void add(float x[], float y[], float z[], int len)
{
    for (int i = 0; i < len; i++) {
        z[i] = x[i] + y[i];
    }
}

void print(float arr[], int len)
{
    cout << "[";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int main()
{
    default_random_engine generator;
    uniform_real_distribution<float> distribution(-1.0, 1.0);
    auto generate = bind(distribution, generator);

    size_t len = 3;

    float x[len] {};
    float y[len] {};
    float z[len] {};

    for (int i = 0; i < len; i++) {
        x[i] = generate();
        y[i] = generate();
    }

    add(x, y, z, len);
    cout << "x:" << endl;
    print(x, len);
    cout << "y:" << endl;
    print(y, len);
    cout << "z:" << endl;
    print(z, len);
}