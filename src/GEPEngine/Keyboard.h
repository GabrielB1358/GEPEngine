#include <memory>
#include <vector>

namespace GEPEngine
{
	struct Core;

	struct Keyboard
	{
		bool getKey(int keyCode);
		bool getKeyDown(int keyCode);
		bool getKeyUp(int keyCode);

	private:
		std::vector<int> keyCodes;
	};
}