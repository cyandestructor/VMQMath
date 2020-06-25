#include "MMatrix3D.h"

namespace VMQ {

	MMatrix3D::MMatrix3D(const Vector3D& vector)
	{
		SetMoveVector(vector);
	}

	void MMatrix3D::SetMoveVector(const Vector3D& vector)
	{
		m_mVector = vector;
		m_matrix.SetElement(0, 3, vector.X());
		m_matrix.SetElement(1, 3, vector.Y());
		m_matrix.SetElement(2, 3, vector.Z());
	}

	const Vector3D& MMatrix3D::GetMoveVector() const
	{
		return m_mVector;
	}

}