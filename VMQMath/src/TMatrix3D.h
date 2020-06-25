#ifndef VMQMATH_TMATRIX3D_H
#define VMQMATH_TMATRIX3D_H

#include "Matrix.h"
#include "Vector3D.h"

namespace VMQ {

	class Point3D;

	class TMatrix3D {

	public:
		TMatrix3D();

		const Matrix& GetMatrix() const;
		TMatrix3D MultiplyWith(const TMatrix3D&) const;
		Vector3D ApplyToVector(const Vector3D&) const;
		Point3D ApplyToPoint(const Point3D&) const;

		static Vector3D TransformVector(const Vector3D&, const TMatrix3D&);
		static Point3D TransformPoint(const Point3D&, const TMatrix3D&);
		static TMatrix3D MultiplyTMatrices(const TMatrix3D&, const TMatrix3D&);

	protected:
		Matrix m_matrix;

	private:
		TMatrix3D(Matrix matrix) : m_matrix(matrix) {}
		static void Create4X1VectorMatrix(const Vector3D&, Matrix&);

	};

	TMatrix3D operator*(const TMatrix3D&, const TMatrix3D&);

}

#endif