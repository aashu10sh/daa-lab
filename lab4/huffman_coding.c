#include <stdio.h>
#include <stdlib.h>

struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

struct HuffmanCode {
    char character;
    int* code;
    int codeLength;
    int frequency;
};

struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx, left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    int i;
    ++minHeap->size;
    i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

struct MinHeap* buildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    int i;
    for (i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    for (i = (minHeap->size - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = buildMinHeap(data, freq, size);
    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Global array to store all codes
struct HuffmanCode* huffmanCodes;
int codeIndex = 0;

void storeCodes(struct MinHeapNode* root, int arr[], int top) {
    int i;
    if (root->left) {
        arr[top] = 0;
        storeCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        storeCodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        huffmanCodes[codeIndex].character = root->data;
        huffmanCodes[codeIndex].frequency = root->freq;
        huffmanCodes[codeIndex].codeLength = top;
        
        huffmanCodes[codeIndex].code = (int*)malloc(top * sizeof(int));
        for (i = 0; i < top; i++) {
            huffmanCodes[codeIndex].code[i] = arr[i];
        }
        codeIndex++;
    }
}

void printCodes(struct MinHeapNode* root, int arr[], int top) {
    int i;
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

int calculateTotalBits(int size) {
    int totalBits = 0, i;
    for (i = 0; i < size; i++) {
        totalBits += huffmanCodes[i].frequency * huffmanCodes[i].codeLength;
    }
    return totalBits;
}

void HuffmanCodes(char data[], int freq[], int size) {
    huffmanCodes = (struct HuffmanCode*)malloc(size * sizeof(struct HuffmanCode));
    codeIndex = 0;
    
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[100], top = 0;
    
    storeCodes(root, arr, top);
    printCodes(root, arr, top);
    
    int totalBits = calculateTotalBits(size);
    printf("\nTotal bits after Huffman compression: %d\n", totalBits);
    
    int originalBits = 0, i;
    for (i = 0; i < size; i++) {
        originalBits += freq[i] * 8;
    }
    printf("Original bits (8 bits per character): %d\n", originalBits);
    
    float compressionRatio = (float)originalBits / totalBits;
    printf("Compression ratio: %.2f\n", compressionRatio);
}

int main() {
    printf("Name: Aashutosh Pudasaini\n");

    int n, i;
    printf("Enter the number of characters: ");
    scanf("%d", &n);

    char data[n];
    int freq[n];

    printf("Enter characters and their frequencies:\n");
    for (i = 0; i < n; i++) {
        scanf(" %c %d", &data[i], &freq[i]);  
    }

    printf("The compressed Huffman code is as follows:\n");

    HuffmanCodes(data, freq, n);
    
    for (i = 0; i < codeIndex; i++) {
        free(huffmanCodes[i].code);
    }
    free(huffmanCodes);
    
    return 0;
}