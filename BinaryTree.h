#pragma once
#include<queue>
#include<vector>

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

//重建二叉树
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
#if 0

//判断一个树是否是另一个树的子树
bool HasSameChild(TreeNode* root1, TreeNode* root2)
{
	if (root2 == NULL)
		return true;
	if (root1 == NULL)
		return false;
	if (root1->_data != root2->_data)
		return false;

	return HasSameChild(root1->_left, root2->_left) && HasSameChild(root1->_right, root2->_right);
}
bool HasSameRoot(TreeNode* root1,TreeNode* root2)
{
	bool result = false;
	if (root1 && root2)
	{
		if (root1->_data == root2->_data)
			result = HasSameChild(root1,root2);
		if (!result)
			result = HasSameRoot(root1->_left,root2);
		if (!result)
			result = HasSameRoot(root1->_right, root2);
	}
	return result;
}

void MirrorBinaryTree(TreeNode* root)
{
	if (root == NULL)
		return;
	if (root->_left == NULL && root->_right == NULL)
		return;

	TreeNode* tmp = root->_left;
	root->_left = root->_right;
	root->_right = tmp;

	if (root->_left)
		MirrorBinaryTree(root->_left);
	if (root->_right)
		MirrorBinaryTree(root->_right);
}

//层次遍历二叉树
void PrintFromTopToBottom(TreeNode* root)
{
	if (root == NULL)
	{
		cout << "NULL" << endl;
		return;
	}

	queue<TreeNode*> tree_queue;

	tree_queue.push(root);
	while (!tree_queue.empty())
	{
		TreeNode* cur = tree_queue.front();

		tree_queue.pop();

		cout << cur->_data << " ";

		if (cur->_left)
			tree_queue.push(cur->_left);
		if (cur->_right)
			tree_queue.push(cur->_right);
	}
	cout << endl;
}

//判断一个数组是不是二叉搜索树的后序遍历结果
bool IsOrderFromBack(int* sequeue, int len)
{
	if (sequeue == NULL || len <= 0)
		return false;

	int root = sequeue[len - 1];

	//找左子树的节点
	int i = 0;
	for (; i < len - 1;++i)
	{
		if (sequeue[i] > root)
			break;
	}
	//查找右子树节点的是否都大于根节点
	int j = i;
	for (; j < len - 1;++j)
	{
		if (sequeue[j] < root)
			return false;
	}

	bool left = true;
	if (i > 0)
		left = IsOrderFromBack(sequeue, i);

	bool right = true;
	if (j < len - 1)
		right = IsOrderFromBack(sequeue, len-i-1);

	return (left && right);
}
#endif
//二叉树中和为某一值的的路径
void FindPath_Add(TreeNode* root, int expentSum, vector<int>& path, int curSum)
{
	curSum += root->_data;
	path.push_back(root->_data);

	//如果到达叶子节点且路径上的节点值相加等于该值打印这条路径
	if (curSum == expentSum && root->_left == NULL && root->_right == NULL)
	{
		vector<int>::iterator it = path.begin();
		while (it != path.end())
		{
			printf("%d\t",*it);
			it++;
		}
		cout << endl;
	}

	if (root->_left)
		FindPath_Add(root->_left, expentSum, path, curSum);
	if (root->_right)
		FindPath_Add(root->_right, expentSum, path, curSum);

	//向上一层返回时从路径上删除当前节点
	path.pop_back();

}
void FindPath(TreeNode* root, int expentSum)
{
	if (root == NULL)
		return;

	int curSum = 0;
	vector<int> path;
	FindPath_Add(root, expentSum, path, curSum);
}


void BinaryTreeTest()
{

	int pre[8] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int mid[8] = { 4, 7, 2, 1, 5, 3, 8, 6 };

	int index = 0;
	TreeNode* root = RebuildTree(pre,mid,0,7,index);
#if 0

	MirrorBinaryTree(root);

	PrintFromTopToBottom(root);

	int array[7] = {5,7,6,9,4,10,8};
	cout << IsOrderFromBack(array, 7) << endl;
#endif
}