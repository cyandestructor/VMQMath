#ifndef VMQMATH_MMATRIX3D_H
#define VMQMATH_MMATRIX3D_H

#include "TMatrix3D.h"

namespace VMQ {

	class MMatrix3D : public TMatrix3D {

	public:
		MMatrix3D(const Vector3D&);
		void SetMoveVector(const Vector3D&);
		const Vector3D& GetMoveVector() const;

	private:
		Vector3D m_mVector;

	};

}

#endif