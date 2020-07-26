#ifndef VMQMATH_TMATRIX4_H
#define VMQMATH_TMATRIX4_H

#include "Matrix.h"

namespace VMQ {

	class Vector3;
	class Point3;

	class TMatrix4 {

	public:
		TMatrix4();
		virtual ~TMatrix4();

		const Matrix& GetMatrix() const;
		TMatrix4 MultiplyWith(const TMatrix4&) const;
		Vector3 ApplyToVector(const Vector3&) const;
		Point3 ApplyToPoint(const Point3&) const;

		static Vector3 TransformVector(const Vector3&, const TMatrix4&);
		static Point3 TransformPoint(const Point3&, const TMatrix4&);
		static TMatrix4 MultiplyTMatrices(const TMatrix4&, const TMatrix4&);

	protected:
		Matrix m_matrix;

	private:
		TMatrix4(Matrix matrix) : m_matrix(matrix) {}
		static void Create4X1Matrix(double x, double y, double z, Matrix& matrix, bool isPoint);

	};

	TMatrix4 operator*(const TMatrix4&, const TMatrix4&);

}

#endif