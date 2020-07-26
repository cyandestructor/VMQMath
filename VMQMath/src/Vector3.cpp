#include "Vector3.h"
#include <math.h>

namespace VMQ {

	//Methods

	double Vector3::X() const {

		return m_x;

	}

	double Vector3::Y() const {

		return m_y;

	}

	double Vector3::Z() const {

		return m_z;

	}

	double Vector3::SqX() const {

		return m_x * m_x;

	}

	double Vector3::SqY() const {

		return m_y * m_y;

	}

	double Vector3::SqZ() const {

		return m_z * m_z;

	}

	double Vector3::Magnitude() const {

		double sqX = m_x * m_x,
			sqY = m_y * m_y,
			sqZ = m_z * m_z;

		return sqrt((double)sqX + (double)sqY + (double)sqZ);

	}

	void Vector3::SetValues(double x, double y, double z) {

		m_x = x;
		m_y = y;
		m_z = z;

	}

	void Vector3::SetX(double x) {

		m_x = x;

	}

	void Vector3::SetY(double y) {

		m_y = y;

	}

	void Vector3::SetZ(double z) {

		m_z = z;

	}

	void Vector3::Normalize() {

		double normFactor = (1 / this->Magnitude());
		m_x *= normFactor;
		m_y *= normFactor;
		m_z *= normFactor;

	}

	Vector3 Vector3::Normalized() const {

		double normFactor = (1 / this->Magnitude()),
			normX = m_x * normFactor,
			normY = m_y * normFactor,
			normZ = m_z * normFactor;

		return Vector3(normX, normY, normZ);

	}

	double Vector3::AngleWith(const Vector3& vector) const {

		return Vector3::AngleBetweenVectors(*this, vector);

	}

	void Vector3::MultiplyScalar(double scalar) {

		m_x *= scalar;
		m_y *= scalar;
		m_z *= scalar;

	}
	
	double Vector3::AngleBetweenVectors(const Vector3& vector1, const Vector3& vector2) {

		double cosAngle = Vector3::DotProduct(vector1, vector2) / (vector1.Magnitude() * vector2.Magnitude());
		return acos(cosAngle);

	}

	Vector3 Vector3::CrossProductWith(const Vector3& vector) const {

		return Vector3::CrossProduct(*this, vector);

	}

	double Vector3::DotProductWith(const Vector3& vector) const {

		return Vector3::DotProduct(*this, vector);

	}

	void Vector3::Add(const Vector3& vector) {

		m_x += vector.m_x;
		m_y += vector.m_y;
		m_z += vector.m_z;

	}
	
	void Vector3::Add(double x, double y, double z) {

		m_x += x;
		m_y += y;
		m_z += z;

	}

	void Vector3::Subtract(const Vector3& vector) {
		
		m_x -= vector.m_x;
		m_y -= vector.m_y;
		m_z -= vector.m_z;
	
	}

	void Vector3::Subtract(double x, double y, double z) {
		
		m_x -= x;
		m_x -= y;
		m_x -= z;

	}

	//Static members

	Vector3 Vector3::CrossProduct(const Vector3& vector1, const Vector3& vector2) {

		double
			x = vector1.m_y * vector2.m_z - vector1.m_z * vector2.m_y,
			y = (vector1.m_x * vector2.m_z - vector1.m_z * vector2.m_x) * -1,
			z = vector1.m_x * vector2.m_y - vector1.m_y * vector2.m_x;

		return Vector3(x, y, z);

	}

	double Vector3::DotProduct(const Vector3& vector1, const Vector3& vector2) {

		return vector1.m_x * vector2.m_x +
			vector1.m_y * vector2.m_y +
			vector1.m_z * vector2.m_z;

	}

	Vector3 Vector3::AddVectors(const Vector3& vector1, const Vector3& vector2) {

		return Vector3(vector1.m_x + vector2.m_x,
			vector1.m_y + vector2.m_y,
			vector1.m_z + vector2.m_z);

	}

	Vector3 Vector3::SubtractVectors(const Vector3& vector1, const Vector3& vector2) {
		return Vector3(vector1.m_x-vector2.m_x,
			vector1.m_y - vector2.m_y,
			vector1.m_z - vector2.m_z);
	}

	Vector3 Vector3::ScalarByVector(double scalar, const Vector3& vector) {
		
		return Vector3(vector.m_x * scalar, vector.m_y * scalar, vector.m_z * scalar);

	}

	//Non-member operators

	Vector3 operator+(const Vector3& vector1, const Vector3& vector2) {

		return Vector3::AddVectors(vector1, vector2);

	}

	Vector3 operator-(const Vector3& vector1, const Vector3& vector2) {
		
		return Vector3::SubtractVectors(vector1, vector2);

	}

	Vector3 operator*(double scalar, const Vector3& vector) {

		return Vector3::ScalarByVector(scalar, vector);

	}
	
	Vector3 operator*(const Vector3& vector, double scalar) {

		return Vector3::ScalarByVector(scalar, vector);

	}

}