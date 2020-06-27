#include "TMatrix3D.h"

namespace VMQ {

	TMatrix3D::TMatrix3D() : m_matrix(4,4)
	{
		m_matrix.SetIdentity();
	}

	TMatrix3D::~TMatrix3D()
	{
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

	Point3D TMatrix3D::ApplyToPoint(const Point3D& point) const
	{
		return TransformPoint(point, *this);
	}

	Vector3D TMatrix3D::TransformVector(const Vector3D& vector, const TMatrix3D& tMatrix)
	{
		Matrix vectorMatrix;
		Create4X1Matrix(vector.X(), vector.Y(), vector.Z(), vectorMatrix, false);
		Matrix result = vectorMatrix * tMatrix.m_matrix;
		double
			x = result.GetElement(0, 0),
			y = result.GetElement(1, 0),
			z = result.GetElement(2, 0);
		return Vector3D(x, y, z);
	}

	Point3D TMatrix3D::TransformPoint(const Point3D& point, const TMatrix3D& tMatrix)
	{
		Matrix pointMatrix;
		Create4X1Matrix(point.X(), point.Y(), point.Z(), pointMatrix, true);
		Matrix result = pointMatrix * tMatrix.m_matrix;
		double
			x = result.GetElement(0, 0),
			y = result.GetElement(1, 0),
			z = result.GetElement(2, 0);
		return Point3D(x, y, z);
	}

	TMatrix3D TMatrix3D::MultiplyTMatrices(const TMatrix3D& tMatrix1, const TMatrix3D& tMatrix2)
	{
		return TMatrix3D(tMatrix1.m_matrix * tMatrix2.m_matrix);
	}

	void TMatrix3D::Create4X1Matrix(double x, double y, double z, Matrix& matrix, bool isPoint)
	{
		matrix = Matrix(4, 1);
		matrix.SetElement(0, 0, x);
		matrix.SetElement(0, 1, y);
		matrix.SetElement(0, 2, z);
		matrix.SetElement(0, 3, isPoint ? 1 : 0);
	}

	TMatrix3D operator*(const TMatrix3D& tMatrix1, const TMatrix3D& tMatrix2)
	{
		return TMatrix3D::MultiplyTMatrices(tMatrix1, tMatrix2);
	}

}