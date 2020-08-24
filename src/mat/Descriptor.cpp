#include "Descriptor.hpp"


Descriptor::Descriptor(size_t start, Pair sizes, Pair strides):
	m_start   {start},
	m_sizes   {move(sizes)},
	m_strides {move(strides)}
{}


size_t Descriptor::at(size_t row, size_t column) const {
	if (row < m_sizes.first && column < m_sizes.second)
		return m_start + row * m_strides.first + column * m_strides.second;

	std::stringstream ss;
	ss << "Descriptor: got indices (" << row << ", " << column << "), but the size is (" << m_sizes.first << ", "
	   << m_sizes.second << ")";
	throw std::out_of_range(ss.str());
}
