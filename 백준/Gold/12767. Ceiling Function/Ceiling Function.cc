#include <iostream>
#include <cstddef>
#include <cstring>

struct node
{
	node(int v = 0)
		: value(v), left(NULL), right(NULL) {}

	int value;
	node *left;
	node *right;
};

node trees[50];
int shapes[50];

void insertValue(node *root, int v)
{
	if (v < root->value)
	{
		if (root->left == NULL)
		{
			root->left = new node(v);
		}
		else
		{
			insertValue(root->left, v);
		}
	}
	else
	{
		if (root->right == NULL)
		{
			root->right = new node(v);
		}
		else
		{
			insertValue(root->right, v);
		}
	}
}

std::string findShape(node *root, int depth)
{
	if (root == NULL)
	{
		return "";
	}

	std::string s;
	if (root->left != NULL)
	{
		s += std::to_string(depth) + "l" + findShape(root->left, depth + 1);
	}
	if (root->right != NULL)
	{
		s += std::to_string(depth) + "r" + findShape(root->right, depth + 1);
	}

	return s;
}

int main()
{
	int N, K, v;
	std::cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> trees[i].value;
		for (int j = 0; j < K - 1; ++j)
		{
			std::cin >> v;
			insertValue(&trees[i], v);
		}
	}

	std::memset(shapes, -1, sizeof(shapes));
	int shapesCount = 0;

	for (int i = 0; i < N; ++i)
	{
		if (shapes[i] != -1)
		{
			continue;
		}
		auto s = findShape(&trees[i], 0);
		shapes[i] = shapesCount;
		for (int j = 0; j < N; ++j)
		{
			if (shapes[j] != -1)
			{
				continue;
			}
			auto p = findShape(&trees[j], 0);
			if (s == p)
			{
				shapes[j] = shapesCount;
			}
		}
		shapesCount++;
	}

	std::cout << shapesCount;

	return 0;
}