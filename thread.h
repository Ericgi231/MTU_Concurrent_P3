#include "ThreadClass.h"

class SwapThread : public Thread {
	public:
		SwapThread(int i, int index) : i(i), index(index) {};
	private:
		int i;
		int index;
		void ThreadFunc();
};