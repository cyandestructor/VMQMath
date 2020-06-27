#include "CTMatrix3D.h"

namespace VMQ {

	void CTMatrix3D::PushTransformation(const TMatrix3D& transformation)
	{
		std::unique_ptr<TMatrix3D> tMatrix = std::make_unique<TMatrix3D>(transformation);
		m_transformationList.push_front(std::move(tMatrix));
	}

	void CTMatrix3D::PopTransformation()
	{
		m_transformationList.pop_front();
	}
	
	TMatrix3D CTMatrix3D::GetTransformationMatrix() const
	{
		TMatrix3D tMatrix;
		
		for (auto& transformation : m_transformationList) {
			tMatrix = tMatrix * (*transformation);
		}

		return tMatrix;
	}

}