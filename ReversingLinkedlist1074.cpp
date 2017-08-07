#include <iostream>
#include <vector>
#include <map>
#include "malloc.h"
using namespace std;

/*
	根据条件翻转链表
	给定k，使得每k个节点翻转
	思路：
	给定addr, k和n，n为节点数，addr为首节点地址
	* 使用map保存每个节点，包括地址和对应的节点 
	* 使用vector将节点顺序排列起来
	* 每k个节点反序打印出来 
	* 不足k个节点不打印 
*/
typedef struct {
	int data;
	int addr;
	int next_addr;
}Node;
int main() {
	int head;
	int node_num, step;
	int addr, next, data;
	map<int, Node*> node_map;
	vector<Node*> node_list;
	cin >> head >> node_num >> step;
	int i;
	for (i = 0; i < node_num; i++) {
		cin >> addr >> data >> next;
		Node *nnode = (Node*)malloc(sizeof(Node));
		nnode->addr = addr;
		nnode->data = data;
		nnode->next_addr = next;
		node_map[addr] = nnode;
	}
	while (head != -1) {
		if (node_map.find(head) == node_map.end()) {
			break;
		}
		Node *n = node_map[head];
		node_list.push_back(n);
		head = n->next_addr;
	}
	
	for (i = 0; i+step <= node_list.size(); i+=step) {
		for (int j = 0; j < step/2; j++) {
			Node *left = node_list[i+j];
			node_list[i+j] = node_list[i+step-j-1];
			node_list[i+step-j-1] = left; 
		}
	}
	for (i = 0; i < node_list.size()-1; i++) {
		Node *n = node_list[i];
		n->next_addr = node_list[i+1]->addr;
		printf("%05d %d %05d\n", n->addr, n->data, n->next_addr);
	}
	if (!node_list.empty()) {
		Node *n = node_list.back();
		printf("%05d %d -1\n", n->addr, n->data);
	}
	return 0;
}
