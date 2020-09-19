#ifndef MATCAL_BASEMATRIX_HPP
#define MATCAL_BASEMATRIX_HPP

#include "Descriptor.hpp"


/**
 * @brief This abstract class is a base for all matrix-like classes.
 *
 * It does not hold any elements but stores information about matrix shape.
 * @tparam T The type of the matrix elements.
 */
template<typename T>
class BaseMatrix {
public:
	/**
	 * @brief Defaulted constructor.
	 */
	BaseMatrix() = default;

	/**
	 * @brief Defaulted copy constructor.
	 */
	BaseMatrix(const BaseMatrix &) = default;

	/**
	 * @brief Defaulted move constructor.
	 */
	BaseMatrix(BaseMatrix &&) noexcept = default;

	/**
	 * @brief Defaulted copy assignment operator.
	 * @return Reference to *this.
	 */
	BaseMatrix & operator=(const BaseMatrix &) = default;

	/**
	 * @brief Defaulted move assignment operator.
	 * @return Reference to *this.
	 */
	BaseMatrix & operator=(BaseMatrix &&) noexcept = default;

	/**
	 * @brief Defaulted virtual destructor.
	 */
	virtual ~BaseMatrix() noexcept = default;

	/**
	 * @brief Returns structure describing matrix shape.
	 * @return Matrix descriptor.
	 */
	const Descriptor & desc() const;

	/**
	 * @brief Returns the number of matrix rows.
	 * @return The number of rows.
	 */
	size_t n_rows() const;

	/**
	 * @brief Returns the number of matrix columns.
	 * @return The number of columns.
	 */
	size_t n_cols() const;

	/**
	 * @brief Returns the total number of matrix elements.
	 * @return The total number of elements.
	 */
	size_t size() const;

	/**
	 * @brief Provides direct "flat" access to the matrix elements.
	 *
	 * Since derived classes may use different kinds of element storage this method is pure virtual.
	 * @return Pointer to the first element of the matrix.
	 */
	virtual T * data() = 0;

	/**
	 * @brief Provides direct "flat" access to the matrix elements. Prohibits object modification.
	 *
	 * Since derived classes may use different kinds of element storage this method is pure virtual.
	 * @return
	 */
	virtual const T * data() const = 0;

	/**
	 * @brief Provides direct access to the matrix element stored at position (row, column).
	 * @param[in] row The row index.
	 * @param[in] column The column index.
	 * @return Reference to the element stored at position (row, column).
	 */
	T & at(size_t row, size_t column);

	/**
	 * @brief Provides direct access to the matrix element stored at position (row, column). Prohibits object
	 * modification.
	 * @param[in] row The row index.
	 * @param[in] column The column index.
	 * @return Reference to the const element stored at position (row, column).
	 */
	const T & at(size_t row, size_t column) const;

protected:
	/**
	 * Constructs a new BaseMatrix, setting descriptor to the passed value.
	 * @param[in] descriptor The descriptor to construct with.
	 */
	explicit BaseMatrix(const Descriptor & descriptor);

	/**
	 * Constructs a new BaseMatrix, creating its descriptor from the passed values.
	 * @param[in] rows The number of rows.
	 * @param[in] columns The number of columns.
	 */
	BaseMatrix(size_t rows, size_t columns);

	Descriptor m_desc;
};


#include "BaseMatrix.cpp"

#endif  // MATCAL_BASEMATRIX_HPP
