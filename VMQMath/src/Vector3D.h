#ifndef VMQMATH_VECTOR3D_H
#define VMQMATH_VECTOR3D_H

namespace VMQ {

	class Vector3D {
	public:
		Vector3D() :m_x(0), m_y(0), m_z(0) {}
		Vector3D(float x, float y, float z) :m_x(x), m_y(y), m_z(z) {}
		float X() const;
		float Y() const;
		float Z() const;
		float SqX() const;
		float SqY() const;
		float SqZ() const;
		float Magnitude() const;
		void SetValues(float, float, float);
		void SetX(float);
		void SetY(float);
		void SetZ(float);
		void Normalize();
		Vector3D Normalized() const;
		double AngleWith(const Vector3D&) const;
		Vector3D CrossProductWith(const Vector3D&) const;
		float DotProductWith(const Vector3D&) const;
		void Add(const Vector3D&);
		void Add(float, float, float);
		void MultiplyScalar(float);

		static double AngleBetweenVectors(const Vector3D&, const Vector3D&);
		static Vector3D CrossProduct(const Vector3D&, const Vector3D&);
		static float DotProduct(const Vector3D&, const Vector3D&);
		static Vector3D AddVectors(const Vector3D&, const Vector3D&);
		static Vector3D ScalarByVector(float, const Vector3D&);
		
	private:
		float m_x, m_y, m_z;

	};

	Vector3D operator+(const Vector3D&, const Vector3D&);
	Vector3D operator*(float, const Vector3D&);
	Vector3D operator*(const Vector3D&, float);

}

#endif