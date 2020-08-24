#ifdef DEBUG
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Descriptor.hpp"


class DescriptorTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(DescriptorTest);
	CPPUNIT_TEST(testAt);
	CPPUNIT_TEST_EXCEPTION(testAtOutOfRange, std::out_of_range);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp() override;
	void tearDown() override;

protected:
	void testAt();
	void testAtOutOfRange();

private:
	Descriptor * m_desc {};
};


void DescriptorTest::setUp() {
	// Describes 4x5 mat
	m_desc = new Descriptor(0, {4, 5}, {5, 1});
}


void DescriptorTest::tearDown() {
	delete m_desc;
}


void DescriptorTest::testAt() {
	size_t idx  {m_desc->m_start};
	size_t rows {m_desc->m_sizes.first};
	size_t cols {m_desc->m_sizes.second};

	for (size_t i {0}; i < rows; ++i)
		for (size_t j {0}; j < cols; ++j)
			CPPUNIT_ASSERT_EQUAL(m_desc->at(i, j), idx++);
}


void DescriptorTest::testAtOutOfRange() {
	m_desc->at(2, 5);
}


CPPUNIT_TEST_SUITE_REGISTRATION(DescriptorTest);

#endif  // DEBUG