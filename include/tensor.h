#pragma once
#include <vector>

class tensor{
    private:
        std::vector<float> _data; //not using pointers since vectors dynamically allocate already 
        std::vector<std::size_t> _shape;

    public:
        tensor(float data); //scalar
        tensor(std::vector<float>); //1D or vector
        tensor(std::vector<std::vector<float>>); //2D or matrix

};