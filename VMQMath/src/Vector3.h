#ifndef VMQMATH_VECTOR3_H
#define VMQMATH_VECTOR3_H

namespace VMQ {

	class Vector3 {
	public:
		Vector3() :m_x(0), m_y(0), m_z(0) {}
		Vector3(double x, double y, double z) :m_x(x), m_y(y), m_z(z) {}
		double X() const;
		double Y() const;
		double Z() const;
		double SqX() const;
		double SqY() const;
		double SqZ() const;
		double Magnitude() const;
		void SetValues(double, double, double);
		void SetX(double);
		void SetY(double);
		void SetZ(double);
		void Normalize();
		Vector3 Normalized() const;
		double AngleWith(const Vector3&) const;
		Vector3 CrossProductWith(const Vector3&) const;
		double DotProductWith(const Vector3&) const;
		void Add(const Vector3&);
		void Add(double, double, double);
		void Subtract(const Vector3&);
		void Subtract(double, double, double);
		void MultiplyScalar(double);

		static double AngleBetweenVectors(const Vector3&, const Vector3&);
		static Vector3 CrossProduct(const Vector3&, const Vector3&);
		static double DotProduct(const Vector3&, const Vector3&);
		static Vector3 AddVectors(const Vector3&, const Vector3&);
		static Vector3 SubtractVectors(const Vector3&, const Vector3&);
		static Vector3 ScalarByVector(double, const Vector3&);
		
	private:
		double m_x, m_y, m_z;

	};

	Vector3 operator+(const Vector3&, const Vector3&);
	Vector3 operator-(const Vector3&, const Vector3&);
	Vector3 operator*(double, const Vector3&);
	Vector3 operator*(const Vector3&, double);

}

#endif