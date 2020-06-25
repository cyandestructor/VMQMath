#ifndef VMQMATH_VECTOR3D_H
#define VMQMATH_VECTOR3D_H

namespace VMQ {

	class Vector3D {
	public:
		Vector3D() :m_x(0), m_y(0), m_z(0) {}
		Vector3D(double x, double y, double z) :m_x(x), m_y(y), m_z(z) {}
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
		Vector3D Normalized() const;
		double AngleWith(const Vector3D&) const;
		Vector3D CrossProductWith(const Vector3D&) const;
		double DotProductWith(const Vector3D&) const;
		void Add(const Vector3D&);
		void Add(double, double, double);
		void Subtract(const Vector3D&);
		void Subtract(double, double, double);
		void MultiplyScalar(double);

		static double AngleBetweenVectors(const Vector3D&, const Vector3D&);
		static Vector3D CrossProduct(const Vector3D&, const Vector3D&);
		static double DotProduct(const Vector3D&, const Vector3D&);
		static Vector3D AddVectors(const Vector3D&, const Vector3D&);
		static Vector3D SubtractVectors(const Vector3D&, const Vector3D&);
		static Vector3D ScalarByVector(double, const Vector3D&);
		
	private:
		double m_x, m_y, m_z;

	};

	Vector3D operator+(const Vector3D&, const Vector3D&);
	Vector3D operator-(const Vector3D&, const Vector3D&);
	Vector3D operator*(double, const Vector3D&);
	Vector3D operator*(const Vector3D&, double);

}

#endif