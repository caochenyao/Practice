#pragma once

struct TreeNode
{
	int _data;
	TreeNode* _left;
	TreeNode* _right;
	TreeNode(int data)
		:_data(data)
		, _left(NULL)
		, _right(NULL)
	{}
};
#if 0
//ÖØ½¨¶þ²æÊ÷
int Find(int* mid, int num,int left,int right)
{
	int i = left;
	while (i<=right)
	{
		if (mid[i] == num)
			break;
		i++;
	}
	return i;
}

TreeNode* RebuildTree(int* pre,int* mid,int left,int right,int& index)
{
	if (left > right)
		return NULL;
	
	TreeNode* root = new TreeNode(pre[index]);
	int find = Find(mid,pre[index],left,right);

	index++;
	root->_left = RebuildTree(pre, mid, left, find - 1,index);
	root->_right = RebuildTree(pre, mid, find + 1, right,index);
	return root;
}
#endif
void BinaryTreeTest()
{
#if 0
	int pre[8] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int mid[8] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	int index = 0;
	TreeNode* root = RebuildTree(pre,mid,0,7,index);
#endif


}