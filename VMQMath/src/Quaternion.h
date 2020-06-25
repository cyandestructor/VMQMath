#ifndef VMQMATH_QUATERNION_H
#define VMQMATH_QUATERNION_H

#include "Vector3D.h"

namespace VMQ {

	class Quaternion {

	public:
		Quaternion() : m_scalar(0), m_vector() {}
		Quaternion(float w, float x, float y, float z) :m_scalar(w), m_vector(x, y, z) {}
		Quaternion(float, const Vector3D&);
		float W() const;
		float X() const;
		float Y() const;
		float Z() const;
		float GetScalar() const;
		const Vector3D& GetVector() const;
		void SetScalar(float);
		void SetVector(const Vector3D&);
		void SetW(float);
		void SetX(float);
		void SetY(float);
		void SetZ(float);

		static Quaternion Multiply(const Quaternion&, const Quaternion&);

	private:
		float m_scalar;
		Vector3D m_vector;

	};

	Quaternion operator*(const Quaternion&, const Quaternion&);

}

#endif