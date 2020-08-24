#ifdef DEBUG
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#endif  // DEBUG

int main(int argc, char * argv[]) {
#ifdef DEBUG
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry & registry {CppUnit::TestFactoryRegistry::getRegistry()};
	runner.addTest(registry.makeTest());

	bool success = runner.run("", false);

	return !success;
#endif  // DEBUG

	return 0;
}
