#include "Point3D.h"
#include <math.h>

namespace VMQ {

	void Point3D::Set(double x, double y, double z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}
	
	double Point3D::X() const
	{
		return m_x;
	}
	
	double Point3D::Y() const
	{
		return m_y;
	}
	
	double Point3D::Z() const
	{
		return m_z;
	}
	
	double Point3D::DistanceWith(const Point3D& point) const
	{
		return DistanceBetweenPoints(*this, point);
	}
	
	Vector3D Point3D::VectorTo(const Point3D& point) const
	{
		return VectorBetweenPoints(*this, point);
	}

	Point3D Point3D::MidpointTo(const Point3D& point) const
	{
		return MidpointBetweenPoints(*this, point);
	}
	
	double Point3D::DistanceBetweenPoints(const Point3D& point1, const Point3D& point2)
	{
		double
			sqX = (point2.m_x - point1.m_x) * (point2.m_x - point1.m_x),
			sqY = (point2.m_y - point1.m_y) * (point2.m_y - point1.m_y),
			sqZ = (point2.m_z - point1.m_z) * (point2.m_z - point1.m_z);

		return sqrt(sqX + sqY + sqZ);
	}
	
	Vector3D Point3D::VectorBetweenPoints(const Point3D& from, const Point3D& to)
	{
		return Vector3D(to.m_x - from.m_x, to.m_y - from.m_y, to.m_z - from.m_z);
	}

	Point3D Point3D::MidpointBetweenPoints(const Point3D& point1, const Point3D& point2)
	{
		double
			x = (point2.m_x - point1.m_x) * 0.5,
			y = (point2.m_y - point1.m_y) * 0.5,
			z = (point2.m_z - point1.m_z) * 0.5;
		
		return Point3D(x, y, z);
	}
	
	Vector3D operator-(const Point3D& from, const Point3D& to)
	{
		return Point3D::VectorBetweenPoints(from, to);
	}
}