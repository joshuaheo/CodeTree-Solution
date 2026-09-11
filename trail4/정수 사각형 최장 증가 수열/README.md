# [[챌린지]정수 사각형 최장 증가 수열](https://www.codetree.ai/trails/complete/curated-cards/challenge-lis-on-the-integer-grid)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / DP I / 격자 안에서 한 칸씩 전진하는 DP](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 보통 |
| 경험치 | 90 XP |

## 개선점 및 배운 점

* `dp[row][col]`은 **현재 칸에서 시작해서 값이 증가하는 방향으로 이동했을 때 방문할 수 있는 최대 칸 수**를 의미한다.

```cpp
dp[row][col] = 1 + max(이동 가능한 이웃의 dp)
```

* `dp`를 `-1`로 초기화하면 아직 계산하지 않은 칸인지 확인할 수 있다.

```cpp
if (dp[nr][nc] == -1)
{
    finding(v, dp, nr, nc);
}
```

한 번 계산한 칸은 저장된 `dp` 값을 다시 사용하므로 동일한 경로를 반복해서 탐색하지 않는다. 이러한 방식을 **메모이제이션(Memoization)**이라고 한다.

* 값이 더 큰 칸으로만 이동할 수 있으므로 이동할수록 값이 계속 증가한다.

```cpp
if (v[nr][nc] > v[row][col])
```

따라서 이전 칸으로 돌아오는 사이클이 발생할 수 없으며, 별도의 `visit` 배열 없이 `dp`만으로 계산 여부를 관리할 수 있다.

* 이동 가능한 칸이 없는 경우 다음과 같이 바로 반환했는데,

```cpp
if (!flag)
{
    dp[row][col] = 1;
    return;
}
```

이 경우 `result`를 갱신하지 않고 종료한다. 모든 칸에서 이동할 수 없는 경우 `result`가 초기값인 `0`으로 남을 수 있으므로 반환 전에 결과값도 갱신해야 한다.

```cpp
if (!flag)
{
    dp[row][col] = 1;
    result = max(result, dp[row][col]);
    return;
}
```

* `max()`를 사용할 때는 해당 함수가 정의된 `<algorithm>` 헤더를 직접 포함하는 것이 안전하다.

```cpp
#include <algorithm>
```

반대로 기존 코드의 `<queue>`는 사용하지 않으므로 제거할 수 있다.

