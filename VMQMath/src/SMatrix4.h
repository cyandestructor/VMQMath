#ifndef VMQMATH_SMATRIX4_H
#define VMQMATH_SMATRIX4_H

#include "TMatrix4.h"
#include "Vector3.h"

namespace VMQ {

	class SMatrix4 : private TMatrix4 {

	public:
		SMatrix4(const Vector3&);
		void SetScaleVector(const Vector3&);
		const Vector3& GetScaleVector() const;

	private:
		Vector3 m_sVector;

	};

}

#endif