# [[개념]정수 사각형 최대 합](https://www.codetree.ai/trails/complete/curated-cards/intro-maximum-sum-path-in-square)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / DP I / 격자 안에서 한 칸씩 전진하는 DP](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 쉬움 |
| 경험치 | 40 XP |

## 코드 추천 수정 사항

### 1. `temp` 없이 DP 배열을 직접 이용하기

기존에는 첫 행과 첫 열의 누적합을 구할 때 `temp` 변수를 사용했다.

```cpp
temp += v[i][0];
dp[i][0] = temp;
```

DP 배열 자체에 이전까지의 결과가 저장되어 있으므로 다음처럼 바로 계산할 수 있다.

```cpp
dp[i][0] = dp[i - 1][0] + v[i][0];
dp[0][i] = dp[0][i - 1] + v[0][i];
```

별도의 누적 변수가 필요 없어지고, `dp`의 의미도 더 명확해진다.

### 2. `<algorithm>` 헤더 추가

`max()` 함수를 사용하고 있으므로 다음 헤더를 직접 포함하는 것이 안전하다.

```cpp
#include <algorithm>
```

