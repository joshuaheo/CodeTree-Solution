# [[개념]최소 경로로 탈출하기](https://www.codetree.ai/trails/complete/curated-cards/intro-escape-with-min-distance)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / BFS / 가중치가 동일한 그래프에서의 BFS](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 쉬움 |
| 경험치 | 40 XP |

## 개선점 및 배운 점

### 1. `q.size()`를 이용한 레벨 단위 BFS

BFS에서는 같은 시점에 큐에 들어 있는 노드들이 같은 이동 거리를 가질 수 있다.

```cpp
while (!q.empty())
{
    count++;

    int size = q.size();

    while (size--)
    {
        auto [row, col] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int drow = row + dr[i];
            int dcol = col + dc[i];

            pushing(q, visit, drow, dcol);
        }
    }
}
```

`int size = q.size();`로 현재 큐에 들어 있는 노드의 개수를 미리 저장하면, 탐색 도중 새로 `push()`되는 노드는 다음 반복에서 처리된다.

따라서 별도의 큐를 만들어

```cpp
f = q;
```

처럼 현재 레벨을 복사할 필요가 없다.

```text
현재 q의 노드들
→ 같은 거리의 노드 처리
→ 새로 발견한 노드는 q 뒤에 추가
→ 다음 while에서 다음 거리 탐색
```

큐 전체 복사를 없앨 수 있어 기존 방식보다 간단하고 불필요한 복사 비용도 줄어든다.

---

### 2. `tuple`에 이동 거리를 함께 저장하는 BFS

각 좌표와 함께 현재까지의 이동 거리를 큐에 직접 저장할 수도 있다.

```cpp
queue<tuple<int, int, int>> q;
q.push({0, 0, 0});
```

각 값은 다음과 같이 사용할 수 있다.

```cpp
auto [row, col, dist] = q.front();
q.pop();

if (row == n - 1 && col == m - 1)
{
    answer = dist;
    break;
}
```

다음 칸을 큐에 넣을 때 거리를 1 증가시킨다.

```cpp
q.push({drow, dcol, dist + 1});
```

이 방식에서는 각 노드가 자신의 이동 거리를 직접 가지고 있으므로

```cpp
count
q.size()
```

를 이용해 BFS 레벨을 따로 관리할 필요가 없다.

```text
(row, col, dist)
        ↓
다음 칸 이동
        ↓
(drow, dcol, dist + 1)
```

### 정리

두 방법 모두 BFS의 최단거리를 구하는 방식이다.

```cpp
// 레벨 단위로 거리 관리
int size = q.size();
```

```cpp
// 각 노드에 거리 직접 저장
queue<tuple<int, int, int>> q;
```

`q.size()` 방식은 **같은 거리의 노드를 한 번에 처리할 때**, `tuple` 방식은 **각 위치의 거리를 직접 가지고 다니고 싶을 때** 사용할 수 있다.

