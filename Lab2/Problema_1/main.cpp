#include "NumberList.h"

using namespace std;

int main() {
	NumberList list;
	list.Init();
	list.Add(4);
	list.Add(3);
	list.Add(10);
	list.Add(1);
	list.Add(8);

	list.Print();

	list.Sort();
	list.Print();
}