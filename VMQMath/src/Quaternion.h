#ifndef VMQMATH_QUATERNION_H
#define VMQMATH_QUATERNION_H

#include "Vector3.h"

namespace VMQ {

	class Quaternion {

	public:
		Quaternion() : m_scalar(0), m_vector() {}
		Quaternion(double w, double x, double y, double z) :m_scalar(w), m_vector(x, y, z) {}
		Quaternion(double, const Vector3&);
		double W() const;
		double X() const;
		double Y() const;
		double Z() const;
		double GetScalar() const;
		const Vector3& GetVector() const;
		void SetScalar(double);
		void SetVector(const Vector3&);
		void SetW(double);
		void SetX(double);
		void SetY(double);
		void SetZ(double);

		static Quaternion Multiply(const Quaternion&, const Quaternion&);

	private:
		double m_scalar;
		Vector3 m_vector;

	};

	Quaternion operator*(const Quaternion&, const Quaternion&);

}

#endif