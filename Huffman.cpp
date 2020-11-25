// 2019015414_JeonYeonji_12838

#include <stdio.h>
#include <stdlib.h>

typedef struct HuffmanCode {
	char code[5];
	int freq;
} HuffmanCode;

typedef struct HuffmanTree {
	int freq;
	int is_code;
	HuffmanCode* code;
	HuffmanTree* leftchild, * rightchild;
} HuffmanTree;

typedef struct heapNode {
	int freq;
	HuffmanTree* h;
} heapNode;

HuffmanCode* huff;
HuffmanTree* huffTree, * root;
heapNode* minHeap;

void swapNode(heapNode* a, heapNode* b) {
	int temp;
	HuffmanTree* tempNode;
	tempNode = a->h;
	a->h = b->h;
	b->h = tempNode;
	temp = a->freq;
	a->freq = b->freq;
	b->freq = temp;
}

void BuildMinHeap(heapNode* minHeap, HuffmanTree * insertTree, int length) {
	int pre_length;
	int temp;
	length++;
	minHeap[length].h = insertTree;
	minHeap[length].freq = insertTree->freq;
	while (length > 1) {
		pre_length = length;
		length = length / 2;
		if (minHeap[length].freq < minHeap[pre_length].freq) {
			break;
		}
		swapNode(minHeap + length, minHeap + pre_length);
	}
}

void ExtractMin(heapNode* minHeap, int length) {
	swapNode(minHeap + 1, minHeap + length);
	length--;
	int nextidx;
	int idx = 1;
	while (1) {
		nextidx = idx;
		if (idx * 2 > length) {
			break;
		}
		else if (idx * 2 + 1 <= length && minHeap[idx * 2 + 1].freq < minHeap[idx].freq) {
			nextidx = idx * 2 + 1;
		}
		if (minHeap[idx * 2].freq < minHeap[nextidx].freq) {
			nextidx = idx * 2;
		}
		swapNode(minHeap + idx, minHeap + nextidx);
		if (nextidx == idx) {
			break;
		}
		idx = nextidx;
	}
}

HuffmanTree * makeHuffmanTreeNode(HuffmanCode* h) {
	HuffmanTree* newnode = (HuffmanTree*)malloc(sizeof(HuffmanTree));
	newnode->is_code = 1;
	newnode->freq = h->freq;
	newnode->code = h;
	return newnode;
}

HuffmanTree* makeMergeHuffmanTreeNode(HuffmanTree* st, HuffmanTree* nd) {
	HuffmanTree* newnode = (HuffmanTree*)malloc(sizeof(HuffmanTree));
	newnode->is_code = 0;
	newnode->freq = st->freq + nd->freq;
	newnode->leftchild = st;
	newnode->rightchild = nd;
	return newnode;
}

void mergeHuffmanTreeNode(HuffmanTree* st, HuffmanTree* nd, int heapLen) {
	HuffmanTree *newNode = makeMergeHuffmanTreeNode(st, nd);
	BuildMinHeap(minHeap, newNode, heapLen);
}

int findFixedCode(int n) {
	int f = 1;
	int cnt = 0;
	while (f < n) {
		f = f * 2;
		cnt++;
	}
	return cnt;
}

int findCode(HuffmanTree* node, int depth) {
	if (node->is_code == 1) {
		return node->code->freq* depth;
	}

	return findCode(node->leftchild, depth + 1) + findCode(node->rightchild, depth + 1);
}

void freeNode(HuffmanTree* node) {
	if (node->is_code == 1) {
		free(node);
		return;
	}

	freeNode(node->leftchild);
	freeNode(node->rightchild);
	free(node);
	return;
}

int main() {
	int n, total_freq;
	int heapLen = 0;
	int i;
	scanf("%d", &n); 
	HuffmanTree* node;
	minHeap = (heapNode*)malloc(sizeof(heapNode) * (n + 1));
	huff = (HuffmanCode*)malloc(sizeof(HuffmanCode) * (n + 1));
	for (i = 1; i <= n; i++) {
		scanf("%s %d", huff[i].code, &huff[i].freq);
		node = makeHuffmanTreeNode(huff + i);
		BuildMinHeap(minHeap, node, heapLen);
		heapLen++;
	}
	scanf("%d", &total_freq);

	printf("%d\n", findFixedCode(n) * total_freq);

	HuffmanTree* st, * nd;
	while (1) {
		if (heapLen == 1) {
			root = minHeap[1].h;
			break;
		}

		st = minHeap[1].h;
		ExtractMin(minHeap, heapLen);
		heapLen--;
		nd = minHeap[1].h;
		ExtractMin(minHeap, heapLen);
		heapLen--;
		mergeHuffmanTreeNode(st, nd, heapLen);
		heapLen++;
	}

	printf("%d\n", findCode(root, 0));

	freeNode(root);
	free(huff);
	free(minHeap);
	return 0;
}