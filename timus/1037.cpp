// Uses: heap, priority queue

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 30000;
const int T = 600;

struct Block {
  int num, p;
  Block(int num, int p) : num(num), p(p) {}
  Block() {}
};

bool operator<(const Block& a, const Block& b) {
  return a.p > b.p;
}

// Heap will hold all occupied blocks
// getMaximum will return the block which is the first to be freed
class Heap {
  private:
    int size;
    Block e[N + 1];

    void heapify(int i) {
      int l = i * 2, r = i * 2 + 1;
      int large = i;
      if (l <= size && e[large] < e[l]) large = l;
      if (r <= size && e[large] < e[r]) large = r;
      if (i != large) {
        swap(e[i], e[large]);
        ind[e[i].num] = i;
        ind[e[large].num] = large;
        heapify(large);
      }
    }

  public:
    // Maps block number -> heap index
    int ind[N + 1];
    Heap() : size(0) { memset(ind, 0, sizeof(ind)); }

    Block getMaximum() {
      return e[1];
    }

    void popMaximum() {
      ind[e[1].num] = 0;
      e[1] = e[size];
      --size;
      heapify(1);
    }

    void insert(Block b) {
      ++size;
      e[size] = b;
      ind[b.num] = size;
      int i = size;
      int parent = i / 2;
      while (i > 1 && e[parent] < e[i]) {
        swap(e[i], e[parent]);
        ind[e[i].num] = i;
        ind[e[parent].num] = parent;
        i = parent;
        parent = i / 2;
      }
    }

    void changePriority(int blockNumber, int newPriority) {
      int i = ind[blockNumber];
      e[i].p = newPriority;
      heapify(i);
    }

    bool empty() {
      return size == 0;
    }
} heap;

int main(int argc, char const *argv[])
{
  // Priority queue will hold all free blocks
  // top() will return the free block with the least number
  priority_queue <int, vector <int>, greater <int> > f;
  int xn, expire, curtime;
  char xc;
  Block b;
  // Initially, all blocks are free
  for (int i = 1; i <= N; i++) f.push(i);
  while (true) {
    scanf("%d %c", &curtime, &xc);
    if (feof(stdin)) break;
    expire = curtime + T;
    while (!heap.empty() && heap.getMaximum().p <= curtime) {
      f.push(heap.getMaximum().num);
      heap.popMaximum();
    }
    if (xc == '+') {
      // Allocation request
      int num = f.top();
      f.pop();
      heap.insert(Block(num, expire));
      printf("%d\n", num);
    } else {
      // Access request
      scanf(" %d", &xn);
      char result = '-';
      if (heap.ind[xn]) {
        result = '+';
        // Access was succesful, so we must update priority of accessed block
        heap.changePriority(xn, expire);
      }
      printf("%c\n", result);
    }
  }
  return 0;
}
