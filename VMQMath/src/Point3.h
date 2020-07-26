#ifndef VMQ_MATH_POINT3D_H
#define VMQ_MATH_POINT3D_H

namespace VMQ {

	class Vector3;

	class Point3 {

	public:
		Point3() :m_x(0), m_y(0), m_z(0) {}
		Point3(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}

		void Set(double, double, double);
		double X() const;
		double Y() const;
		double Z() const;
		double DistanceWith(const Point3&) const;
		Vector3 VectorTo(const Point3&) const;
		Point3 MidpointTo(const Point3&) const;

		static double DistanceBetweenPoints(const Point3&, const Point3&);
		static Vector3 VectorBetweenPoints(const Point3&, const Point3&);
		static Point3 MidpointBetweenPoints(const Point3&, const Point3&);

	private:
		double m_x, m_y, m_z;

	};

	Vector3 operator-(const Point3&, const Point3&);

}

#endif