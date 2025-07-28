#pragma once
#include <vector>

class tensor{
    private:
        std::vector<float> _data; //not using pointers since vectors dynamically allocate already 
        std::vector<std::size_t> _shape;
        std::vector<std::size_t> _stride;

    public:
        tensor();
        tensor(float); //scalar
        tensor(const std::vector<float>&); //1D or vector
        tensor(const std::vector<std::vector<float>>&); //2D or matrix
};