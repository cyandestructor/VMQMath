#ifndef VMQMATH_QUATERNION_H
#define VMQMATH_QUATERNION_H

#include "Vector3D.h"

namespace VMQ {

	class Quaternion {

	public:
		Quaternion() : m_scalar(0), m_vector() {}
		Quaternion(double w, double x, double y, double z) :m_scalar(w), m_vector(x, y, z) {}
		Quaternion(double, const Vector3D&);
		double W() const;
		double X() const;
		double Y() const;
		double Z() const;
		double GetScalar() const;
		const Vector3D& GetVector() const;
		void SetScalar(double);
		void SetVector(const Vector3D&);
		void SetW(double);
		void SetX(double);
		void SetY(double);
		void SetZ(double);

		static Quaternion Multiply(const Quaternion&, const Quaternion&);

	private:
		double m_scalar;
		Vector3D m_vector;

	};

	Quaternion operator*(const Quaternion&, const Quaternion&);

}

#endif