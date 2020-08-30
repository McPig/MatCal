#ifndef MATCAL_DESCRIPTOR_HPP
#define MATCAL_DESCRIPTOR_HPP

#include <utility>
#include <sstream>


/**
 * @brief This class is an abstraction that allows to manipulate a one-dimensional array as if it were two-dimensional.
 *
 * Descriptor uses a mapping capable of describing the shape of a matrix or its part (row, column or sub-matrix) in
 * terms of three values:
 *  -# starting index,
 *  -# pair of sizes,
 *  -# pair of strides
 *
 * without need to declare nested structures such as two-dimensional array.
 */
class Descriptor {
public:
	using Pair = std::pair<size_t, size_t>;

	/**
	 * @brief Constructs a new Descriptor, setting attributes to the passed values.
	 * @param[in] start The index of the first element.
	 * @param[in] sizes The pair of sizes (rows, columns).
	 * @param[in] strides The pair of distances (between rows, between columns).
	 */
	Descriptor(size_t start, Pair sizes, Pair strides);

	/**
	 * @brief Constructs a new Descriptor, setting sizes to the passed value.
	 *
	 * Sets starting index to 0, sets strides to (columns, 1).
	 * @param[in] sizes The pair of sizes (rows, columns).
	 */
	explicit Descriptor(Pair sizes);

	/**
	 * @brief Defaulted destructor.
	 */
	~Descriptor() = default;

	/**
	 * @brief Returns the starting index.
	 * @return The first index.
	 */
	size_t start() const;

	/**
	 * @brief Returns the pair of sizes (rows, columns).
	 * @return The pair of sizes.
	 */
	const Pair & sizes() const;

	/**
	 * @brief Returns the pair of strides (between rows, between columns).
	 * @return The pair of strides.
	 */
	const Pair & strides() const;

	/**
	 * @brief Subscript operator that maps row and column indices to the actual array index. No bounds check performed.
	 * @param[in] row The row index.
	 * @param[in] column The column index.
	 * @return The actual index from the array.
	 */
	size_t operator()(size_t row, size_t column) const;

	/**
	 * @brief Maps row and column indices to the actual array index. Performs bounds check.
	 *
	 * The method automatically checks whether passed values are within the bounds throwing a std::out_of_range
	 * exception if they are not.
	 * @param[in] row The row index.
	 * @param[in] column The column index.
	 * @return The actual index from the array.
	 * @throw std::out_of_range exception if row or column are not valid indices.
	 */
	size_t at(size_t row, size_t column) const;

private:
	size_t m_start;    // first index
	Pair   m_sizes;    // number of rows, number of columns
	Pair   m_strides;  // distance between rows, distance between columns
};


#endif  // MATCAL_DESCRIPTOR_HPP
