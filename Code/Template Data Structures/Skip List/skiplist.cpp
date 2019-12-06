#include "skiplist.h"

template<typename T>
skipList<T>::node::node(T data, int lvl) {
  this->data = data;
  next         = new node *[lvl + 1];
  prev         = new node *[lvl + 1];
  memset(next, 0, sizeof(node *) * (lvl + 1));
  memset(prev, 0, sizeof(node *) * (lvl + 1));
}

template<typename T>
skipList<T>::node::~node() {
  delete[] prev;
  delete[] next;
}

template<typename T>
skipList<T>::skipList(int n) {
  maxLvl = ceil(log(n));
  level  = 0;
  head   = new node(-INF, maxLvl);
  tail   = new node(INF, maxLvl);

  for (int i = 0; i <= maxLvl; ++i) {
    head->next[i] = tail;
    tail->prev[i] = head;
  }
}

template<typename T>
skipList<T>::~skipList() {
  node *now = head->next[0];

  while (now != tail) {
    now = now->next[0];
    delete now->prev[0];
  }
  delete head;
  delete tail;
}

template<typename T>
int skipList<T>::getRandLevel(int maxLvl) {
  int randLevel = 0;

  while (rand() % 2 == 1 && randLevel < maxLvl) {
    ++randLevel;
  }
  return randLevel;
}

template<typename T>
void skipList<T>::insert(T data) {
  node *now = head;

  node *update[maxLvl + 1];

  memset(update, 0, sizeof(T *) * (maxLvl + 1));

  for (int i = level; i >= 0; --i) {
    while (now->next[i]->data < data) {
      now = now->next[i];
    }
    update[i] = now;
  }

  int randLevel = getRandLevel(maxLvl);

  if (randLevel > level)
  {
    for (int i = level + 1; i <= randLevel; i++) {
      update[i] = head;
    }
    level = randLevel;
  }
  now = new node(data, randLevel);

  for (int i = 0; i <= randLevel; i++)
  {
    now->next[i]                  = update[i]->next[i];
    now->prev[i]                  = update[i];
    update[i]->next[i]->prev[i] = now;
    update[i]->next[i]          = now;
  }
}

template<typename T>
void skipList<T>::remove(T data)
{
  node *now = head;

  node *update[maxLvl + 1];

  memset(update, 0, sizeof(T *) * (maxLvl + 1));

  for (int i = level; i >= 0; i--)
  {
    while (now->next[i]->data < data) {
      now = now->next[i];
    }
    update[i] = now;
  }

  now = now->next[0];

  if (now->data == data)
  {
    for (int i = 0; i <= level; i++)
    {
      if (update[i]->next[i] != now) {
        break;
      }
      update[i]->next[i]    = now->next[i];
      now->next[i]->prev[i] = update[i];
    }
    delete now;

    while (level > 0 && head->next[level] == tail) {
      level--;
    }
    cout << "Successfully deleted points " << data << "\n";
  }
}

template<typename T>
void skipList<T>::search(T data) {
  node *now = head;

  for (int i = level; i >= 0; i--)
  {
    while (now->next[i]->data < data) {
      now = now->next[i];
    }
  }
  now = now->next[0];

  if (now->data == data) {
    cout << "Found points: " << data << "\n";
  } else {
    cout << "Cannot find " << data << "\n";
  }
}

template<typename T>
void skipList<T>::displayList() {
  cout << "\n*****Skip List*****" << "\n";

  for (int i = level; i >= 0; --i)
  {
    node *now = head->next[i];
    cout << "Level " << i << ": ";

    while (now != tail)
    {
      cout << now->data << " ";
      now = now->next[i];
    }
    cout << "\n";
  }
}

template class skipList<int>;
template class skipList<float>;
