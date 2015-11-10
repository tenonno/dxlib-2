#pragma once

struct Matrix : MATRIX
{

	Matrix(const MATRIX &mat)
	{

		for (auto i : Rep(4))
		{
			for (auto j : Rep(4))
			{
				m[i][j] = mat.m[i][j];
			}
		}
	}

	float *operator[](const uint32 index)
	{
		return m[index];
	}


	/// <summary> ãtçsóÒÇ…ïœä∑ÇµÇ‹Ç∑ </summary>
	Matrix &inverse()
	{
		return (*this = MInverse(*this));
	}


	Matrix &transpose()
	{
		return *this = MTranspose(*this);
	}


	Matrix &cell(const uint32 index, const std::initializer_list<double> &values)
	{

		if (index >= 4 || values.size() > 4) throw std::out_of_range("");


		uint32 count = 0;
		for (const double value : values)
		{
			m[count++][index] = static_cast<float>(value);
		}

		return *this;
	}


	Matrix &row(const uint32 index, const std::initializer_list<double> &values)
	{
		uint32 count = 0;
		for (const double value : values)
		{
			m[index][count++] = static_cast<float>(value);
		}

		return *this;
	}



	static Matrix RotateX(const double rotate)
	{
		return MGetRotX(static_cast<float>(rotate));
	}

};
