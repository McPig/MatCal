#ifdef DEBUG

#include <gtest/gtest.h>

#include "Descriptor.hpp"


class DescriptorTest : public testing::Test {
protected:
	DescriptorTest();

	~DescriptorTest() override;

	Descriptor * m_descA;
	Descriptor * m_descB;
};


DescriptorTest::DescriptorTest():
	testing::Test(),
	m_descA {new Descriptor({4, 6})},
	m_descB {new Descriptor(8, {3, 2}, {6, 2})}
{
	/*
	 *  Given the matrix:
	 *	11 12 13 14 15 16
	 *	21 22 23 24 25 26
	 *	31 32 33 34 35 36
	 *	41 42 43 44 45 46
	 *
	 *	descA describes the whole matrix
	 *
	 *	descB describes this sub-matrix:
	 *	23 25
	 *  33 35
	 *  43 45
	 */
}


DescriptorTest::~DescriptorTest() {
	delete m_descA;
	delete m_descB;
}


TEST_F(DescriptorTest, startWorks) {
	EXPECT_EQ(0, m_descA->start());
	EXPECT_EQ(8, m_descB->start());
}


TEST_F(DescriptorTest, sizesWorks) {
	EXPECT_EQ(4, m_descA->sizes().first);
	EXPECT_EQ(6, m_descA->sizes().second);
	EXPECT_EQ(3, m_descB->sizes().first);
	EXPECT_EQ(2, m_descB->sizes().second);
}


TEST_F(DescriptorTest, stridesWorks) {
	EXPECT_EQ(6, m_descA->strides().first);
	EXPECT_EQ(1, m_descA->strides().second);
	EXPECT_EQ(6, m_descB->strides().first);
	EXPECT_EQ(2, m_descB->strides().second);
}


TEST_F(DescriptorTest, subscriptOperatorWorks) {
	// Test m_descA
	size_t idx  {m_descA->start()};
	size_t rows {m_descA->sizes().first};
	size_t cols {m_descA->sizes().second};

	for (size_t i {0}; i < rows; ++i)
		for (size_t j {0}; j < cols; ++j)
			EXPECT_EQ(idx++, m_descA->operator()(i, j));

	// Test m_descB
	idx  = m_descB->start();
	rows = m_descB->sizes().first;
	cols = m_descB->sizes().second;

	for (size_t i {0}; i < rows; ++i) {
		for (size_t j {0}; j < cols; ++j) {
			EXPECT_EQ(idx, m_descB->operator()(i, j));
			idx += 2;
		}
		idx += 2;
	}
}


TEST_F(DescriptorTest, atThrows) {
	EXPECT_THROW(m_descB->at(2, -1), std::out_of_range);
}


#endif  // DEBUG
