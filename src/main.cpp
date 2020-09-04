#ifdef DEBUG
#include <gtest/gtest.h>
#endif  // DEBUG

int main(int argc, char * argv[]) {
#ifdef DEBUG
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
#endif  // DEBUG

	return 0;
}
