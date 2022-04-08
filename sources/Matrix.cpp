#include "Matrix.hpp"
namespace zich{
    bool LegalMatrix(std::vector<double> & value,unsigned int line,unsigned int column){
        return(value.size()==line*column);
    }
    Matrix createUniformMat(double num,unsigned int line,unsigned int column);
    void Matrix::setValue(std::vector<double> & value,unsigned int line,unsigned int column){
            this->column = column;
            this->line = line;
            this->mat = value;
    }
    Matrix::Matrix(std::vector<double> & value,unsigned int line,unsigned int column){
        if(!LegalMatrix(value,line,column)){
            throw std::runtime_error("the size of the matrix not competiable to the values yo want to insert");
        }
            this->column = column;
            this->line = line;
            this->mat = value;
    }
    Matrix createUniformMat(double num,unsigned int line,unsigned int column){
        std::vector<double> value(line*column,num);
        return Matrix(value,line, column);
    }
    Matrix::Matrix(std::vector<double> value,int line,int column){
        if(line<1 || column<1 || !LegalMatrix(value,(unsigned int) line,(unsigned int) column)){
            throw std::runtime_error("illgal input");
        }
        this->line = (unsigned int) line;
        this->column = (unsigned int) column;
        this->mat = value;
    }
    /** @brief: This function are the regular method Binary operators   */
    Matrix Matrix::operator + (Matrix const & other) const{
        if(this->line != other.line || this->column != other.column){
            throw std::runtime_error ("can't do the + functions between this matrixs");
        }
        std::vector<double> value;
        for(size_t i=0; i<this->line;i++){
            for(size_t j=0; j<this->column;j++){
                value.push_back(this->mat.at(i*this->column +j) + other.mat.at(i*this->column +j));
            }
        }
        return Matrix{value, this->line, this->column};
    }
    Matrix Matrix::operator-(Matrix const & other) const{
            try
            {
                return  *this + (-1* other);
            }
            catch(const std::exception& e)
            {
                throw e;
            }
            
    }
    Matrix& Matrix::operator-=(Matrix const &other){
        try{
        *this+= (-1*other);
        return *this;
        }
        catch(const std::exception& e)
            {
                throw e;
            }
    }
    Matrix& Matrix::operator-=(double num){
        try{
            *this= *this - num;
            return *this;
        }
        catch(const std::exception& e)
            {
                throw e;
            }
    }    
    Matrix& Matrix::operator+=(Matrix const & other){
        *this= *this + other;
        return *this;
    }
    Matrix& Matrix::operator+=(double num){
    try{
        *this+= createUniformMat(num, this->line, this->column);
        return *this;
    }
    catch(const std::exception& e)
        {
            throw e;
        }
    }
    Matrix Matrix::operator - (double num) const{
        try {
            return (*this + ((-1)*num));
        }
        catch(const std::exception& e)
        {
            throw e;
        }
    }
    Matrix Matrix::operator + (double num) const{
        try {
            return (*this + createUniformMat(num,this->line, this->column));
        }
        catch(const std::exception& e)
            {
                throw e;
            }
    }

/** @brief -> comparetions operators:
 * '==' Means the value on the left matrix at the place i,j is the same value as the right matrix
 * '>' Means the sum of the right mat is bigger for the left one
 * '<' The sum of the left matrix bigger then the right
 * '<=' || '>' The sum is equal or bigger
 * '!='  there is a cube i,j in the matrixs that not the same
 */
    bool Matrix::operator == (Matrix const & other) const{
        if(this->line != other.line || this->column != other.column){
            return false;
        }
        for(size_t i=0; i<this->line;i++){
            for(size_t j=0; j<this->column;j++){
                if(this->mat.at(i*this->column +j)!=other.mat.at(i*this->column +j)){
                    return false;
                }
            }
        }
        return true;
    }
    bool Matrix::operator > (Matrix const & other) const{
        if(this->line != other.line || this->column != other.column){
            throw std::runtime_error ("the matrix not at the same size!");
        }
        Matrix check = *this - other;
        double sum=0;
        for(size_t i=0; i<this->line*this->column;i++){
            sum+=check.mat.at(i);
        }
        return (sum>0);
    }
    bool Matrix::operator < (Matrix const & other) const{
        if(this->line != other.line || this->column != other.column){
            throw std::runtime_error ("the matrix not at the same size!");
        }
        Matrix check = *this - other;
        double sum=0;
        for(size_t i=0; i<this->line*this->column;i++){
            sum+=check.mat.at(i);
        }
        return (sum<0);
    }
    bool Matrix::operator >=(Matrix const & other) const{
        return (!(*this<other));
    }
    bool Matrix::operator <=(Matrix const & other) const{
        return (!(*this>other));
    }
    bool Matrix::operator !=(Matrix const & other) const{
        return (!(*this==other));}
/* Multiply functions  */
    Matrix Matrix::operator*(Matrix const & other) const{
        if(this->column!=other.line){ throw std::runtime_error ("this matrixs vamt be multifiction");}
        std::vector<double> value(this->line*other.column,0);
        for(size_t place=0; place<this->line;place++){
            for(size_t i=0; i<other.column;i++){
                for(size_t j=0; j<this->column;j++){
                    value.at(place*other.column +i) += this->mat.at(place*this->column+j)* other.mat.at(j*other.column +i);
                }
            }
        }
        return Matrix(value,this->line, other.column);
    }
    Matrix operator * (double scalar, Matrix const & other){
        try
        {
            std::vector<double> temp;
            for(size_t i=0;i<other.column*other.line;i++){
                temp.push_back(scalar * other.mat.at(i));
            }
            return Matrix(temp, other.line, other.column);
        }
        catch(const std::exception& e)
            {
                throw e;
            }
    }
    Matrix Matrix::operator*(double scalar) const{
        try{
            return (scalar * (*this));
        }
        catch(const std::exception& e)
            {
                throw e;
            }
    }
    Matrix& Matrix::operator *= (double scalar){
        try {
            *this = (*this) * scalar;
            return *this;
        }
        catch(const std::exception& e)
            {
                throw e;
            }
    }
    Matrix operator *=(double scalar, Matrix & other){
        try 
        {
            Matrix temp(other);
            temp*=scalar;
            return temp;
        }
        catch(const std::exception& e)
            {
                throw e;
            }
    }


/** @brief This is the unary operators. using only an operator and the matrix */

    Matrix& Matrix::operator--(){
        for(size_t i=0; i<this->column*this->line;i++){
            --this->mat.at(i);
        }
        return *this;
    }
    Matrix Matrix::operator--(int){
        Matrix temp(*this);
        --(*this);
        return temp;
    }
    Matrix& Matrix::operator++(){
        for(size_t i=0; i<this->column*this->line;i++){
            ++this->mat.at(i);
        }
        return *this;
    }
    Matrix Matrix::operator++(int){
        Matrix temp(*this);
        ++(*this);
        return temp;
    }
    Matrix Matrix::operator -(){
        return (-1*(*this));
    }
    Matrix Matrix::operator +(){
        return Matrix(*this);
    }

    /* stream in/out put functions  */

    std::ostream & operator << (std::ostream & oStream, Matrix const &  other){
        for(size_t i=0; i<other.line;i++){
            oStream << "[";
            for(size_t j=0;j<other.column-1;j++){
                oStream<<other.mat.at(i*other.column + j)<<" ";
            }
            oStream <<other.mat.at(i*other.column +other.column-1)<< "]" <<'\n';
        }
        return oStream;
    }
    
}