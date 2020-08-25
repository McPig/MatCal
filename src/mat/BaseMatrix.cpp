#ifndef MATCAL_BASEMATRIX_CPP
#define MATCAL_BASEMATRIX_CPP

#include "BaseMatrix.h"

// ------------
// Constructors
// ------------
template<typename T>
BaseMatrix<T>::BaseMatrix(const Descriptor & descriptor):
	m_desc {descriptor}
{}


template<typename T>
BaseMatrix<T>::BaseMatrix(size_t rows, size_t columns):
	m_desc {0, {rows, columns,}, {columns, 1}}
{}


// ---------
// Accessors
// ---------
template<typename T>
const Descriptor & BaseMatrix<T>::desc() const {
	return m_desc;
}


template<typename T>
size_t BaseMatrix<T>::n_rows() const {
	return m_desc.m_sizes.first;
}


template<typename T>
size_t BaseMatrix<T>::n_cols() const {
	return m_desc.m_sizes.second;
}


template<typename T>
size_t BaseMatrix<T>::size() const {
	return n_rows() * n_cols();
}


template<typename T>
T & BaseMatrix<T>::at(size_t row, size_t column) {
	return *(data() + m_desc.at(row, column));
}

template<typename T>
const T & BaseMatrix<T>::at(size_t row, size_t column) const {
	return *(data() + m_desc.at(row, column));
}


#endif  // MATCAL_BASEMATRIX_CPP