#ifndef VMQMATH_MMATRIX4_H
#define VMQMATH_MMATRIX4_H

#include "TMatrix4.h"
#include "Vector3.h"

namespace VMQ {

	class MMatrix4 : public TMatrix4 {

	public:
		MMatrix4(const Vector3&);
		void SetMoveVector(const Vector3&);
		const Vector3& GetMoveVector() const;

	private:
		Vector3 m_mVector;

	};

}

#endif