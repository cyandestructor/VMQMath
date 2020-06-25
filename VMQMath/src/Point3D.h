#ifndef VMQ_MATH_POINT3D_H
#define VMQ_MATH_POINT3D_H

#include "Vector3D.h"

namespace VMQ {

	class Point3D {

	public:
		Point3D() :m_x(0), m_y(0), m_z(0) {}
		Point3D(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}

		void Set(double, double, double);
		double X() const;
		double Y() const;
		double Z() const;
		double DistanceWith(const Point3D&) const;
		Vector3D VectorTo(const Point3D&) const;
		Point3D MidpointTo(const Point3D&) const;

		static double DistanceBetweenPoints(const Point3D&, const Point3D&);
		static Vector3D VectorBetweenPoints(const Point3D&, const Point3D&);
		static Point3D MidpointBetweenPoints(const Point3D&, const Point3D&);

	private:
		double m_x, m_y, m_z;

	};

	Vector3D operator-(const Point3D&, const Point3D&);

}

#endif