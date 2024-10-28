#include <cstdio>
#include <iostream>
#include <string.h>

#define MAX (20)

const int DY[4] = {0, 0, -1, 1};
const int DX[4] = {-1, 1, 0, 0};

void (*g_move[4])(int **, int);

int **g_board;
int g_size;
int g_max;

void input(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> g_size;

  g_board = (int **)malloc(sizeof(int *) * g_size);
  g_board[0] = (int *)malloc(sizeof(int) * g_size * g_size);
  for (int i = 1; i < g_size; ++i)
    g_board[i] = g_board[i - 1] + g_size;

  for (int i = 0; i < g_size; ++i) {
    for (int j = 0; j < g_size; ++j) {
      std::cin >> g_board[i][j];
    }
  }
}

void move_up(int **board, int size) {
  for (int col = 0; col < size; ++col) {
    /* Combine with the same number */
    for (int row = 0; row < size; ++row) {
      int &cur = board[row][col];
      if (cur == 0) {
        continue;
      }

      for (int i = row + 1; i < size; ++i) {
        int &below = board[i][col];
        if (below == 0) {
          continue;
        } else if (below == cur) {
          cur += below;
          below = 0;
          break;
        } else {
          break;
        }
      }
    }

    /* move blocks upward */
    for (int row = 0; row < size; ++row) {
      int &cur = board[row][col];
      if (cur != 0) {
        continue;
      }

      for (int i = row + 1; i < size; ++i) {
        int &below = board[i][col];
        if (below == 0)
          continue;
        cur = below;
        below = 0;
        break;
      }
    }
  }
}

void move_down(int **board, int size) {
  for (int col = 0; col < size; ++col) {
    /* Combine with the same number */
    for (int row = size - 1; row >= 0; --row) {
      int &cur = board[row][col];
      if (cur == 0) {
        continue;
      }

      for (int i = row - 1; i >= 0; --i) {
        int &above = board[i][col];
        if (above == 0) {
          continue;
        } else if (above == cur) {
          cur += above;
          above = 0;
          break;
        } else {
          break;
        }
      }
    }

    /* move blocks downward */
    for (int row = size - 1; row >= 0; --row) {
      int &cur = board[row][col];
      if (cur != 0) {
        continue;
      }

      for (int i = row - 1; i >= 0; --i) {
        int &above = board[i][col];
        if (above == 0)
          continue;
        cur = above;
        above = 0;
        break;
      }
    }
  }
}

void move_left(int **board, int size) {
  for (int row = 0; row < size; ++row) {
    /* Combine with the same number */
    for (int col = 0; col < size; ++col) {
      int &cur = board[row][col];
      if (cur == 0) {
        continue;
      }

      for (int i = col + 1; i < size; ++i) {
        int &right = board[row][i];
        if (right == 0) {
          continue;
        } else if (right == cur) {
          cur += right;
          right = 0;
          break;
        } else {
          break;
        }
      }
    }

    /* shift blocks to left */
    for (int col = 0; col < size; ++col) {
      int &cur = board[row][col];
      if (cur != 0) {
        continue;
      }

      for (int i = col + 1; i < size; ++i) {
        int &right = board[row][i];
        if (right == 0)
          continue;
        cur = right;
        right = 0;
        break;
      }
    }
  }
}

void move_right(int **board, int size) {
  for (int row = 0; row < size; ++row) {
    /* Combine with the same number */
    for (int col = size - 1; col >= 0; --col) {
      int &cur = board[row][col];
      if (cur == 0) {
        continue;
      }

      for (int i = col - 1; i >= 0; --i) {
        int &left = board[row][i];
        if (left == 0) {
          continue;
        } else if (left == cur) {
          cur += left;
          left = 0;
          break;
        } else {
          break;
        }
      }
    }

    /* shift blocks to left */
    for (int col = size - 1; col >= 0; --col) {
      int &cur = board[row][col];
      if (cur != 0) {
        continue;
      }

      for (int i = col - 1; i >= 0; --i) {
        int &left = board[row][i];
        if (left == 0)
          continue;
        cur = left;
        left = 0;
        break;
      }
    }
  }
}

void dfs(int depth, int **board) {
  if (depth == 5) {
    for (int i = 0; i < g_size; ++i) {
      for (int j = 0; j < g_size; ++j) {
        if (board[i][j] > g_max)
          g_max = board[i][j];
      }
    }
    return;
  }

  int **dup = (int **)malloc(sizeof(int *) * g_size);
  dup[0] = (int *)malloc(sizeof(int) * g_size * g_size);
  for (int i = 1; i < g_size; ++i)
    dup[i] = dup[i - 1] + g_size;

  memmove(dup[0], board[0], sizeof(int) * g_size * g_size);

  for (int i = 0; i < 4; ++i) {
    g_move[i](board, g_size);
    dfs(depth + 1, board);
    memmove(board[0], dup[0], sizeof(int) * g_size * g_size);
  }

  free(dup[0]);
  free(dup);
}

void solve(void) {
  g_move[0] = move_up;
  g_move[1] = move_down;
  g_move[2] = move_left;
  g_move[3] = move_right;

  dfs(0, g_board);

  std::cout << g_max;
}

int main(void) {
  input();
  //   for (int i = 0; i < g_size; ++i) {
  //     for (int j = 0; j < g_size; ++j) {
  //       std::cout << g_board[i][j] << ' ';
  //     }
  //     std::cout << '\n';
  //   }
  solve();

  free(g_board[0]);
  free(g_board);

  return 0;
}