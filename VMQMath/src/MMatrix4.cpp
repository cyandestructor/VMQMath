#include "MMatrix4.h"

namespace VMQ {

	MMatrix4::MMatrix4(const Vector3& vector)
	{
		SetMoveVector(vector);
	}

	void MMatrix4::SetMoveVector(const Vector3& vector)
	{
		m_mVector = vector;
		m_matrix.SetElement(0, 3, vector.X());
		m_matrix.SetElement(1, 3, vector.Y());
		m_matrix.SetElement(2, 3, vector.Z());
	}

	const Vector3& MMatrix4::GetMoveVector() const
	{
		return m_mVector;
	}

}