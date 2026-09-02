# [[챌린지]비를 피하기](https://www.codetree.ai/trails/complete/curated-cards/challenge-stay-out-of-rain)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / BFS / 가중치가 동일한 그래프에서의 BFS](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 보통 |
| 경험치 | 80 XP |

## 개선점 및 권장사항

### 1. BFS 시작점도 큐에 넣는 순간 방문 처리

수정 전

```cpp
if (v[i][j] == 3)
{
    q.push({i, j, 0});
}
```

수정 후

```cpp
if (v[i][j] == 3)
{
    q.push({i, j, 0});
    visit[i][j] = 0;
}
```

### 수정 이유

BFS에서는 일반적으로 **큐에 넣는 순간 방문 처리를 한다.**

시작점 역시 이미 방문한 위치이므로 `visit = 0`으로 설정해야 한다.

설정하지 않으면 다른 시작점이나 주변 칸을 탐색하는 과정에서 해당 시작점이 다시 큐에 들어가는 중복 탐색이 발생할 수 있다.

---

### 2. `q.front()` 이후 바로 `pop()` 하는 방식 권장

기존 방식

```cpp
auto [row, col, count] = q.front();

for (int i = 0; i < 4; i++)
{
    pushing(...);
}

q.pop();
```

권장 방식

```cpp
auto [row, col, count] = q.front();
q.pop();

for (int i = 0; i < 4; i++)
{
    pushing(...);
}
```

### 권장 이유

현재 방식도 정상적으로 동작하지만, `pushing()` 내부에서 다시 `q.front()`를 사용하기 때문에 **현재 탐색 중인 값이 큐의 맨 앞에 남아 있어야 한다는 전제**가 생긴다.

보통 BFS에서는

```text
front()로 현재 값 저장
→ pop()
→ 저장한 값을 이용해 다음 위치 탐색
```

순서로 처리한다.

이렇게 하면 현재 노드의 정보와 큐 자체의 상태가 분리되어 코드 흐름이 더 명확해지고, 이후 `pop()` 위치를 변경하더라도 실수할 가능성이 줄어든다.

> 현재 코드가 틀린 것은 아니며, 일반적인 BFS 작성 습관으로 권장되는 방식이다.

