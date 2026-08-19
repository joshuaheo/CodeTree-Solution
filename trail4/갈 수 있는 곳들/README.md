# [[챌린지]갈 수 있는 곳들](https://www.codetree.ai/trails/complete/curated-cards/challenge-places-can-go)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / BFS / BFS 탐색](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 쉬움 |
| 경험치 | 40 XP |

## 개선하면 좋을 점

### 1. `x`, `y` 대신 `row`, `col` 사용

#### 현재

```cpp
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

x = q.front().second;
y = q.front().first;

pushing(q, visit, v, x + dx[j], y + dy[j]);
```

2차원 배열에서는 `v[y][x]`처럼 좌표 순서와 배열 인덱스 순서가 달라 헷갈릴 수 있다.

#### 개선 버전

```cpp
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int row = q.front().first;
int col = q.front().second;

pushing(q, visit, v, row + dr[j], col + dc[j]);
```

큐에도 `row`, `col` 순서로 저장한다.

```cpp
q.push({row, col});
```

#### 수정 이유

2차원 배열은 다음과 같이 접근한다.

```cpp
v[row][col]
```

따라서 BFS에서도 `row`, `col` 순서를 유지하면 큐 저장 순서와 배열 접근 순서가 같아져 좌표를 뒤집어 생각할 필요가 줄어든다.

---

### 2. 모든 시작점을 큐에 넣은 뒤 BFS 한 번 실행

#### 현재

```cpp
for (int i = 0; i < k; i++)
{
    q.push(start_point[i]);
    visit[start_point[i].first][start_point[i].second] = 1;

    while (!q.empty())
    {
        // BFS
    }
}
```

각 시작점마다 BFS를 하나씩 끝까지 실행했다.

#### 개선 버전

```cpp
for (int i = 0; i < k; i++)
{
    q.push(start_point[i]);
    visit[start_point[i].first][start_point[i].second] = 1;
}

while (!q.empty())
{
    int row = q.front().first;
    int col = q.front().second;

    for (int j = 0; j < 4; j++)
    {
        pushing(q, visit, v, row + dr[j], col + dc[j]);
    }

    q.pop();
}
```

#### 수정 이유

여러 시작점에서 이동 가능한 모든 영역을 구하는 경우, 시작점을 먼저 전부 큐에 넣은 뒤 BFS를 한 번만 실행할 수 있다.

이 방식을 **멀티 소스 BFS(Multi-source BFS)** 라고 하며, 여러 시작점에서 동시에 탐색이 퍼져나가는 형태로 처리할 수 있다.
