#include "SMatrix4.h"

namespace VMQ {

	SMatrix4::SMatrix4(const Vector3& vector)
	{
		SetScaleVector(vector);
	}

	void SMatrix4::SetScaleVector(const Vector3& vector)
	{
		m_sVector = vector;
		m_matrix.SetElement(0, 0, vector.X());
		m_matrix.SetElement(1, 1, vector.Y());
		m_matrix.SetElement(2, 2, vector.Z());
	}

	const Vector3& SMatrix4::GetScaleVector() const
	{
		return m_sVector;
	}
}