#include "RMatrix3D.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace VMQ {

	RMatrix3D::RMatrix3D(double angle, Axes fixedAxis)
	{
		float sinA = (float)sin(angle * M_PI / 180),
			cosA = (float)cos(angle * M_PI / 180);

		m_matrix.SetIdentity();

		switch (fixedAxis) {
		case Axes::X:
			m_matrix.SetElement(1, 1, cosA);
			m_matrix.SetElement(1, 2, -sinA);
			m_matrix.SetElement(2, 1, sinA);
			m_matrix.SetElement(2, 2, cosA);
			break;
		case Axes::Y:
			m_matrix.SetElement(0, 0, cosA);
			m_matrix.SetElement(0, 2, sinA);
			m_matrix.SetElement(2, 0, -sinA);
			m_matrix.SetElement(2, 2, cosA);
			break;
		case Axes::Z:
			m_matrix.SetElement(0, 0, cosA);
			m_matrix.SetElement(0, 1, -sinA);
			m_matrix.SetElement(1, 0, sinA);
			m_matrix.SetElement(1, 1, cosA);
			break;
		}

	}

	RMatrix3D::RMatrix3D(const Quaternion& quaternion)
	{
		const Vector3D& vector = quaternion.GetVector();
		double scalar = quaternion.GetScalar();

		double
			sqW = scalar * scalar,
			sqX = vector.SqX(),
			sqY = vector.SqY(),
			sqZ = vector.SqZ(),

			xw = vector.X() * scalar,
			yw = vector.Y() * scalar,
			zw = vector.Z() * scalar,

			xy = vector.X() * vector.Y(),
			xz = vector.X() * vector.Z(),

			yz = vector.Y() * vector.Z();

		m_matrix.SetIdentity();

		m_matrix.SetElement(0, 0, (1 - 2 * (sqY + sqZ)));
		m_matrix.SetElement(0, 1, (2 * (xy - zw)));
		m_matrix.SetElement(0, 2, (2 * (xz + yw)));

		m_matrix.SetElement(1, 0, (2 * (xy + zw)));
		m_matrix.SetElement(1, 1, (1 - 2 * (sqX + sqZ)));
		m_matrix.SetElement(1, 2, (2 * (yz - xw)));

		m_matrix.SetElement(2, 0, (2 * (xz - yw)));
		m_matrix.SetElement(2, 1, (2 * (yz + xw)));
		m_matrix.SetElement(2, 2, (1 - 2 * (sqX + sqY)));

	}

}