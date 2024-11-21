#pragma once
#include "_Condition.h"
#include "AgentsFSM.h"


namespace AIForGames {
	class _DistanceCondition : public _Condition
	{
	private:
		float m_distance;
		bool m_lessThan;

	public:
		_DistanceCondition(float d, bool It) : m_distance(d), m_lessThan(It) {}
		virtual bool IsTrue(AgentsFSM* agent);

	};
}



