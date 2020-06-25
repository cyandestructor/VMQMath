#include "Quaternion.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace VMQ {

	//Constructors

	Quaternion::Quaternion(float angle, const Vector3D& axis) {

		float A = angle * 0.5, sinA = (float)sin(A * M_PI / 180), cosA = (float)cos(A * M_PI / 180);

		m_scalar = cosA;
		m_vector = sinA * axis.Normalized();

	}

	//Methods Definitions

	float Quaternion::W() const {

		return m_scalar;

	}

	float Quaternion::X() const {

		return m_vector.X();

	}

	float Quaternion::Y() const {

		return m_vector.Y();

	}

	float Quaternion::Z() const {

		return m_vector.Z();

	}

	float Quaternion::GetScalar() const {

		return m_scalar;

	}

	const Vector3D& Quaternion::GetVector() const {

		return m_vector;

	}

	void Quaternion::SetScalar(float scalar) {

		m_scalar = scalar;

	}

	void Quaternion::SetVector(const Vector3D& vector) {

		m_vector = vector;

	}

	void Quaternion::SetW(float w) {

		m_scalar = w;

	}

	void Quaternion::SetX(float x) {

		m_vector.SetX(x);

	}

	void Quaternion::SetY(float y) {

		m_vector.SetY(y);

	}

	void Quaternion::SetZ(float z) {

		m_vector.SetZ(z);

	}

	//Static Members

	Quaternion Quaternion::Multiply(const Quaternion& quaternion1, const Quaternion& quaternion2) {

		float
			x1 = quaternion1.X(),
			y1 = quaternion1.Y(),
			z1 = quaternion1.Z(),
			w1 = quaternion1.W(),
			x2 = quaternion2.X(),
			y2 = quaternion2.Y(),
			z2 = quaternion2.Z(),
			w2 = quaternion2.W(),
			rx = x1 * w2 + y1 * z2 - z1 * y2 + w1 * x2,
			ry = (-x1 * z2) + y1 * w2 + z1 * x2 + w1 * y2,
			rz = x1 * y2 + (-y1 * x2) + z1 * w2 + w1 * z2,
			rw = w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2;

		return Quaternion(rw, rx, ry, rz);

	}

	//Non-member operators

	Quaternion operator*(const Quaternion& quaternion1, const Quaternion& quaternion2) {

		return Quaternion::Multiply(quaternion1, quaternion2);

	}
}