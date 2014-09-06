#include <iostream>
#include <stack>

using namespace std;

struct LinkNode
{
	int        m_nKey;
	LinkNode * m_pNext;
};

void AddToTail(LinkNode ** pHead, int value)
{
	LinkNode * pNew = new LinkNode();
	pNew->m_nKey = value;
	pNew->m_pNext = NULL;

	if (*pHead == NULL)
		*pHead = pNew;
	else
	{
		LinkNode * pNode = *pHead;
		while (pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pNew;
	}
}

void PrintReverse(LinkNode * pHead)
{
	LinkNode * pNode = pHead;
	stack<int> nodes_stack;
	while (pNode != NULL)
	{
		nodes_stack.push(pNode->m_nKey);
		pNode = pNode->m_pNext;
	}
	while(!nodes_stack.empty())
	{
		cout << nodes_stack.top() << " ";
		nodes_stack.pop();
	}
	cout << endl;
}

int main()
{
	LinkNode * pHead = NULL;
	AddToTail(&pHead, 4);
	AddToTail(&pHead, 5);
	AddToTail(&pHead, 3);
	PrintReverse(pHead);
	return 0;
}