# 최적화 버전 정리

## 1. 후보마다 BFS를 실행하던 구조를 BFS 1회로 변경

### 수정 전

기존에는 값이 큰 후보부터 찾은 뒤, 해당 후보까지 도달 가능한지를 `checking()`에서 BFS로 확인했다.

```cpp
for (int i = v[row][col] - 1; i > 0; i--)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            if (v[j][k] == i)
            {
                ...
                flag = checking(v, row, col, j, k, visit);
            }
        }
    }
}
```

흐름은 다음과 같았다.

```text
좋은 후보 탐색
→ 후보까지 BFS
→ 실패하면 다음 후보 탐색
→ 다시 BFS
```

### 수정 후

현재 위치에서 BFS를 한 번 실행해 도달 가능한 모든 칸을 탐색하면서 동시에 가장 좋은 후보를 찾도록 변경했다.

```cpp
while (!q.empty())
{
    for (int j = 0; j < 4; j++)
    {
        nextr = q.front().first + dr[j];
        nextc = q.front().second + dc[j];

        ...

        pushing(v, nextr, nextc, visit, q,
                i + 1, best, bestr, bestc);
    }

    q.pop();
}
```

### 수정 이유

기존 방식은 높은 우선순위의 후보가 도달 불가능할 경우 같은 영역을 여러 번 BFS로 탐색할 수 있었다.

```text
후보 A → BFS 실패
후보 B → BFS 실패
후보 C → BFS 성공
```

수정 후에는 한 번의 이동에서 BFS를 한 번만 실행하고, 각 칸을 최대 한 번씩 방문한다.

```text
BFS 1회
→ 도달 가능한 모든 칸 확인
→ 최적 후보 결정
```

---

## 2. `masking()`을 제거하고 BFS에서 이동 조건 직접 검사

### 수정 전

현재 위치의 값 이상인 칸을 `masking()`으로 미리 막았다.

```cpp
if (v[i][j] >= v[r][c])
{
    visit[i][j] = 1;
}
```

이후 BFS에서는 `visit`을 보고 이동 가능 여부를 판단했다.

### 수정 후

BFS에서 다음 위치의 값을 현재 시작점의 값과 바로 비교한다.

```cpp
if (v[nextr][nextc] >= v[row][col])
{
    continue;
}
```

### 수정 이유

이동 가능 여부를 판단하기 위해 격자 전체를 미리 순회할 필요가 없었다.

기존:

```text
전체 격자 masking
→ 이동 불가능 칸 표시
→ BFS
```

수정 후:

```text
BFS
→ 이동하려는 칸의 값 즉시 검사
```

불필요한 전체 탐색과 `masking()` 함수가 제거됐다.

---

## 3. 후보 주변 사전검사와 `checking()` 제거

### 수정 전

후보를 발견하면 먼저 주변에 진입 가능한 칸이 있는지 검사했다.

```cpp
for (int t = 0; t < 4; t++)
{
    if (...)
    {
        if (v[dr[t] + j][dc[t] + k] < v[row][col] ||
            (dr[t] + j == row && dc[t] + k == col))
        {
            flag = true;
            break;
        }
    }
}
```

그 후 다시 `checking()`을 호출해 실제 도달 가능 여부를 BFS로 확인했다.

```cpp
flag = checking(v, row, col, j, k, visit);
```

### 수정 후

현재 위치에서 BFS를 직접 실행하기 때문에 BFS에서 실제로 방문한 칸만 후보로 사용한다.

따라서 별도의 후보 주변 검사와 `checking()` 함수가 필요하지 않게 됐다.

### 수정 이유

기존에는

```text
후보가 갈 수 있을 것 같은지 사전검사
→ 실제로 갈 수 있는지 BFS로 다시 검사
```

하는 이중 판정 구조였다.

수정 후에는

```text
BFS에서 방문됨
= 실제 도달 가능한 칸
```

이 되므로 별도의 사전검사가 필요 없다.

---

## 4. 값 내림차순 전체 탐색을 BFS 중 `best` 갱신으로 변경

### 수정 전

현재 값보다 작은 값을 큰 값부터 하나씩 찾고, 매번 전체 격자를 순회했다.

```cpp
for (int i = v[row][col] - 1; i > 0; i--)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            if (v[j][k] == i)
            {
                ...
            }
        }
    }
}
```

### 수정 후

BFS로 새로운 칸을 발견할 때마다 현재 `best`와 비교한다.

```cpp
if (best < v[tempr][tempc])
{
    best = v[tempr][tempc];
    bestr = tempr;
    bestc = tempc;
}
```

값이 같다면 문제의 우선순위에 따라 행과 열을 비교한다.

