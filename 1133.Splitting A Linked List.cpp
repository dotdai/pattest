#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
using namespace std;

typedef struct Node {
	char Address[5];
	int Data;
	char NAddr[5];
	Node* Next;
}*LNode, *List;

List CreateList() {
	List L = (List)malloc(sizeof(Node));
	L->Next = NULL;
	return L;
}

void InsertList(LNode n, List L) {
	LNode c = L;
	while (c->Next) {
		c = c->Next;
	}
	strcpy(c->NAddr, n->Address);
	c->Next = n;
}

void InsertPos(LNode n, LNode Pos) {
	strcpy(Pos->NAddr, n->Address);
	Pos->Next = n;
}

LNode CreateNode(char* Address,int Data, char* NAddr) {
	LNode n = (LNode)malloc(sizeof(Node));
	strcpy(n->Address, Address);
	n->Next = NULL;
	n->Data = Data;
	strcpy(n->NAddr, NAddr);
	return n;
}

void SplitList(List L0, int K) {
	List L1 = CreateList();
	List L2 = CreateList();
	List L3 = CreateList();
	LNode l = L0->Next;
	LNode l1 = L1;
	LNode l2 = L2;
	LNode l3 = L3;
	while (l) {
		LNode del = l;
		strcpy(del->NAddr, "-1");
		l = del->Next;
		del->Next = NULL;
		if (del->Data < 0) {
			InsertPos(del, l1);
			l1 = del;
		} else if (del->Data <= K) {
			InsertPos(del, l2);
			l2 = del;
		} else {
			InsertPos(del, l3);
			l3 = del;
		}
	}
	if (L2->Next) {
		InsertList(L2->Next, L1);
	}
	if (L3->Next) {
		InsertList(L3->Next, L1);
	}
	l1 = L1->Next;
	while (l1) {
		printf("%s %d %s\n", l1->Address, l1->Data, l1->NAddr);
		l1 = l1->Next;
	}
}

int main() {
	int K, N, data;
	char FirstAddr[5], addr[5], naddr[5];
	scanf("%s %d %d", &FirstAddr, &N, &K);
	List L0 = CreateList();
	map<string, LNode> inputs;
	while(N--) {
		scanf("%s %d %s", &addr, &data, &naddr);
		LNode n = CreateNode(addr, data, naddr);
		inputs.insert(make_pair(addr, n));
	}
	LNode n = inputs[FirstAddr];
	while(n && strcmp(n->NAddr, "-1")) {
		InsertList(n, L0);
		n = inputs[n->NAddr];
	} 
	InsertList(n, L0);
	SplitList(L0, K);
}
