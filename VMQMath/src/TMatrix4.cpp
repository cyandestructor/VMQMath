#include "TMatrix4.h"
#include "Vector3.h"
#include "Point3.h"

namespace VMQ {

	TMatrix4::TMatrix4() : m_matrix(4,4)
	{
		m_matrix.SetIdentity();
	}

	TMatrix4::~TMatrix4()
	{
	}

	const Matrix& TMatrix4::GetMatrix() const
	{
		return m_matrix;
	}

	TMatrix4 TMatrix4::MultiplyWith(const TMatrix4& tMatrix) const
	{
		return MultiplyTMatrices(*this, tMatrix);
	}

	Vector3 TMatrix4::ApplyToVector(const Vector3& vector) const
	{
		return TransformVector(vector, *this);
	}

	Point3 TMatrix4::ApplyToPoint(const Point3& point) const
	{
		return TransformPoint(point, *this);
	}

	Vector3 TMatrix4::TransformVector(const Vector3& vector, const TMatrix4& tMatrix)
	{
		Matrix vectorMatrix;
		Create4X1Matrix(vector.X(), vector.Y(), vector.Z(), vectorMatrix, false);
		Matrix result = vectorMatrix * tMatrix.m_matrix;
		double
			x = result.GetElement(0, 0),
			y = result.GetElement(1, 0),
			z = result.GetElement(2, 0);
		return Vector3(x, y, z);
	}

	Point3 TMatrix4::TransformPoint(const Point3& point, const TMatrix4& tMatrix)
	{
		Matrix pointMatrix;
		Create4X1Matrix(point.X(), point.Y(), point.Z(), pointMatrix, true);
		Matrix result = pointMatrix * tMatrix.m_matrix;
		double
			x = result.GetElement(0, 0),
			y = result.GetElement(1, 0),
			z = result.GetElement(2, 0);
		return Point3(x, y, z);
	}

	TMatrix4 TMatrix4::MultiplyTMatrices(const TMatrix4& tMatrix1, const TMatrix4& tMatrix2)
	{
		return TMatrix4(tMatrix1.m_matrix * tMatrix2.m_matrix);
	}

	void TMatrix4::Create4X1Matrix(double x, double y, double z, Matrix& matrix, bool isPoint)
	{
		matrix = Matrix(4, 1);
		matrix.SetElement(0, 0, x);
		matrix.SetElement(0, 1, y);
		matrix.SetElement(0, 2, z);
		matrix.SetElement(0, 3, isPoint ? 1 : 0);
	}

	TMatrix4 operator*(const TMatrix4& tMatrix1, const TMatrix4& tMatrix2)
	{
		return TMatrix4::MultiplyTMatrices(tMatrix1, tMatrix2);
	}

}