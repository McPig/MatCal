#ifndef MATCAL_DESCRIPTOR_HPP
#define MATCAL_DESCRIPTOR_HPP

#include <utility>
#include <sstream>


/**
 * @brief This struct is an abstraction that allows to manipulate a one-dimensional array as a mat.
 *
 * It uses a mapping capable of describing the shape of a mat or its part (row, column or sub-mat) in terms of
 * three values:
 *  - starting index,
 *  - pair of sizes,
 *  - pair of strides
 * without need to declare nested structures such as two-dimensional array.
 */
struct Descriptor {
	using Pair = std::pair<size_t, size_t>;

	/**
	 * @brief Constructs a new Descriptor, setting attributes to the passed values.
	 * @param[in] start The index of the first element.
	 * @param[in] sizes The pair of sizes (rows, columns).
	 * @param[in] strides The pair of distances (between rows, between columns).
	 */
	Descriptor(size_t start, Pair sizes, Pair strides);

	/**
	 * @brief Defaulted destructor.
	 */
	~Descriptor() = default;

	/**
	 * @brief Maps row and column indices to the actual index.
	 * @param[in] row The row index.
	 * @param[in] column The column index.
	 * @return The actual index from the array.
	 * @throw std::out_of_range exception if row or column are not valid indices.
	 */
	size_t at(size_t row, size_t column) const;

	size_t m_start;    // first index
	Pair   m_sizes;    // number of rows, number of columns
	Pair   m_strides;  // distance between rows, distance between columns
};


#endif  // MATCAL_DESCRIPTOR_HPP
