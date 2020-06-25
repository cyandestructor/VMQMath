#ifndef VMQMATH_MATRIX_H
#define VMQMATH_MATRIX_H

#include <iostream>

namespace VMQ {

	class Matrix {

	public:
		Matrix();
		Matrix(size_t, size_t);
		Matrix(const Matrix&);

		Matrix& operator= (const Matrix& other);

		size_t Rows() const;
		size_t Columns() const;
		bool IsEmpty() const;
		Matrix Transpose() const;
		Matrix Identity() const;
		void SetIdentity();
		void MultiplyScalar(double scalar);
		void SetElement(size_t, size_t, double);
		double GetElement(size_t, size_t) const;
		void Reset();

		~Matrix();

		static Matrix TransposeOf(const Matrix&);
		static Matrix Identity(size_t, size_t);
		static Matrix AddMatrices(const Matrix&, const Matrix&);
		static Matrix SubtractMatrices(const Matrix&, const Matrix&);
		static Matrix MultiplyMatrices(const Matrix&, const Matrix&);
		static Matrix ScalarByMatrix(double scalar, const Matrix&);

	private:
		size_t m_rows, m_columns;
		double* m_matrix;

	};

	Matrix operator+(const Matrix&, const Matrix&);
	Matrix operator-(const Matrix&, const Matrix&);
	Matrix operator*(const Matrix&, const Matrix&);
	Matrix operator*(const Matrix&, double);
	Matrix operator*(double, const Matrix&);

}

#endif