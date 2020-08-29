#ifdef DEBUG

#include <vector>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "Descriptor.hpp"


class DescriptorTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(DescriptorTest);
	CPPUNIT_TEST(testStart);
	CPPUNIT_TEST(testSizes);
	CPPUNIT_TEST(testStrides);
	CPPUNIT_TEST(testSubscript);
	CPPUNIT_TEST_EXCEPTION(testSubscriptOutOfRange, std::out_of_range);
	CPPUNIT_TEST_SUITE_END();

public:
	void setUp() override;
	void tearDown() override;

protected:
	void testStart();
	void testSizes();
	void testStrides();
	void testSubscript();
	void testSubscriptOutOfRange();

private:
	Descriptor *     m_descA {};
	Descriptor *     m_descB {};
};


void DescriptorTest::setUp() {
	/*
	 *	11 12 13 14 15 16
	 *	21 22 23 24 25 26
	 *	31 32 33 34 35 36
	 *	41 42 43 44 45 46
	 */

	// describes the whole matrix
	m_descA = new Descriptor({4, 6});

	/*
	 *  describes this sub-matrix:
	 *  23 25
	 *  33 35
	 *  43 45
	 */
	m_descB = new Descriptor(8, {3, 2}, {6, 2});
}


void DescriptorTest::tearDown() {
	delete m_descA;
	delete m_descB;
}


void DescriptorTest::testStart() {
	CPPUNIT_ASSERT_EQUAL(0lu, m_descA->start());
	CPPUNIT_ASSERT_EQUAL(8lu, m_descB->start());
}


void DescriptorTest::testSizes() {
	CPPUNIT_ASSERT_EQUAL(4lu, m_descA->sizes().first);
	CPPUNIT_ASSERT_EQUAL(6lu, m_descA->sizes().second);
	CPPUNIT_ASSERT_EQUAL(3lu, m_descB->sizes().first);
	CPPUNIT_ASSERT_EQUAL(2lu, m_descB->sizes().second);
}


void DescriptorTest::testStrides() {
	CPPUNIT_ASSERT_EQUAL(6lu, m_descA->strides().first);
	CPPUNIT_ASSERT_EQUAL(1lu, m_descA->strides().second);
	CPPUNIT_ASSERT_EQUAL(6lu, m_descB->strides().first);
	CPPUNIT_ASSERT_EQUAL(2lu, m_descB->strides().second);
}


void DescriptorTest::testSubscript() {
	// Test m_descA
	size_t idx  {m_descA->start()};
	size_t rows {m_descA->sizes().first};
	size_t cols {m_descA->sizes().second};

	for (size_t i {0}; i < rows; ++i)
		for (size_t j {0}; j < cols; ++j)
			CPPUNIT_ASSERT_EQUAL(idx++, m_descA->operator()(i, j));

	// Test m_descB
	idx  = m_descB->start();
	rows = m_descB->sizes().first;
	cols = m_descB->sizes().second;

	for (size_t i {0}; i < rows; ++i) {
		for (size_t j {0}; j < cols; ++j) {
			CPPUNIT_ASSERT_EQUAL(idx, m_descB->operator()(i, j));
			idx += 2;
		}
		idx += 2;
	}
}


void DescriptorTest::testSubscriptOutOfRange() {
	m_descB->at(2, -1);
}


CPPUNIT_TEST_SUITE_REGISTRATION(DescriptorTest);

#endif  // DEBUG
