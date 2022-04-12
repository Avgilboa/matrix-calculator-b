#pragma once

#include <iostream>
#include <vector>

namespace zich{
    class Matrix{
        private:
            unsigned int column;
            unsigned int line;
            std::vector<double> mat;
        public:

            unsigned int getCol() const {return this->column;}
            unsigned int getLine() const {return this->line;}
            
            
            Matrix operator+(Matrix const & other) const;
            Matrix operator+(double num) const;
            Matrix& operator++();
            Matrix operator++(int);
            Matrix& operator+=(Matrix const & other);
            Matrix& operator+=(double num);
            Matrix operator +();


            Matrix operator-(Matrix const  & other) const;
            Matrix operator-(double num) const;
            Matrix& operator-=(Matrix const & other);
            Matrix& operator-=(double num);
            Matrix& operator--();
            Matrix operator--(int);
            Matrix operator -();


            Matrix operator*(Matrix const & other) const;
            Matrix operator*(double scalar) const;
            Matrix& operator*=(Matrix const & other);
            Matrix& operator*=(double scalar);                        
            friend Matrix operator*=(double scalar, Matrix const & other);                         
            friend Matrix operator * (double scalar , Matrix const & other); 

            bool operator<=(Matrix const & other) const ;
            bool operator<(Matrix  const & other)const ;
            bool operator>(Matrix  const & other) const ;
            bool operator>=(Matrix const & other)const ;
            bool operator == (Matrix const & other) const;
            bool operator !=(Matrix const & other) const;

            friend std::ostream & operator << (std::ostream & oStream ,Matrix const &  other);
            friend std::istream & operator >> (std::istream & iStream , Matrix & other);

            Matrix(std::vector<double> & value,unsigned int line,unsigned int column);
            Matrix(std::vector<double>  value,int line,int column); 

            Matrix();
            ~Matrix(){};

            void setValue(std::vector<double> & value,unsigned int line,unsigned int column);
    };
}