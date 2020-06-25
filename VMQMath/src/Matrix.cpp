#include <iostream>
#include "Matrix.h"

namespace VMQ {

	//Constructors

	Matrix::Matrix() {

		m_rows = 0;
		m_columns = 0;

		m_matrix = nullptr;

	}

	Matrix::Matrix(size_t rows, size_t columns) {

		m_rows = rows;
		m_columns = columns;

		if (rows == 0 || columns == 0) {
			m_matrix = nullptr;
		}
		else {
			m_matrix = new float[rows * columns]; //Matrix represented as a linear array
			std::memset(m_matrix, 0, sizeof(float) * rows * columns);
		}

	}

	Matrix::Matrix(const Matrix& other) {

		m_rows = other.m_rows;
		m_columns = other.m_columns;

		if (m_rows != 0 && m_columns != 0) {
			m_matrix = new float[m_rows * m_columns];

			for (int i = 0; i < m_rows * m_columns; i++) {
				m_matrix[i] = other.m_matrix[i];
			}

		}
		else {
			m_matrix = nullptr;
		}

	}

	//Member operators

	Matrix& Matrix::operator=(const Matrix& other) {

		if (this != &other) {

			if (other.m_matrix != nullptr) {
				delete[] m_matrix;

				m_rows = other.m_rows;
				m_columns = other.m_columns;

				m_matrix = new float[m_rows * m_columns];

				for (int i = 0; i < m_rows * m_columns; i++) {
					m_matrix[i] = other.m_matrix[i];
				}
			}
			else {
				this->Reset();
			}

		}

		return *this;

	}

	//Matrix methods

	size_t Matrix::Rows() const {

		return m_rows;

	}

	size_t Matrix::Columns() const {

		return m_columns;

	}

	bool Matrix::IsEmpty() const {

		if (m_matrix == nullptr) {
			return true;
		}
		else {
			return false;
		}

	}

	void Matrix::Reset() {

		delete[] m_matrix;
		m_matrix = nullptr;

		m_rows = 0;
		m_columns = 0;

	}

	void Matrix::SetElement(size_t row, size_t column, float value) {

		m_matrix[row * m_columns + column] = value;

	}

	float Matrix::GetElement(size_t row, size_t column) const {

		return m_matrix[row * m_columns + column];

	}

	Matrix Matrix::Transpose() const {

		return TransposeOf(*this);

	}

	Matrix Matrix::Identity() const {

		Matrix identity(m_rows, m_columns);

		for (size_t i = 0; i < m_rows; i++) {
			for (size_t j = 0; j < m_columns; j++) {
				if (i == j) {
					identity.SetElement(i, j, 1);
				}
			}
		}

		return identity;

	}

	void Matrix::SetIdentity() {

		for (size_t i = 0; i < m_rows; i++) {
			for (size_t j = 0; j < m_columns; j++) {
				if (i == j)
					this->SetElement(i, j, 1);
				else
					this->SetElement(i, j, 0);
			}
		}

	}

	void Matrix::MultiplyScalar(float scalar) {

		for (size_t i = 0; i < m_rows; i++) {

			for (size_t j = 0; j < m_columns; j++) {

				float scalarProduct = scalar * this->GetElement(i, j);
				this->SetElement(i, j, scalarProduct);

			}

		}

	}

	//Destructor
	Matrix::~Matrix() {

		delete[] m_matrix;

	}

	//Static members

	Matrix Matrix::AddMatrices(const Matrix& matrix1, const Matrix& matrix2) {

		Matrix resultantMatrix;

		if (!matrix1.IsEmpty() && !matrix2.IsEmpty()) {

			if (matrix1.Rows() == matrix2.Rows() && matrix1.Columns() == matrix2.Columns()) {	//If both matrices are the same order

				//resultanMatrix will have the same order/dimensions as matrices 1 and 2
				int resMatrixRows = matrix1.Rows(),
					resMatrixColumns = matrix2.Columns();

				resultantMatrix = Matrix(resMatrixRows, resMatrixColumns);	//Change the properties of the matrix

				for (size_t i = 0; i < resMatrixRows; i++) {

					for (size_t j = 0; j < resMatrixColumns; j++) {
						float newValue = matrix1.GetElement(i, j) + matrix2.GetElement(i, j);
						resultantMatrix.SetElement(i, j, newValue);
					}

				}

			}

		}

		return resultantMatrix;

	}

	Matrix Matrix::MultiplyMatrices(const Matrix& matrix1, const Matrix& matrix2) {

		Matrix resultantMatrix;

		if (!matrix1.IsEmpty() && !matrix2.IsEmpty()) {

			if (matrix1.Columns() == matrix2.Rows()) {	//Condition of matrix multiplication

				//resultantMatrix order/dimensions
				int resMatrixRows = matrix1.Rows(),
					resMatrixColumns = matrix2.Columns();

				resultantMatrix = Matrix(resMatrixRows, resMatrixColumns);	//Change the properties of the matrix

				float sum;

				//Algorithm for Matrix multiplication
				for (size_t i = 0; i < resMatrixRows; i++) {

					for (size_t j = 0; j < resMatrixColumns; j++) {

						sum = 0;

						for (size_t k = 0; k < matrix1.Columns(); k++) {

							sum += matrix1.GetElement(i, k) * matrix2.GetElement(k, j);

						}

						resultantMatrix.SetElement(i, j, sum);

					}

				}

			}

		}

		return resultantMatrix;

	}

	Matrix Matrix::TransposeOf(const Matrix& matrix) {

		Matrix transpose(matrix.m_columns, matrix.m_rows);

		for (size_t i = 0; i < transpose.m_rows; i++) {
			for (size_t j = 0; j < transpose.m_columns; i++) {
				transpose.SetElement(i, j, matrix.GetElement(j, i));
			}
		}

		return transpose;

	}

	Matrix Matrix::Identity(size_t rows, size_t columns) {
		Matrix identity(rows, columns);

		for (size_t i = 0; i < rows; i++) {
			for (size_t j = 0; j < columns; j++) {
				if (i == j) {
					identity.SetElement(i, j, 1);
				}
			}
		}

		return identity;

	}

	Matrix Matrix::ScalarByMatrix(float scalar, const Matrix& matrix) {

		Matrix resultant = matrix;

		if (!matrix.IsEmpty()) {

			for (size_t i = 0; i < matrix.Rows(); i++) {

				for (size_t j = 0; j < matrix.Columns(); j++) {

					float scalarProduct = scalar * matrix.GetElement(i, j);
					resultant.SetElement(i, j, scalarProduct);

				}

			}

		}

		return resultant;

	}

	//Non-member operators

	Matrix operator+(const Matrix& matrix1, const Matrix& matrix2) {

		return Matrix::AddMatrices(matrix1, matrix2);

	}

	Matrix operator*(const Matrix& matrix1, const Matrix& matrix2) {

		return Matrix::MultiplyMatrices(matrix1, matrix2);

	}

	Matrix operator*(const Matrix& matrix, float scalar) {

		return Matrix::ScalarByMatrix(scalar, matrix);

	}

	Matrix operator*(float scalar, const Matrix& matrix) {

		return Matrix::ScalarByMatrix(scalar, matrix);

	}

}