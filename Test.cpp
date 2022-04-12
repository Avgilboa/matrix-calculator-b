/**
 *
 * AUTHORS: Aviad Gilboa
 * 
 * Date: 04-2022
**/ 

#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;
#include <string>
#include <algorithm>
using namespace std;


TEST_CASE("check if the matrix is legal"){
    vector<double> value = {1,0,0,0,0,
                            0,1,0,0,0,
                            0,0,1,0,0,
                            0,0,0,1,0,
                            0,0,0,0,1};
    CHECK_NOTHROW(Matrix m(value,5,5););
    CHECK_THROWS(Matrix(value,3,3););
    CHECK_THROWS(Matrix(value,5,4););
    value ={1,2,0,
            0,1,2,
            0,0,1,
            0,0,0,
            0,0,0,
            1,1,1};
    CHECK_NOTHROW(Matrix(value,6,3));
    value ={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};   ///20 times 1;
    CHECK_NOTHROW(Matrix(value,5,4));
    CHECK_NOTHROW(Matrix(value,20,1));
    CHECK_THROWS(Matrix(value,5,5));
    CHECK_THROWS(Matrix(value,0,20));
    CHECK_THROWS(Matrix(value,2,15));
    CHECK_THROWS(Matrix(value,20,2));
}

TEST_CASE("multification matrixs"){
        vector<double> v1 = {1,0,0,0,0,
                                0,1,0,0,0,
                                0,0,1,0,0,
                                0,0,0,1,0,
                                0,0,0,0,1};
        vector<double> v2 =     {2,0,0,0,0,
                                0,2,0,0,0,
                                0,0,2,0,0,
                                0,0,0,2,0,
                                0,0,0,0,2};
        Matrix m1(v1,5,5), m2(v2,5,5);
        m1*=2;
        CHECK_EQ(m1,m2);
        CHECK_EQ(m1, m2*m2);
        CHECK_EQ(m1-m2, m2);
        m2*=6;
        CHECK_FALSE(m2==m1);
    }

    TEST_CASE("CHECK equale parameters"){
        vector<double> v1 = {1,0,0,0,0,
                            0,1,0,0,0,
                            0,0,1,0,0,
                            0,0,0,1,0,
                            0,0,0,0,1};
            Matrix m1(v1,5,5);
            Matrix m2(v1,1,25);
            Matrix m3(v1,25,1);
        CHECK_THROWS(m1==m2);
        CHECK_THROWS(m2==m3);
        CHECK_THROWS(m3==m1);
    }

    TEST_CASE("CHECK PLUS AND MINUS CASES"){
        vector<double> v1 = {1,0,0,0,0,
                            0,1,0,0,0,
                            0,0,1,0,0,
                            0,0,0,1,0,
                            0,0,0,0,1};
            Matrix m1(v1,5,5);
            Matrix m2(v1,1,25);
            Matrix m3(v1,25,1);
        vector<double> v4 = {50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50,
                            50,50,50,50,50};
        Matrix m4(v4,30,5);
        Matrix m5(v4,30,5);
        for(size_t i=0; i<10;i++){
            m4--;
            CHECK_EQ(m4,--m5);
        }
        for(size_t i=0; i<10;i++){
            m4++;
            CHECK_EQ(m4,++m5);
        }
        CHECK_EQ(m4--,m5);
         m4--;
         m5-=2;
        CHECK(m4==m5);
    }