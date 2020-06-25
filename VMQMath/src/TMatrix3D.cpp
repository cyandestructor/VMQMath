#include "TMatrix3D.h"

namespace VMQ {

	TMatrix3D::TMatrix3D() : m_matrix(4,4)
	{
		m_matrix.SetIdentity();
	}

	const Matrix& TMatrix3D::GetMatrix() const
	{
		return m_matrix;
	}

	TMatrix3D TMatrix3D::MultiplyWith(const TMatrix3D& tMatrix) const
	{
		return MultiplyTMatrices(*this, tMatrix);
	}

	Vector3D TMatrix3D::ApplyToVector(const Vector3D& vector) const
	{
		return TransformVector(vector, *this);
	}

	/*Point3D TMatrix3D::ApplyToPoint(const Point3D&) const
	{
		return Point3D();
	}*/

	Vector3D TMatrix3D::TransformVector(const Vector3D& vector, const TMatrix3D& tMatrix)
	{
		Matrix vectorMatrix;
		Create4X1VectorMatrix(vector, vectorMatrix);
		Matrix result = vectorMatrix * tMatrix.m_matrix;
		double
			x = result.GetElement(0, 0),
			y = result.GetElement(1, 0),
			z = result.GetElement(2, 0);
		return Vector3D(x, y, z);
	}

	/*Point3D TMatrix3D::TransformPoint(const Point3D&, const TMatrix3D&)
	{
		return Point3D();
	}*/

	TMatrix3D TMatrix3D::MultiplyTMatrices(const TMatrix3D& tMatrix1, const TMatrix3D& tMatrix2)
	{
		return TMatrix3D(tMatrix1.m_matrix * tMatrix2.m_matrix);
	}

	void TMatrix3D::Create4X1VectorMatrix(const Vector3D& vector, Matrix& matrix)
	{
		matrix = Matrix(4, 1);
		matrix.SetElement(0, 0, vector.X());
		matrix.SetElement(0, 1, vector.Y());
		matrix.SetElement(0, 2, vector.Z());
		matrix.SetElement(0, 3, 1);
	}

	TMatrix3D operator*(const TMatrix3D& tMatrix1, const TMatrix3D& tMatrix2)
	{
		return TMatrix3D::MultiplyTMatrices(tMatrix1, tMatrix2);
	}

}