```cpp
else if (best == v[tempr][tempc])
{
    if (bestr == tempr)
    {
        if (tempc < bestc)
        {
            bestc = tempc;
        }
    }
    else if (tempr < bestr)
    {
        bestr = tempr;
        bestc = tempc;
    }
}
```

### 수정 이유

도달 가능한 칸을 BFS에서 이미 확인하고 있으므로 후보를 찾기 위해 다시 전체 격자를 순회할 필요가 없다.

```text
값이 큰 칸
→ 행이 작은 칸
→ 열이 작은 칸
```

순으로 BFS 도중 바로 최적 후보를 갱신하도록 변경했다.

---

## 5. BFS마다 방문 배열을 초기화하지 않고 탐색 번호 사용

### 수정 전

`checking()`을 호출할 때마다 새로운 방문 배열을 생성했다.

```cpp
vector<vector<int>> s(n, vector<int>(n, 0));
```

### 수정 후

하나의 `visit` 배열을 유지하고 현재 BFS의 회차 번호를 저장한다.

```cpp
pushing(v, nextr, nextc, visit, q,
        i + 1, best, bestr, bestc);
```

`pushing()`에서는 현재 BFS에서 이미 방문한 칸인지 확인한다.

```cpp
if (visit[tempr][tempc] == i)
{
    return;
}

...

visit[tempr][tempc] = i;
```

예를 들어:

```text
visit = 1 → 첫 번째 BFS에서 방문
visit = 2 → 두 번째 BFS에서 방문
visit = 3 → 세 번째 BFS에서 방문
```

### 수정 이유

BFS를 새로 시작할 때마다 방문 배열 전체를 `0`으로 초기화하지 않고도 각 탐색의 방문 여부를 구분할 수 있다.

반복적으로 BFS를 수행할 때 사용할 수 있는 방문 처리 방식이다.

---

## 6. 재귀 구조를 반복문으로 변경

### 수정 전

이동에 성공할 때마다 남은 횟수를 감소시키고 `finding()`을 다시 호출했다.

```cpp
f--;

finding(row, col, v, visit);
return;
```

### 수정 후

최대 이동 횟수만큼 반복문을 실행한다.

```cpp
for (int i = 0; i < f; i++)
{
    ...
}
```

이번 BFS에서 이동 가능한 칸을 찾지 못하면 즉시 종료한다.

```cpp
if (best == 0)
{
    break;
}
```

### 수정 이유

이 문제는 동일한 이동 과정을 최대 `K`번 반복하는 구조이므로 재귀 호출 없이 반복문으로 직접 표현할 수 있다.

기존:

```text
이동
→ 재귀 호출
→ 이동
→ 재귀 호출
```

수정 후:

```text
K번 반복
→ BFS
→ 위치 갱신
```

재귀 호출과 전역 `f` 감소 처리가 사라져 전체 흐름이 단순해졌다.

---

## 7. `pushing()`에서 최적 후보의 값과 위치를 함께 갱신

### 수정 후

`pushing()`은 새로운 칸을 큐에 넣으면서 해당 위치가 현재 최적 후보인지 함께 확인한다.

```cpp
q.push({tempr, tempc});

if (best < v[tempr][tempc])
{
    best = v[tempr][tempc];
    bestr = tempr;
    bestc = tempc;
}
```

`best`, `bestr`, `bestc`는 호출한 함수의 값을 직접 수정해야 하므로 참조로 전달한다.

```cpp
int &best, int &bestr, int &bestc
```

### 수정 이유

BFS가 끝난 뒤 다시 격자 전체를 탐색하지 않고, BFS 중 방문한 칸만 이용해 최적 위치까지 동시에 결정하기 위해서다.

---

# 정리

기존 구조는 다음과 같았다.

```text
masking으로 이동 불가능 칸 표시
→ 좋은 후보부터 전체 격자 탐색
→ 후보 주변 사전검사
→ 후보까지 BFS
→ 실패하면 다음 후보에 대해 다시 BFS
→ 성공하면 재귀 호출
```

최적화 후 구조는 다음과 같다.

```text
현재 위치에서 BFS 1회
→ 이동 가능한 칸만 큐에 삽입
→ 방문하면서 best 값과 위치 갱신
→ BFS 종료
→ best 위치로 이동
→ 최대 K번 반복
```

핵심 변화는 **후보를 먼저 찾고 BFS로 검증하는 방식에서, BFS로 도달 가능한 영역을 한 번 탐색하면서 최적 후보까지 동시에 찾는 방식으로 변경한 것**이다.

이를 통해 `masking()`, 후보 주변 사전검사, `checking()`, 값별 전체 격자 탐색, 재귀 호출이 제거됐으며, 한 번의 이동에서 후보마다 BFS를 반복하던 구조도 BFS 1회로 단순화됐다.
