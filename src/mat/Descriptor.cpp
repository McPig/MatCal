#include "Descriptor.hpp"


// ------------
// Constructors
// ------------
Descriptor::Descriptor(size_t start, Pair sizes, Pair strides):
	m_start   {start},
	m_sizes   {move(sizes)},
	m_strides {move(strides)}
{}


Descriptor::Descriptor(Pair sizes):
	m_start   {0},
	m_sizes   {move(sizes)},
	m_strides {sizes.second, 1}
{}


// ---------
// Accessors
// ---------
size_t Descriptor::start() const {
	return m_start;
}


const Descriptor::Pair & Descriptor::sizes() const {
	return m_sizes;
}


const Descriptor::Pair & Descriptor::strides() const {
	return m_strides;
}


// ---------
// Subscript
// ---------
size_t Descriptor::operator()(size_t row, size_t column) const {
	return m_start + row * m_strides.first + column * m_strides.second;
}


size_t Descriptor::at(size_t row, size_t column) const {
	if (row < m_sizes.first && column < m_sizes.second)
		return operator()(row, column);

	std::stringstream ss;
	ss << "Descriptor: got indices (" << row << ", " << column << "), but the size is (" << m_sizes.first << ", "
	   << m_sizes.second << ")";
	throw std::out_of_range(ss.str());
}
