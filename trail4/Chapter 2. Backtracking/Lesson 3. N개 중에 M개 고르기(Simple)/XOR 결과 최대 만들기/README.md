# [[챌린지]XOR 결과 최대 만들기](https://www.codetree.ai/trails/complete/curated-cards/challenge-max-of-xor)

| 항목 | 내용 |
|---|---|
| 분류 | Trail |
| 커리큘럼 | [Trail 4 / Backtracking / N개 중에 M개 고르기(Simple)](https://www.codetree.ai/trail-info/intermediate-low/) |
| 난이도 | 쉬움 |
| 경험치 | 40 XP |

## 개선할 만 한 점

```cpp
if (start == n)
{
    return;
}
```

`start == n`이면 아래 `for`문의 조건 `i < n`을 만족하지 않아 반복문이 실행되지 않고 함수가 자연스럽게 종료된다.

* 현재는 `m`개를 모두 고른 뒤 선택한 값들을 다시 순회해서 XOR을 계산한다.

```cpp
int temp = df[0];

for (int i = 1; i < m; i++)
{
    temp = temp ^ df[i];
}
```

XOR 값도 재귀를 진행하면서 함께 누적하면 마지막에 `df` 전체를 다시 순회하지 않아도 된다.

예를 들어 현재 XOR 값을 매개변수로 넘겨

```cpp
finding(..., currentXor ^ v[i]);
```

형태로 관리할 수 있다.

* 현재 코드는 `push_back → 재귀 → pop_back` 구조를 사용해 선택 상태를 복구하는 전형적인 백트래킹 방식이다.

