## 최적화 버전 코드 수정 사항

### 1. 단순 DFS → 메모이제이션 적용

**수정 전**
```cpp
finding(v, d, x, y, count + 1);
```

같은 위치에 여러 경로로 도착할 경우, 해당 위치 이후의 경로를 매번 다시 탐색했다.

**수정 후**
```cpp
if (memozi[row][col] != -1)
    return;

memozi[row][col] = 0;
```

```cpp
finding(v, d, memozi, row, col);

memozi[brow][bcol] =
    max(memozi[brow][bcol], 1 + memozi[row][col]);
```

`memozi[row][col]`에 **현재 위치에서 앞으로 이동할 수 있는 최대 횟수**를 저장한다.

이미 계산한 위치는 다시 탐색하지 않고 저장된 결과를 사용하므로 중복 탐색을 줄일 수 있다.

---

### 2. `count`, 전역 `answer` 제거

**수정 전**
```cpp
finding(v, d, x, y, count + 1);
answer = max(answer, count);
```

**수정 후**
```cpp
memozi[brow][bcol] =
    max(memozi[brow][bcol], 1 + memozi[row][col]);
```

이전에는 시작점부터 이동한 횟수 `count`를 계속 전달하며 전체 최댓값을 구했다.

수정 후에는 각 위치가 자신의 **남은 최대 이동 횟수**를 저장하므로 `count`와 전역 `answer`가 필요 없어졌다.

최종 답도 시작 위치의 메모값으로 바로 구할 수 있다.

```cpp
printf("%d", memozi[r][c]);
```

---

### 3. `switch` 방향 처리 → 방향 배열

**수정 전**
```cpp
switch (direction)
{
case 1:
    y--;
    break;
...
}
```

**수정 후**
```cpp
int drow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dcol[8] = {0, 1, 1, 1, 0, -1, -1, -1};

row += drow[direction];
col += dcol[direction];
```

8방향의 행·열 변화량을 배열에 저장해 이동 코드를 단순화했다.

또한 `x`, `y` 대신 `row`, `col`을 사용해 2차원 배열의 행과 열을 구분하기 쉽게 변경했다.

---

## 정리

기존 코드는 가능한 모든 경로를 DFS로 탐색하기 때문에 같은 위치 이후의 탐색이 반복될 수 있었다.

최적화 버전은

```text
현재 위치의 최대 이동 횟수 계산
→ memozi에 저장
→ 같은 위치를 다시 만나면 저장된 결과 사용
```

하는 **Top-down DP + 메모이제이션** 구조로 변경했다.

핵심 최적화는 방향 배열보다 `memozi`를 이용해 **같은 위치의 탐색을 한 번만 수행하도록 만든 것**이다.
