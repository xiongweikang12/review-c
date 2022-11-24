
#ifndef Function_gobal_template
#define Function_gobal_template


template <typename T>
void show_fill_label(const T& fill_label, int size_)
{
	//展示表达现在的graph标签
	auto temp = fill_label;
	cout << "\n";
	for (int i =0; i < size_; i++)
	{
		if (i == size_ - 1)
		{
			cout << temp[i];
		}
		else
		{
			cout << temp[i] << "->";
		}
	}
}

template <typename T>
void show_mat(const T& Graph_mat, int size_)
{
	cout << "\n";
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			cout << Graph_mat[i][j]<<"\t ";
		}
		cout << "\n";
	}
}

template <typename T1,typename T2>
void set_mat(const T1& source_Graph_mat,T2& des_tion_Graph_mat,int size_)
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			des_tion_Graph_mat[i][j] = source_Graph_mat[i][j];
		}
	}
}

template <typename T1>
void fill_INF(T1& source, float fill_number,int size_)
{
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			source[i][j] = fill_number;
		}
	}
}


#endif // !Function_gobal_template
