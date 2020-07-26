#ifndef VMQMATH_RMATRIX4_H
#define VMQMATH_RMATRIX4_H

#include "TMatrix4.h"
#include "Axis.h"
#include "Quaternion.h"

namespace VMQ {

	class RMatrix4 : public TMatrix4 {

	public:
		RMatrix4(double, Axis);
		RMatrix4(const Quaternion&);

	};

}

#endif