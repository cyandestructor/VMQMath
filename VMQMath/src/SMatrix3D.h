#ifndef VMQMATH_SMATRIX3D_H
#define VMQMATH_SMATRIX3D_H

#include "TMatrix3D.h"

namespace VMQ {

	class SMatrix3D : private TMatrix3D {

	public:
		SMatrix3D(const Vector3D&);
		void SetScaleVector(const Vector3D&);
		const Vector3D& GetScaleVector() const;

	private:
		Vector3D m_sVector;

	};

}

#endif