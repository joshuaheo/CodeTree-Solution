# [[챌린지]방향에 맞춰 최대로 움직이기](https://www.codetree.ai/trails/complete/curated-cards/challenge-max-movements-with-direction)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / Backtracking / K개 중 하나를 N번 선택하기(Conditional)](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 보통 |
| 경험치 | 70 XP |

## 개선점 및 배운 점

### 1. 8방향 이동은 방향 배열로 처리
`switch`문으로 8방향을 각각 처리할 수도 있지만, 방향 배열을 사용하면 더 간단하게 만들 수 있다.

```cpp
int dx[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
```

격자 탐색에서는 상하좌우나 8방향 이동을 방향 배열로 관리하는 경우가 많다.

### 2. 행과 열의 의미 구분
현재 코드에서 `v[y][x]`로 접근하므로 `x`는 열, `y`는 행을 의미한다.

격자 문제에서는 `row`, `col`처럼 이름을 사용하면 좌표 혼동을 줄일 수 있다.


참조로 전달해 복사를 막고, `const`를 붙여 함수에서 값을 수정하지 않는다는 것을 명확하게 할 수 있다.
