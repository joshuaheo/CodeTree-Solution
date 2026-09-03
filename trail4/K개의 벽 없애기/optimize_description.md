# 최적화 버전 요약

## 코드 수정 사항

### 1. 벽 조합 생성 + 반복 BFS 제거

#### 수정 전

벽 중 K개를 선택한 뒤, 각 조합마다 BFS를 새로 실행했다.

```cpp
void deleting(int index, int count, vector<vector<int>> &v)
{
    if (count == k)
    {
        solving(v);
        return;
    }

    v[wall[index].first][wall[index].second] = 0;
    deleting(index + 1, count + 1, v);

    v[wall[index].first][wall[index].second] = 1;
    deleting(index + 1, count, v);
}
```

#### 수정 후

벽을 미리 선택하지 않고, BFS 도중 벽을 만났을 때 `broken`을 증가시키도록 변경했다.

```cpp
queue<tuple<int, int, int>> q;
// row, col, broken

q.push({sr, sc, 0});
```

```cpp
if (v[row][col] == 1)
{
    if (broken == k)
    {
        return;
    }

    broken++;
}
```

#### 수정 이유

기존 방식은 벽의 조합이 달라질 때마다 시작점부터 BFS를 다시 실행하므로, 서로 다른 조합에서 동일한 경로를 반복 탐색하게 된다.

최적화 버전에서는 벽을 몇 개 제거했는지를 BFS의 상태로 포함하여 **하나의 BFS 안에서 벽 제거 경우의 수를 함께 탐색**하도록 변경했다.

기존 탐색량은 대략

```text
O(C(벽의 개수, K) × N²)
```

이지만 상태 BFS에서는 최대 상태 수가

```text
N × N × (K + 1)
```

이므로 대략

```text
O(N² × K)
```

범위에서 탐색할 수 있다.

---

### 2. `visit`에 벽 제거 횟수 상태 추가

#### 수정 전

각 BFS가 독립적으로 실행되므로 일반적인 2차원 방문 배열을 사용했다.

```cpp
vector<vector<int>> visit(n, vector<int>(n, 0));
```

#### 수정 후

같은 위치라도 지금까지 제거한 벽의 개수가 다르면 서로 다른 상태로 처리하도록 3차원 배열로 변경했다.

```cpp
vector<vector<vector<int>>> visit(
    n,
    vector<vector<int>>(n, vector<int>(k + 1, 0))
);
```

방문 여부는 다음과 같이 판단한다.

```cpp
visit[row][col][broken]
```

#### 수정 이유

같은 칸에 도착했더라도 다음 두 상태는 서로 의미가 다르다.

```text
6번 이동 / 벽 2개 제거
8번 이동 / 벽 1개 제거
```

첫 번째가 더 빠르게 도착했더라도 이미 벽을 많이 제거했기 때문에 이후 경로가 막힐 수 있고, 두 번째 상태만 목적지까지 갈 수도 있다.

따라서 `broken`이 다르면 서로 다른 BFS 상태로 유지하고, **동일한 `(row, col, broken)` 상태만 중복 방문하지 않도록 처리**했다.

이동 횟수의 최소값은 BFS 탐색 순서가 보장하고, 벽 제거 횟수는 `broken` 상태가 관리하도록 역할을 분리했다.

---

### 3. 벽 처리 후 실제 `broken` 상태를 기준으로 방문 확인

#### 수정 전

다음 칸이 벽인지 확인하기 전에 현재 `broken` 값으로 방문 여부를 검사했다.

```cpp
if (visit[row][col][broken] == 1)
{
    return;
}

if (v[row][col] == 1)
{
    broken++;
}
```

벽을 통과하면 실제 큐에 저장되는 값은 `broken + 1`이므로 방문 검사 상태와 실제 저장 상태가 달라질 수 있었다.

#### 수정 후

먼저 벽 여부를 확인하여 `broken`을 확정한 뒤 방문 여부를 검사했다.

```cpp
if (v[row][col] == 1)
{
    if (broken == k)
    {
        return;
    }

    broken++;
}

if (visit[row][col][broken] == 1)
{
    return;
}

q.push({row, col, broken});
visit[row][col][broken] = 1;
```

#### 수정 이유

`visit`은 실제로 큐에 들어갈

```text
(row, col, broken)
```

상태의 방문 여부를 판단해야 한다.

벽을 통과하면서 `broken`이 변경되는 경우에는 변경 이후의 값을 기준으로 검사해야 동일한 상태가 큐에 중복 삽입되는 것을 막을 수 있다.

---

## 정리

기존:

```text
벽 K개 선택
→ 해당 벽 제거
→ BFS 실행
→ 다음 벽 조합 선택
→ 다시 처음부터 BFS
```

최적화 후:

```text
BFS 한 번 실행
→ (row, col, broken) 상태로 이동
→ 빈칸이면 broken 유지
→ 벽이면 broken + 1
→ visit[row][col][broken]으로 상태별 중복 방지
```

핵심 변화는 **벽 제거 조합을 BFS 외부에서 모두 만든 뒤 반복 탐색하던 구조를, 벽 제거 횟수 자체를 BFS 상태에 포함하는 방식으로 변경한 것**이다.

이를 통해 서로 다른 벽 조합에서 반복되던 BFS 경로 탐색을 크게 줄였다.
