#include "tensor.h"
#include <iostream>

tensor::tensor(): _data(), _shape(),_stride() {};

tensor::tensor(float data): _data(data), _shape({}), _stride({}){}

tensor::tensor(const std::vector<float>& data): _data(data), _shape({data.size()}), _stride({1}) {}

tensor::tensor(const std::vector<std::vector<float>>& data): _shape({data.size(),data[0].size()}), _stride({data[0].size(),1}) {

    if (data.empty() || data[0].empty()) {
        throw std::invalid_argument("Cannot initialize tensor with empty data");
    }

    std::size_t n_expected_columns = data[0].size();

    //check if dimensions match, if each row has the same number of columns//
    for(const auto& row: data){
        if(row.size() != n_expected_columns)
            throw std::invalid_argument("Invalid Dimensions");
    }

    //store in row major form//
    for(const auto& i: data){
        for(const auto& j: i)
            _data.push_back(j);         
    }

}


