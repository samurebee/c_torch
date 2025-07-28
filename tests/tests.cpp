#include <iostream>
#include <gtest/gtest.h>
#include "tensor.h"


TEST(HelloTest, BasicTest){
    EXPECT_EQ(1,1);
}

TEST(TensorTest, ScalarConstructorStoresValueCorrectly){
    tensor t(3.14f);
    EXPECT_FLOAT_EQ(t.item(), 3.14f); // Floating point comparison
}

TEST(TensorTest, ScalarConstructorWithZero) {
    tensor t(0.0f);
    EXPECT_EQ(t.item(), 0.0f); // Works for exact 0
}

TEST(TensorTest,ThrowIfNotScalar){
    tensor t({0.0f,0.0f});
    EXPECT_THROW(t.item(),std::runtime_error);
}

TEST(TensorTest,ThrowIfNotScalarWith2dTensor){
    tensor t({{0.0f,0.0f},{0.0f,0.0f}});
    EXPECT_THROW(t.item(),std::runtime_error);
}

