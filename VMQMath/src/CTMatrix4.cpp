#include "CTMatrix4.h"

namespace VMQ {

	void CTMatrix4::PushTransformation(const TMatrix4& transformation)
	{
		std::unique_ptr<TMatrix4> tMatrix = std::make_unique<TMatrix4>(transformation);
		m_transformationList.push_front(std::move(tMatrix));
	}

	void CTMatrix4::PopTransformation()
	{
		m_transformationList.pop_front();
	}
	
	TMatrix4 CTMatrix4::GetTransformationMatrix() const
	{
		TMatrix4 tMatrix;
		
		for (auto& transformation : m_transformationList) {
			tMatrix = tMatrix * (*transformation);
		}

		return tMatrix;
	}

}