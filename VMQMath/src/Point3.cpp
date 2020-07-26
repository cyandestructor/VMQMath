#include "Point3.h"
#include "Vector3.h"
#include <math.h>

namespace VMQ {

	void Point3::Set(double x, double y, double z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}
	
	double Point3::X() const
	{
		return m_x;
	}
	
	double Point3::Y() const
	{
		return m_y;
	}
	
	double Point3::Z() const
	{
		return m_z;
	}
	
	double Point3::DistanceWith(const Point3& point) const
	{
		return DistanceBetweenPoints(*this, point);
	}
	
	Vector3 Point3::VectorTo(const Point3& point) const
	{
		return VectorBetweenPoints(*this, point);
	}

	Point3 Point3::MidpointTo(const Point3& point) const
	{
		return MidpointBetweenPoints(*this, point);
	}
	
	double Point3::DistanceBetweenPoints(const Point3& point1, const Point3& point2)
	{
		double
			sqX = (point2.m_x - point1.m_x) * (point2.m_x - point1.m_x),
			sqY = (point2.m_y - point1.m_y) * (point2.m_y - point1.m_y),
			sqZ = (point2.m_z - point1.m_z) * (point2.m_z - point1.m_z);

		return sqrt(sqX + sqY + sqZ);
	}
	
	Vector3 Point3::VectorBetweenPoints(const Point3& from, const Point3& to)
	{
		return Vector3(to.m_x - from.m_x, to.m_y - from.m_y, to.m_z - from.m_z);
	}

	Point3 Point3::MidpointBetweenPoints(const Point3& point1, const Point3& point2)
	{
		double
			x = (point2.m_x - point1.m_x) * 0.5,
			y = (point2.m_y - point1.m_y) * 0.5,
			z = (point2.m_z - point1.m_z) * 0.5;
		
		return Point3(x, y, z);
	}
	
	Vector3 operator-(const Point3& from, const Point3& to)
	{
		return Point3::VectorBetweenPoints(from, to);
	}
}