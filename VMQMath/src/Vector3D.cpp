#include "Vector3D.h"
#include <math.h>

namespace VMQ {

	//Methods

	double Vector3D::X() const {

		return m_x;

	}

	double Vector3D::Y() const {

		return m_y;

	}

	double Vector3D::Z() const {

		return m_z;

	}

	double Vector3D::SqX() const {

		return m_x * m_x;

	}

	double Vector3D::SqY() const {

		return m_y * m_y;

	}

	double Vector3D::SqZ() const {

		return m_z * m_z;

	}

	double Vector3D::Magnitude() const {

		double sqX = m_x * m_x,
			sqY = m_y * m_y,
			sqZ = m_z * m_z;

		return sqrt((double)sqX + (double)sqY + (double)sqZ);

	}

	void Vector3D::SetValues(double x, double y, double z) {

		m_x = x;
		m_y = y;
		m_z = z;

	}

	void Vector3D::SetX(double x) {

		m_x = x;

	}

	void Vector3D::SetY(double y) {

		m_y = y;

	}

	void Vector3D::SetZ(double z) {

		m_z = z;

	}

	void Vector3D::Normalize() {

		double normFactor = (1 / this->Magnitude());
		m_x *= normFactor;
		m_y *= normFactor;
		m_z *= normFactor;

	}

	Vector3D Vector3D::Normalized() const {

		double normFactor = (1 / this->Magnitude()),
			normX = m_x * normFactor,
			normY = m_y * normFactor,
			normZ = m_z * normFactor;

		return Vector3D(normX, normY, normZ);

	}

	double Vector3D::AngleWith(const Vector3D& vector) const {

		return Vector3D::AngleBetweenVectors(*this, vector);

	}

	void Vector3D::MultiplyScalar(double scalar) {

		m_x *= scalar;
		m_y *= scalar;
		m_z *= scalar;

	}
	
	double Vector3D::AngleBetweenVectors(const Vector3D& vector1, const Vector3D& vector2) {

		double cosAngle = Vector3D::DotProduct(vector1, vector2) / (vector1.Magnitude() * vector2.Magnitude());
		return acos(cosAngle);

	}

	Vector3D Vector3D::CrossProductWith(const Vector3D& vector) const {

		return Vector3D::CrossProduct(*this, vector);

	}

	double Vector3D::DotProductWith(const Vector3D& vector) const {

		return Vector3D::DotProduct(*this, vector);

	}

	void Vector3D::Add(const Vector3D& vector) {

		m_x += vector.m_x;
		m_y += vector.m_y;
		m_z += vector.m_z;

	}
	
	void Vector3D::Add(double x, double y, double z) {

		m_x += x;
		m_y += y;
		m_z += z;

	}

	void Vector3D::Subtract(const Vector3D& vector) {
		
		m_x -= vector.m_x;
		m_y -= vector.m_y;
		m_z -= vector.m_z;
	
	}

	void Vector3D::Subtract(double x, double y, double z) {
		
		m_x -= x;
		m_x -= y;
		m_x -= z;

	}

	//Static members

	Vector3D Vector3D::CrossProduct(const Vector3D& vector1, const Vector3D& vector2) {

		double
			x = vector1.m_y * vector2.m_z - vector1.m_z * vector2.m_y,
			y = (vector1.m_x * vector2.m_z - vector1.m_z * vector2.m_x) * -1,
			z = vector1.m_x * vector2.m_y - vector1.m_y * vector2.m_x;

		return Vector3D(x, y, z);

	}

	double Vector3D::DotProduct(const Vector3D& vector1, const Vector3D& vector2) {

		return vector1.m_x * vector2.m_x +
			vector1.m_y * vector2.m_y +
			vector1.m_z * vector2.m_z;

	}

	Vector3D Vector3D::AddVectors(const Vector3D& vector1, const Vector3D& vector2) {

		return Vector3D(vector1.m_x + vector2.m_x,
			vector1.m_y + vector2.m_y,
			vector1.m_z + vector2.m_z);

	}

	Vector3D Vector3D::SubtractVectors(const Vector3D& vector1, const Vector3D& vector2) {
		return Vector3D(vector1.m_x-vector2.m_x,
			vector1.m_y - vector2.m_y,
			vector1.m_z - vector2.m_z);
	}

	Vector3D Vector3D::ScalarByVector(double scalar, const Vector3D& vector) {
		
		return Vector3D(vector.m_x * scalar, vector.m_y * scalar, vector.m_z * scalar);

	}

	//Non-member operators

	Vector3D operator+(const Vector3D& vector1, const Vector3D& vector2) {

		return Vector3D::AddVectors(vector1, vector2);

	}

	Vector3D operator-(const Vector3D& vector1, const Vector3D& vector2) {
		
		return Vector3D::SubtractVectors(vector1, vector2);

	}

	Vector3D operator*(double scalar, const Vector3D& vector) {

		return Vector3D::ScalarByVector(scalar, vector);

	}
	
	Vector3D operator*(const Vector3D& vector, double scalar) {

		return Vector3D::ScalarByVector(scalar, vector);

	}

}