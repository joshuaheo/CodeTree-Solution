# [[챌린지]K개의 벽 없애기](https://www.codetree.ai/trails/complete/curated-cards/challenge-remove-k-walls)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / BFS / 가중치가 동일한 그래프에서의 BFS](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 보통 |
| 경험치 | 70 XP |

## 개선점 및 배운 점

### 1. 벽 선택을 `선택/비선택` 방식에서 조합 방식으로 변경

#### 수정 전

각 벽마다 현재 벽을 제거할지, 제거하지 않을지를 선택했다.

```cpp
v[wall[index].first][wall[index].second] = 0;
deleting(index + 1, count + 1, v);

v[wall[index].first][wall[index].second] = 1;
deleting(index + 1, count, v);
```

#### 수정 후

`start` 이후의 벽 중 하나를 직접 선택하는 조합 방식으로 변경할 수 있다.

```cpp
for (int i = start; i < wall.size(); i++)
{
    int row = wall[i].first;
    int col = wall[i].second;

    v[row][col] = 0;
    deleting(i + 1, count + 1, v);
    v[row][col] = 1;
}
```

#### 수정 이유

기존 방식도 모든 조합을 만들 수 있지만, 각 벽마다 `제거 / 제거하지 않음` 두 경우를 탐색한다.

이 문제처럼 **여러 개의 벽 중 정확히 K개를 선택하는 문제**에서는 `start` 이후의 원소를 하나씩 선택하는 조합 방식이 문제의 의미와 더 잘 맞는다.

`deleting(i + 1, ...)`로 다음 탐색 위치를 제한하기 때문에 이미 선택한 벽 이전으로 돌아가지 않으며, 같은 조합을 순서만 바꾸어 다시 선택하는 경우도 발생하지 않는다.

---

### 2. 성공 종료와 실패 종료를 구분

#### 수정 전

```cpp
if (count == k || index == wall.size())
{
    solving(v);
    return;
}
```

`K개를 모두 선택한 경우`와 `모든 벽을 확인한 경우`에 모두 BFS를 실행했다.

#### 수정 후

```cpp
if (count == k)
{
    solving(v);
    return;
}

if (index == wall.size())
{
    return;
}
```

#### 수정 이유

두 조건은 의미가 다르다.

* `count == k`
  → 벽을 정확히 K개 제거한 유효한 조합이므로 BFS 실행

* `index == wall.size()`이고 `count < k`
  → 모든 벽을 확인했지만 K개를 선택하지 못한 경우이므로 그대로 종료

따라서 **성공한 조합에서만 BFS를 실행하도록 종료 조건을 분리**하면 불필요한 탐색을 줄일 수 있다.

