#ifndef HUFF_ARRY_HEADER
#define HUFF_ARRY_HEADER


#define HUFF_API _declspec(dllexport)
#ifdef __cplusplus
extern "C"
{

#endif
	typedef struct huff_node
	{
		int weight;
		int parent;
		int rchild;
		int lchild;
	}Huff_node, * Huff_tree;

	HUFF_API void  _stdcall CreatHuffmanTree(Huff_tree HT, int n);
#ifdef _cplusplus

}

#endif 
#endif
