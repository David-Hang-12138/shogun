/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Written (W) 2013 Soumyajit De
 */

#ifndef MATRIX_OPERATOR_H_
#define MATRIX_OPERATOR_H_

#include <shogun/lib/config.h>
#include <shogun/mathematics/logdet/LinearOperator.h>

namespace shogun
{
template<class T> class SGVector;

/** @brief Abstract base class that represents a matrix linear operator.
 * It provides an interface to computes matrix-vector product \f$Ax\f$
 * in its apply method, \f$A\in\mathbb{C}^{m\times n},A:\mathbb{C}^{n}
 * \rightarrow \mathbb{C}^{m}\f$ being the matrix operator and \f$x\in
 * \mathbb{C}^{n}\f$ being the vector. The result is a vector \f$y\in
 * \mathbb{C}^{m}\f$.
 */
template<class T> class CMatrixOperator : public CLinearOperator<T>
{
public:
	/** default constructor */
	CMatrixOperator()
	: CLinearOperator<T>()
	{
	}

	/** 
	 * constructor
	 *
	 * @param dimension the dimension of the vector on which this it can apply
	 */
	CMatrixOperator(index_t dimension)
	: CLinearOperator<T>(dimension)
	{
	}

	/** destructor */
	~CMatrixOperator()
	{
	}

	/** 
	 * abstract method that applies the matrix linear operator to a vector
	 *
	 * @param b the vector to which the linear operator applies
	 * @return the result vector
	 */
	virtual SGVector<T> apply(SGVector<T> b) const = 0;

	/**
	 * abstract method that sets the main diagonal
	 *
	 * @param diag the diagonal to be set
	 */
	virtual void set_diagonal(SGVector<T> diag) = 0;

	/**
	 * abstract method that returns the main diagonal
	 *
	 * @return the main diagonal
	 */
	virtual SGVector<T> get_diagonal() const = 0;

	/** @return object name */
	virtual const char* get_name() const
	{
		return "CMatrixOperator";
	}

};

template class CMatrixOperator<bool>;
template class CMatrixOperator<char>;
template class CMatrixOperator<int8_t>;
template class CMatrixOperator<uint8_t>;
template class CMatrixOperator<int16_t>;
template class CMatrixOperator<uint16_t>;
template class CMatrixOperator<int32_t>;
template class CMatrixOperator<uint32_t>;
template class CMatrixOperator<int64_t>;
template class CMatrixOperator<uint64_t>;
template class CMatrixOperator<float32_t>;
template class CMatrixOperator<float64_t>;
template class CMatrixOperator<floatmax_t>;
template class CMatrixOperator<complex64_t>;

}

#endif // MATRIX_OPERATOR_H_
