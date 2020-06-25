#include "SMatrix3D.h"

namespace VMQ {

	SMatrix3D::SMatrix3D(const Vector3D& vector)
	{
		SetScaleVector(vector);
	}

	void SMatrix3D::SetScaleVector(const Vector3D& vector)
	{
		m_sVector = vector;
		m_matrix.SetElement(0, 0, vector.X());
		m_matrix.SetElement(1, 1, vector.Y());
		m_matrix.SetElement(2, 2, vector.Z());
	}

	const Vector3D& SMatrix3D::GetScaleVector() const
	{
		return m_sVector;
	}
}