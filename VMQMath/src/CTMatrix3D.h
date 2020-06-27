#ifndef VMQMATH_CTMATRIX3D_H
#define VMQMATH_CTMATRIX3D_H

#include <list>
#include <memory>
#include "TMatrix3D.h"

namespace VMQ {

	class CTMatrix3D {

	public:
		void PushTransformation(const TMatrix3D&);
		void PopTransformation();
		TMatrix3D GetTransformationMatrix() const;

	private:
		std::list<std::unique_ptr<TMatrix3D>> m_transformationList;

	};

}

#endif // !VMQMATH_CTMATRIX3D_H
