#pragma once
#include<iostream>

const int MAX = 30;

class Queen
{
public :
	Queen(int size)
	{
		Size = size;
		count = 0;
		for(int i = 0;i<Size;++i)
			colFree[i] = true;
		for(int j = 0;j<2*Size-1;++j)
			upwardFree[j] = true;
		for(int k = 0;k<2*Size-1;++k)
			downwardFree[k] = true;
	}

	bool IsSolved() const
	{
		if(count == Size)
			return true;
		return false;
	}

	void Print() const
	{
		for(int i = 0;i<Size;++i)
		{
			for(int j = 0;j<Size;++j)
			{
				if(queenInRow[i]==j)
					std::cout<<'Q';
				else
					std::cout<<'*';
			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
	}

	bool Unguarded(int col) const
	{
		return colFree[col]&&upwardFree[count+col]&&downwardFree[count-col+Size-1];
	}

	void Insert(int col) 
	{
		queenInRow[count] = col;
		colFree[col] = false;
		upwardFree[count+col] = false;
		downwardFree[count-col+Size-1] = false;
		++count;
	}

	void Remove(int col)
	{
		--count;
		colFree[col] = true;
		upwardFree[count+col] = true;
		downwardFree[count-col+Size-1] = true;
	}

	int Size;
private:
	int count;
	bool colFree[MAX];
	bool upwardFree[2*MAX-1];
	bool downwardFree[2*MAX-1];
	int queenInRow[MAX];
};

void SolveFrom(Queen& ref)
{
	if(ref.IsSolved())
		ref.Print();
	else
	{
		for(int i = 0;i<ref.Size;++i)
		{
			if(ref.Unguarded(i))
			{
				ref.Insert(i);
				SolveFrom(ref);
				ref.Remove(i);
			}
		}
	}
}