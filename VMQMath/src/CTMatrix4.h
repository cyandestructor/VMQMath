#ifndef VMQMATH_CTMATRIX4_H
#define VMQMATH_CTMATRIX4_H

#include <list>
#include <memory>

#include "TMatrix4.h"

namespace VMQ {

	class CTMatrix4 {

	public:
		void PushTransformation(const TMatrix4&);
		void PopTransformation();
		TMatrix4 GetTransformationMatrix() const;

	private:
		std::list<std::unique_ptr<TMatrix4>> m_transformationList;

	};

}

#endif // !VMQMATH_CTMATRIX3D_H
