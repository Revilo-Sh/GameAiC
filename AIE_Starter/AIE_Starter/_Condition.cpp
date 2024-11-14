#include "_Condition.h"
#include "AgentsFSM.h"

namespace AIForGames {
	class _Condition
	{
	public:
		virtual bool IsTrue(AgentsFSM* agents) = 0;

	};

}