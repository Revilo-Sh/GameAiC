#pragma once
#include "AgentsFSM.h"

namespace AIForGames {
	class _Condition
	{
	public: 
		virtual bool IsTrue(AgentsFSM* agent) = 0;
	};
}



