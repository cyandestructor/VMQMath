#ifndef VMQMATH_RMATRIX3D_H
#define VMQMATH_RMATRIX3D_H

#include "TMatrix3D.h"
#include "Axes.h"
#include "Quaternion.h"

namespace VMQ {

	class RMatrix3D : public TMatrix3D {

	public:
		RMatrix3D(double, Axes);
		RMatrix3D(const Quaternion&);

	};

}

#endif